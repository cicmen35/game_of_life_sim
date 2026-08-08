#include "iostream"
#include "simulation.h"
#include <raylib.h>

int main() {
  Color Grey = {29, 29, 29, 255};
  const int WINDOW_WIDHT = 750;
  const int WINDOW_HEIGHT = 750;
  const int CELL_SIZE = 25;
  int FPS = 12;

  InitWindow(WINDOW_WIDHT, WINDOW_HEIGHT, "Game of Life");
  SetTargetFPS(FPS);
  Simulation simulation{WINDOW_WIDHT, WINDOW_HEIGHT, CELL_SIZE};

  std::cout << simulation.CountLiveNeighbours(3, 4) << std::endl;

  // Simulation loop
  while (WindowShouldClose() == false) {

    // 1. Event handling

    if (IsKeyPressed(KEY_ENTER)) {
      simulation.Start();
      SetWindowTitle("Game of Life is running...");
    } else if (IsKeyPressed(KEY_SPACE)) {
      simulation.Stop();
      SetWindowTitle("Game of Life has stopped.");
    } else if (IsKeyPressed(KEY_F)) {
      FPS += 2;
      SetTargetFPS(FPS);
    } else if (IsKeyPressed(KEY_S)) {
      if (FPS > 5) {
        FPS -= 2;
        SetTargetFPS(FPS);
      }
    } else if (IsKeyPressed(KEY_R)) {
      simulation.CreateRandomState();
    } else if (IsKeyPressed(KEY_C)) {
      simulation.ClearGrid();
    }

    // 2. Updating state
    simulation.Update();

    // 3. Draw
    BeginDrawing();
    ClearBackground(Grey);
    simulation.Draw();
    EndDrawing();
  }

  CloseWindow();
}