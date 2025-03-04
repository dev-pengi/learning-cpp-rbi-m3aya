#include "utils.h"
#include <raylib.h>
#include <raymath.h>

static double lastUpdateTime = 0;

bool eventTriggered(double interval) {
  double currentTime = GetTime();
  double elapsedTime = currentTime - lastUpdateTime;
  if (elapsedTime >= interval)
    lastUpdateTime = currentTime;
  return elapsedTime >= interval;
}

bool elementInDeque(Vector2 element, std::deque<Vector2> deque) {
  for (auto &vec : deque)
    if (Vector2Equals(element, vec))
      return true;
  return false;
}