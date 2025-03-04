#include "game.h"
#include "constants.h"
#include <fstream>
#include <raylib.h>
#include <raymath.h>

Game::Game() {
  InitAudioDevice();
  eatSound = LoadSound("assets/sounds/eat.mp3");
  crashSound = LoadSound("assets/sounds/crash.mp3");
  LoadHighScore();
}

Game::~Game() {
  UnloadSound(eatSound);
  UnloadSound(crashSound);
  CloseAudioDevice();
}

void Game::Update() {
  snake.Update();
  CheckCollisions();
}

void Game::Draw() {
  ClearBackground(green);
  food.Draw();
  snake.Draw();

  DrawRectangleLinesEx({offset - 5, offset - 5,
                        (float)cellSize * cellCount + 10,
                        (float)cellSize * cellCount + 10},
                       5, darkGreen);
  DrawText("Sif's Valley", offset - 5, 20, 35, darkGreen);
  DrawText(TextFormat("Score: %i", score), offset - 5,
           offset + cellSize * cellCount + 10, 30, darkGreen);
  DrawText(TextFormat("High Score: %i", highScore),
           offset + cellSize * cellCount - 200,
           offset + cellSize * cellCount + 10, 30, darkGreen);
  DrawText(TextFormat("FPS: %i", GetFPS()), offset + cellSize * cellCount - 200, 10, 20, darkGreen);
}

void Game::HandleInput() {
  if (IsKeyPressed(KEY_UP) && snake.direction.y == 0)
    snake.direction = {0, -1};
  else if (IsKeyPressed(KEY_DOWN) && snake.direction.y == 0)
    snake.direction = {0, 1};
  else if (IsKeyPressed(KEY_LEFT) && snake.direction.x == 0)
    snake.direction = {-1, 0};
  else if (IsKeyPressed(KEY_RIGHT) && snake.direction.x == 0)
    snake.direction = {1, 0};
}

void Game::CheckCollisions() {
  CheckFoodCollision();
  CheckEdgeCollision();
  CheckSelfCollision();
}

void Game::CheckFoodCollision() {
  if (Vector2Equals(snake.body[0], food.position)) {
    snake.body.push_back(snake.body.back());
    food.position = food.GenerateRandomPosition(snake.body);
    PlaySound(eatSound);
    if (++score > highScore) {
      highScore = score;
      SaveHighScore();
    }
  }
}

void Game::CheckEdgeCollision() {
  Vector2 head = snake.body[0];
  if (head.x < 0 || head.x >= cellCount || head.y < 0 || head.y >= cellCount)
    GameOver();
}

void Game::CheckSelfCollision() {
  for (size_t i = 1; i < snake.body.size(); i++)
    if (Vector2Equals(snake.body[0], snake.body[i]))
      GameOver();
}

void Game::GameOver() {
  PlaySound(crashSound);
  snake = Snake();
  score = 0;
}

void Game::LoadHighScore() {
  std::ifstream file("highscore.txt");
  if (file)
    file >> highScore;
}

void Game::SaveHighScore() {
  std::ofstream file("highscore.txt");
  if (file)
    file << highScore;
}