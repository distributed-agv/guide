#ifndef GUIDE_H
#define GUIDE_H

#include <string>

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
  enum StepCode {
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
};

#endif
