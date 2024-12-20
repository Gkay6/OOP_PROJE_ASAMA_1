#include "MAP.h"
#include <iostream>

// Constructor: Sets grid dimensions and initializes all grid elements to 0

MAP::MAP(int x, int y, int roomx, int roomy ) : gridNumberX(x), gridNumberY(y), room_X(roomx), room_Y(roomy){
    grid = new int* [gridNumberY];
    for (int i = 0; i < gridNumberY; ++i) {
        grid[i] = new int[gridNumberX];
        // Initialize all elements in each row to zero
        for (int j = 0; j < gridNumberX; ++j) {
            grid[i][j] = 0;
        }
    }
}


// Destructor: Cleans up dynamic memory
MAP::~MAP() {
    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

// Assigns a value of 1 to the point's coordinates on the grid
void MAP::insertPoint(const Point& point) {
    int gridX = point.getX() - room_X;
    int gridY = point.getY() - room_Y;

    std::cout << "at that coordinate :"<< gridX << "," << gridY << "\n";

    if (gridX >= 0 && gridX < gridNumberX && gridY >= 0 && gridY < gridNumberY) {
        grid[gridY][gridX] = 1;
    }
    else {
        std::cerr << "Error: The point is out of the valid grid area!" << std::endl;
    }
}

// Returns the value at the given grid coordinates
int MAP::getGrid(int x, int y) const {
    int adjustedX = x - room_X;
    int adjustedY = y - room_Y;

    if (adjustedX < 0 || adjustedY < 0 || adjustedX >= gridNumberX || adjustedY >= gridNumberY) {
        std::cerr << "Error: Invalid grid coordinates (" << x << ", " << y << ")." << std::endl;
        return -1;
    }
    return grid[adjustedY][adjustedX];
}


// Sets a value at the specified grid index: for example, setting (2, 2) to 1
void MAP::setGrid(int x, int y, int value) {
    int adjustedX = x - room_X;
    int adjustedY = y - room_Y;

    if (adjustedX < 0 || adjustedY < 0 || adjustedX >= gridNumberX || adjustedY >= gridNumberY) {
        std::cerr << "Error: Invalid grid coordinates (" << x << ", " << y << ")." << std::endl;
        return;
    }
    grid[adjustedY][adjustedX] = value;
}


// Resets all grids to zero
void MAP::clearMap() {
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            grid[i][j] = 0; // Correct access
        }
    }
}

// Prints grid information
void MAP::printInfo() const {
    std::cout << "Grid Size: " << gridNumberX << " x " << gridNumberY << "\n";
    std::cout << "Total Grid Number: " << gridNumberX * gridNumberY << "\n";
}

// Prints the grid to the console
void MAP::showMap() const {
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            std::cout << (grid[i][j] == 0 ? "." : "x") << " "; // Doğru erişim
        }
        std::cout << "\n";
    }
}

// Returns the number of grids along the X axis
int MAP::getNumberX() const {
    return gridNumberX;
}

// Returns the number of grids along the Y axis
int MAP::getNumberY() const {
    return gridNumberY;
}
void MAP::addGridSize(int x, int y) {
    if (x < 0 || y < 0 ) {
        std::cerr << "Error: Invalid values." << std::endl;
        return; // No operation for invalid index
    }
    // Get the current grid dimensions

    // Calculate the new grid dimensions
    int newGridNumberX = gridNumberX + x;
    int newGridNumberY = gridNumberY + y;

    // Allocate memory for the new grid
    int** newGrid = new int* [newGridNumberY];
    for (int i = 0; i < newGridNumberY; ++i) {
        newGrid[i] = new int[newGridNumberX] {0}; // 0's for new grid
    }
    

    // Copy the old grid data to the new grid
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            newGrid[i][j] = grid[i][j]; // Copy old data to the new grid
        }
    }

    // Clean up the old grid
    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i];  // Free each row of the old grid
    }
    delete[] grid;  // Free the old grid itself

    // Assign the new grid
    grid = newGrid;

    // Update grid dimensions
    setGridSize(newGridNumberX, newGridNumberY);
}

// Resizes the grid
void MAP::setGridSize(int x, int y) {
    if (x < 0 || y < 0) {
        std::cerr << "Error: Invalid values." << std::endl;
        return; // No operation for invalid index
    }
    // Clean up the old grid
    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i];
    }
    delete[] grid;

    // Create the new grid
    gridNumberX = x;
    gridNumberY = y;
    grid = new int*[gridNumberY];
    for (int i = 0; i < gridNumberY; ++i) {
        grid[i] = new int[gridNumberX]{0};
    }
}
