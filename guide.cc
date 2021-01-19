#include "guide.h"
#include "hiredis/hiredis.h"

StepCode GetNextStep(const CarState &car_state) {
    return StepCode::STOP;
}
