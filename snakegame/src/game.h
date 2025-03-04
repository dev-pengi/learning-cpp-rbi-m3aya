#pragma once

#include "food.h"
#include "snake.h"
#include <raylib.h>

class Game {
public:
  Snake snake;
  Food food;
  int score = 0;
  int highScore = 0;
  Sound eatSound;
  Sound crashSound;

  Game();
  ~Game();
  void Update();
  void Draw();
  void HandleInput();

private:
  void CheckCollisions();
  void CheckFoodCollision();
  void CheckEdgeCollision();
  void CheckSelfCollision();
  void GameOver();
  void LoadHighScore();
  void SaveHighScore();
};