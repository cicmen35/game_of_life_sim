#include "simulation.h"
#include <utility>
#include <vector>

void Simulation::Draw() { grid.Draw(); }

void Simulation::SetCellValue(int row, int column, int value) {
  grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbours(int row, int column) {
  int liveNeighbours = 0;
  std::vector<std::pair<int, int>> neighbourOffsets = {
      {-1, 0},  // hore
      {1, 0},   // dole
      {0, -1},  // vlavo
      {0, 1},   // vpravo
      {-1, -1}, // vlavo hore
      {-1, 1},  // vpravo hore
      {1, -1},  // vlavo dole
      {1, 1}    // vpravo dole
  };

  for (const auto &offset : neighbourOffsets) {
    int neighbourRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
    int neighbourColumn =
        (column + offset.second + grid.GetColumns()) % grid.GetColumns();
    liveNeighbours += grid.GetValue(neighbourRow, neighbourColumn);
  };
  return liveNeighbours;
};

void Simulation::Update() {
  for (int row = 0; row < grid.GetRows(); row++) {
    for (int column = 0; column < grid.GetColumns(); column++) {
      int liveNeighbours = CountLiveNeighbours(row, column);
      int cellValue = grid.GetValue(row, column);

      if (cellValue == 1) {
        if (liveNeighbours > 3 || liveNeighbours < 2) {
          tempGrid.SetValue(row, column, 0);
        } else {
          tempGrid.SetValue(row, column, 1);
        }
      } else {
        if (liveNeighbours == 3) {
          tempGrid.SetValue(row, column, 1);
        } else {
          tempGrid.SetValue(row, column, 0);
        }
      }
    }
  }
  grid = tempGrid;
}