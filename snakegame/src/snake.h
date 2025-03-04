#pragma once
#include <deque>
#include <raylib.h>

class Snake {
public:
  std::deque<Vector2> body;
  Vector2 direction;
  Vector2 nextDirection;

  Snake();
  void Draw();
  void Update();
};