#ifndef GUIDE_H
#define GUIDE_H

#include <string>
#include "hiredis/hiredis.h"

using namespace std;

struct Guide {
  struct Position {
    int row_idx;
    int col_idx;
  };
  struct CarState {
    int car_id;
    int seq;
    Position cur_pos;
    Position last_pos;
    Position dst_pos;
  };
  enum StepCode:int {
    STOP = 0,
    LEFT,
    RIGHT,
    FORWARD,
    BACKWARD,
    RESET,
    ERROR,
  };
  int car_num;
  int row_num;
  int col_num;
  int redis_port;
  std::string redis_host;
  std::string get_lock_sha;
  std::string commit_sha;
  std::string recover_sha;
  StepCode GetNextStep(const CarState &);
  int releaseLock(string *release_lock,int next_step,int seq,int car_id,redisContext *redis_context);
  string* findReleaseLock(int x,int y,int nextX,int nextY,int car);
  StepCode changeNextToDirect(int nowX, int nowY, int nextX,int nextY);
  void findNextStep(int x,int y,int &nextX,int &nextY,int car,int goalX,int goalY);
  int getLock(int x,int y,int car_id,int seq,redisContext *redis_context);
  int ResetTimer(redisContext *redis_context, bool &success_out);
};

#endif
