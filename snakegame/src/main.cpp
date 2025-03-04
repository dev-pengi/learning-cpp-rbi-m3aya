#include <cmath>
#include <iostream>

#include "constants.h"
#include "game.h"
#include "utils.h"
#include <raylib.h>

int main() {
  std::cout << "Starting game..." << std::endl;

  InitWindow(2 * offset + cellSize * cellCount,
             2 * offset + cellSize * cellCount, "Sif's Valley");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    BeginDrawing();
    game.HandleInput();

    float gameSpeed =
        (100.0f - (10.0f / 2.0f) * log2(game.score + 1)) / 1000.0f;
    std::cout << "Game speed: " << gameSpeed << std::endl;

    if (eventTriggered(gameSpeed)) {
      game.Update();
    }
    game.Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}