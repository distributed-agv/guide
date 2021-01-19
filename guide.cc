#include "guide.h"
#include "hiredis/hiredis.h"

Guide::Guide(int, int, int, const std::string &, const std::string &, const std::string &, const std::string &) {}

Guide::StepCode Guide::GetNextStep(const CarState &) {
  return Guide::StepCode::STOP;
}
