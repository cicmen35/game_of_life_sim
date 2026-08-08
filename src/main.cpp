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
  simulation.SetCellValue(3, 4, 1);
  simulation.SetCellValue(3, 5, 1);
  simulation.SetCellValue(4, 5, 1);
  simulation.SetCellValue(2, 5, 1);

  std::cout << simulation.CountLiveNeighbours(3, 4) << std::endl;

  // Simulation loop
  while (WindowShouldClose() == false) {
    // 1. Event handling

    // 2. Updating state

    // 3. Draw
    BeginDrawing();
    ClearBackground(Grey);
    simulation.Draw();
    EndDrawing();
  }

  CloseWindow();
}