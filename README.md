# Game of Life Simulation

A C++ implementation of Conway's Game of Life built using the [Raylib](https://www.raylib.com/) library. 

This project simulates a cellular automaton on a 2D grid where cells live, die, or multiply based on a set of mathematical rules. The grid is toroidal, meaning it wraps around the edges—cells on the far right interact with those on the far left, and cells on the bottom interact with those on the top.

## Features

- **Standard Rules**: Implements Conway's original survival, underpopulation, overpopulation, and reproduction rules.
- **Continuous Grid**: Edges wrap around, treating the board as a continuous torus.
- **Interactive Controls**: Play, pause, adjust speed, and modify the grid in real-time.

## Controls

When running the application, you can use the following keyboard controls to interact with the simulation:

- **`ENTER`**: Start the simulation.
- **`SPACE`**: Pause the simulation.
- **`F`**: Increase simulation speed (FPS).
- **`S`**: Decrease simulation speed (FPS).
- **`R`**: Generate a random grid layout (only when paused).
- **`C`**: Clear the grid entirely (only when paused).

## Building and Running

This project uses `make` to compile the C++ source code. Ensure you have a C++ compiler (like `clang++` or `g++`) and the Raylib dependencies installed on your system.

1. **Compile**:
   ```bash
   make
   ```

2. **Run**:
   ```bash
   ./game
   ```

## Project Structure

- `src/main.cpp`: Entry point, window initialization, and main game loop.
- `src/simulation.cpp` / `.h`: Core Game of Life logic, rules execution, and state management.
- `src/grid.cpp` / `.h`: Data structure for the grid, handling cell drawing, and bounds/wrap-around logic.
