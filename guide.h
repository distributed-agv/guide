#ifndef GUIDE_H
#define GUIDE_H

struct Position {
    int row_idx;
    int col_idx;
};

struct CarState {
    int car_id;
    int nonce;
    Position cur_pos;
    Position last_pos;
    Position dst_pos;
};

enum StepCode {
    STOP,
    LEFT,
    RIGHT,
    FORWARD,
    BACKWARD,
    RESET,
};

StepCode GetNextStep(const CarState &);

#endif
