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
    int neighbourRow = row + offset.first;
    int neighbourColumn = column + offset.second;
    liveNeighbours += grid.GetValue(neighbourRow, neighbourColumn);
  };
  return liveNeighbours;
};