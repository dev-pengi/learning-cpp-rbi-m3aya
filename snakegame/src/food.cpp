#include "food.h"
#include "constants.h"
#include "utils.h"
#include <raylib.h>

Food::Food() {
  Image image = LoadImage("assets/graphics/food.png");
  ImageResize(&image, cellSize, cellSize);
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
  position = GenerateRandomPosition();
}

Food::~Food() { UnloadTexture(texture); }

void Food::Draw() {
  DrawTexture(texture, offset + position.x * cellSize,
              offset + position.y * cellSize, WHITE);
}

Vector2 Food::GenerateRandomPosition(std::deque<Vector2> snakeBody) {
  Vector2 pos;
  do {
    pos = {(float)GetRandomValue(0, cellCount - 1),
           (float)GetRandomValue(0, cellCount - 1)};
  } while (elementInDeque(pos, snakeBody));
  return pos;
}