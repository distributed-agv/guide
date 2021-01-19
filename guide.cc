#include "guide.h"
#include "hiredis/hiredis.h"
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include "Astar.h"
#include <iostream>
using namespace std;
int **map_guide;

int Guide::releaseLock(string *release_lock,int next_step,int seq,int car_id,redisContext *redis_context){
  redisReply *redis_reply = (redisReply *) redisCommand(
    redis_context,
    "EVALSHA %s 0 %d %d %s %s %s %s %d",
    commit_sha.c_str(),
    car_id,
    seq,
    release_lock[0].c_str(),
    release_lock[1].c_str(),
    release_lock[2].c_str(),
    release_lock[3].c_str(),
    next_step
  );
  if (redis_reply==NULL||redis_reply->type == REDIS_REPLY_ERROR)
    return 6;
  int result;
  sscanf(redis_reply->str, "%d", &result);
  freeReplyObject(redis_reply);
  return result;
}
string* Guide::findReleaseLock(int x,int y,int nextX,int nextY,int car){
  string *release_lock=new string[4];
  int num =0;
  if(x+1<row_num && map_guide[x+1][y]==car && !(x+1==nextX && y==nextY)){
    string name="("+to_string(x+1)+","+to_string(y)+")";
    release_lock[num]=name;
    num++;
  }
  if(y+1<col_num && map_guide[x][y+1]==car && !(x==nextX && y+1==nextY)){
    string name="("+to_string(x)+","+to_string(y+1)+")";
    release_lock[num]=name;
    num++;
  }
  if(x-1>=0 && map_guide[x-1][y]==car && !(x-1==nextX && y==nextY)){
    string name="("+to_string(x-1)+","+to_string(y)+")";
    release_lock[num]=name;
    num++;
  }
  if(y-1>=0 && map_guide[x][y-1]==car && !(x==nextX && y-1==nextY)){
    string name="("+to_string(x)+","+to_string(y-1)+")";
    release_lock[num]=name;
    num++;
  }
  return release_lock;
}

Guide::StepCode Guide::changeNextToDirect(int nowX, int nowY, int nextX,int nextY){
  if(nextX==-1&&nextY==-1)
     return (Guide::StepCode)0;
  if(nowX==nextX-1)
     return (Guide::StepCode)3;
  if(nowX==nextX+1)
     return (Guide::StepCode)4;
  if(nowY==nextY-1)
     return (Guide::StepCode)2;
  if(nowY==nextY+1)
     return (Guide::StepCode)1;
  return (Guide::StepCode)0;
}
void Guide::findNextStep(int x,int y,int &nextX,int &nextY,int car,int goalX,int goalY){
  Astar astar(row_num-1,col_num-1,car);
  Node *startPos = new Node(x,y);
  Node *endPos = new Node(goalX,goalY);
  int *tmpX=new int;
  int *tmpY=new int;
  if(astar.search(startPos,endPos,map_guide,tmpX,tmpY)){
    nextY=*tmpY;
    nextX=*tmpX;
  }
  else{
    nextX=-1;
    nextY=-1;
  }
  return ;
}

