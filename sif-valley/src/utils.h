#pragma once
#include <deque>
#include <raylib.h>

bool eventTriggered(double interval);
bool elementInDeque(Vector2 element, std::deque<Vector2> deque);