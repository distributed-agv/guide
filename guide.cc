#include "guide.h"
#include "hiredis/hiredis.h"

Guide::StepCode Guide::GetNextStep(const CarState &) {
  return Guide::StepCode::STOP;
}
