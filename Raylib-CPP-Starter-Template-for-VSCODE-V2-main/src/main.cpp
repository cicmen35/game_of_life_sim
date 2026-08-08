#include <raylib.h>

int main() {
  Color Grey = {29, 29, 29, 255};
  const int WINDOW_WIDHT = 750;
  const int WINDOW_HEIGHT = 750;
  int FPS = 12;

  InitWindow(WINDOW_WIDHT, WINDOW_HEIGHT, "Game of Life");
  SetTargetFPS(FPS);

  // Simulation loop
  while (WindowShouldClose() == false) {
    // 1. Event handling

    // 2. Updating state

    // 3. Draw
    BeginDrawing();
    ClearBackground(Grey);
    EndDrawing();
  }

  CloseWindow();
}