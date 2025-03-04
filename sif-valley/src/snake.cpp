#include "snake.h"
#include "constants.h"
#include <raymath.h>

Snake::Snake() : body{{6,9}, {5,9}, {4,9}}, direction{1,0}, nextDirection{0,0} {}

void Snake::Draw() {
    for (size_t i = 0; i < body.size(); i++) {
        float x = offset + body[i].x * cellSize;
        float y = offset + body[i].y * cellSize;
        DrawRectangleRounded({x, y, (float)cellSize, (float)cellSize}, 
                            i == 0 ? 0.7 : 0.5, 6, darkGreen);
    }
}

void Snake::Update() {
    if (nextDirection.x != 0 || nextDirection.y != 0) {
        direction = nextDirection;
        nextDirection = {0, 0};
    }
    body.pop_back();
    body.push_front(Vector2Add(body[0], direction));
}