int Guide::getLock(int x,int y,int car_id,int seq,redisContext *redis_context){
  string *name=new string[5];
  if(x+1 < row_num){
    name[0]="("+to_string(x+1)+","+to_string(y)+")";
  }
  else{
    name[0]="";
  }
  if(y+1 < col_num){
    name[1]="("+to_string(x)+","+to_string(y+1)+")";
  }
  else{
    name[1]="";
  }
  if(x-1>=0){
    name[2]="("+to_string(x-1)+","+to_string(y)+")";
  }
  else{
    name[2]="";
  }
  if(y-1>=0){
    name[3]="("+to_string(x)+","+to_string(y-1)+")";
  }
  else{
    name[3]="";
  }
  name[4]="("+to_string(x)+","+to_string(y)+")";
  
  redisReply *redis_reply = (redisReply *) redisCommand(
      redis_context,
      "EVALSHA %s 0 %d %d %s %s %s %s %s",
      get_lock_sha.c_str(),
      car_id,
      seq,
      name[0].c_str(),
      name[1].c_str(),
      name[2].c_str(),
      name[3].c_str(),
      name[4].c_str()
  );
  if (redis_reply == NULL ){
    return 6;
  }
  

  if(redis_reply->type == REDIS_REPLY_STRING){
    int result;
    sscanf(redis_reply->str, "%d", &result);
    freeReplyObject(redis_reply);
    return result;
  }
  else if(redis_reply->type == REDIS_REPLY_ARRAY){
    map_guide=new int*[row_num];
    for(int i=0;i<row_num;i++){
      map_guide[i]=new int [col_num];
      for(int j=0;j<col_num;j++){
        map_guide[i][j]=-1;
      }    
    }
    for (int i = 0; i < redis_reply->elements; i += 2) {
      int car = 0;
      int tmpX;
      int tmpY;
      sscanf(redis_reply->element[i]->str, "(%d,%d)", &tmpX, &tmpY);
      sscanf(redis_reply->element[i + 1]->str, "%d", &car);
      
      if(car==-1)
        map_guide[tmpX][tmpY]=car_id+1;
      else 
        map_guide[tmpX][tmpY]=car;
    }
    return 1;
  }
  return 6;
}
Guide::StepCode Guide::GetNextStep(const CarState &car_state) {
  int car_id = car_state.car_id;
  int seq = car_state.seq;
  Position cur_pos= car_state.cur_pos;
  Position last_pos= car_state.last_pos;
  Position dst_pos= car_state.dst_pos;
 
 
  redisContext *redis_context = redisConnect(redis_host.c_str(), redis_port);
  if (NULL == redis_context || redis_context->err){

      Guide::StepCode step_code = ERROR;
      redisFree(redis_context);
      return step_code;
  }
  if(seq < 0){
    //判断是否存在lua脚本
    redisReply *lua_exit=(redisReply *)redisCommand(redis_context,"SCRIPT %s %s" ,"EXISTS",recover_sha.c_str());
    if (NULL == lua_exit){
      Guide::StepCode step_code = ERROR;
      redisFree(redis_context);
      return step_code;
    }
    if(lua_exit->element[0]->integer==0){
      pid_t pid = fork();
      if (pid == 0){
        execlp("python3", "python3", "recover_lua.py");
      }
      Guide::StepCode step_code = ERROR;
      redisFree(redis_context);
      return step_code;
    }
    freeReplyObject(lua_exit);
    
    // 进入恢复
    redisReply *redis_recover = (redisReply *) redisCommand(
      redis_context,
      "EVALSHA %s 0 %d %d (%d,%d) %d",
      recover_sha.c_str(),
      car_id,
      seq,
      cur_pos.row_idx,
      cur_pos.col_idx,
      car_num
    );
    if(redis_recover == NULL || redis_recover->type != REDIS_REPLY_STRING){
      Guide::StepCode step_code = ERROR;
      redisFree(redis_context);
      return step_code;
    }
    int next_step;
    sscanf(redis_recover->str, "%d", &next_step);
    freeReplyObject(redis_recover);
    bool reset_timer_success = false;
    if (next_step < 0 && ResetTimer(redis_context, reset_timer_success) == 0 && reset_timer_success) {
      pid_t pid = fork();
      if (pid == 0)
        execlp("python3", "python3", "car-locator/locator_recover.py", "-d", "-n", std::to_string(seq).c_str(), NULL);
    }
    redisFree(redis_context);
    return (Guide::StepCode)next_step;
  }

  int getlock_result=getLock(cur_pos.row_idx,cur_pos.col_idx,car_id,seq,redis_context);
  if(getlock_result != 1){
    redisFree(redis_context);
    
    return (Guide::StepCode)getlock_result;
  }
  
  //寻路阶段
  int nextX,nextY;
  findNextStep(cur_pos.row_idx,cur_pos.col_idx,nextX,nextY,car_id,dst_pos.row_idx,dst_pos.col_idx);
  Guide::StepCode step_code=changeNextToDirect(cur_pos.row_idx,cur_pos.col_idx,nextX,nextY);
   
  //放锁
  string* release_lock=findReleaseLock(cur_pos.row_idx,cur_pos.col_idx,nextX,nextY,car_id);
  step_code=(Guide::StepCode)releaseLock(release_lock,(int)step_code,seq,car_id,redis_context);
  if(step_code==6){
    redisFree(redis_context);
    return (Guide::StepCode)step_code;
  }
  redisFree(redis_context);
  return step_code;
}


int Guide::ResetTimer(redisContext *redis_context, bool &success_out) {
  int result = 0;
  redisReply *redis_reply = (redisReply *) redisCommand(redis_context, "SET timer TIMER PX 60000 NX");
  if (redis_reply == NULL || (redis_reply->type != REDIS_REPLY_NIL && redis_reply->type != REDIS_REPLY_STATUS)) {
    result = 1;
    goto leave;
  }
  success_out = redis_reply->type != REDIS_REPLY_NIL;
leave:
  freeReplyObject(redis_reply);
  return result;
}