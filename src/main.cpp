#include "grid.h"
#include <raylib.h>

int main() {
  Color Grey = {29, 29, 29, 255};
  const int WINDOW_WIDHT = 750;
  const int WINDOW_HEIGHT = 750;
  const int CELL_SIZE = 25;
  int FPS = 12;

  InitWindow(WINDOW_WIDHT, WINDOW_HEIGHT, "Game of Life");
  SetTargetFPS(FPS);
  Grid grid(WINDOW_WIDHT, WINDOW_HEIGHT, CELL_SIZE);
  grid.SetValue(0, 0, 1);
  grid.SetValue(2, 1, 1);
  grid.SetValue(0, 0, 80);

  // Simulation loop
  while (WindowShouldClose() == false) {
    // 1. Event handling

    // 2. Updating state

    // 3. Draw
    BeginDrawing();
    ClearBackground(Grey);
    grid.Draw();
    EndDrawing();
  }

  CloseWindow();
}