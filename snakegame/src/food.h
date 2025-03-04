#pragma once
#include <deque>
#include <raylib.h>

class Food {
public:
  Vector2 position;
  Texture2D texture;

  Food();
  ~Food();

  void Draw();
  Vector2 GenerateRandomPosition(std::deque<Vector2> snakeBody = {});
};