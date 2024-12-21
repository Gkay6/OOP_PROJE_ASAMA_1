#include "MAP.h"
#include <iostream>

/*!
 * @brief Constructor: Sets the grid dimensions and initializes all grid elements to 0.
 *
 * @param x Number of cells in the X axis of the grid.
 * @param y Number of cells in the Y axis of the grid.
 * @param roomx X coordinate of the starting room.
 * @param roomy Y coordinate of the starting room.
 */
MAP::MAP(int x, int y, int roomx, int roomy) : gridNumberX(x), gridNumberY(y), room_X(roomx), room_Y(roomy) {
    grid = new int* [gridNumberY];
    for (int i = 0; i < gridNumberY; ++i) {
        grid[i] = new int[gridNumberX];
        for (int j = 0; j < gridNumberX; ++j) {
            grid[i][j] = 0;
        }
    }
}

/*!
 * @brief Destructor: Frees dynamically allocated memory.
 */
MAP::~MAP() {
    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

/*!
 * @brief Adds a point's coordinates to the grid.
 *
 * @param point The point to be added.
 */
void MAP::insertPoint(const Point& point) {
    int gridX = point.getX() - room_X;
    int gridY = point.getY() - room_Y;

    std::cout << "At that coordinate: " << gridX << "," << gridY << "\n";

    if (gridX >= 0 && gridX < gridNumberX && gridY >= 0 && gridY < gridNumberY) {
        grid[gridY][gridX] = 1;
    }
    else {
        std::cerr << "Error: The point is out of the valid grid area!" << std::endl;
    }
}

/*!
 * @brief Returns the grid value at the specified coordinates.
 *
 * @param x X axis coordinate.
 * @param y Y axis coordinate.
 * @return The grid value; returns -1 for invalid coordinates.
 */
int MAP::getGrid(int x, int y) const {
    int adjustedX = x - room_X;
    int adjustedY = y - room_Y;

    if (adjustedX < 0 || adjustedY < 0 || adjustedX >= gridNumberX || adjustedY >= gridNumberY) {
        std::cerr << "Error: Invalid grid coordinates (" << x << ", " << y << ")." << std::endl;
        return -1;
    }
    return grid[adjustedY][adjustedX];
}

/*!
 * @brief Sets a value at the specified grid cell.
 *
 * @param x X axis coordinate.
 * @param y Y axis coordinate.
 * @param value The value to be set.
 */
void MAP::setGrid(int x, int y, int value) {
    int adjustedX = x - room_X;
    int adjustedY = y - room_Y;

    if (adjustedX < 0 || adjustedY < 0 || adjustedX >= gridNumberX || adjustedY >= gridNumberY) {
        std::cerr << "Error: Invalid grid coordinates (" << x << ", " << y << ")." << std::endl;
        return;
    }
    grid[adjustedY][adjustedX] = value;
}

/*!
 * @brief Resets all grid cells to zero.
 */
void MAP::clearMap() {
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            grid[i][j] = 0;
        }
    }
}

/*!
 * @brief Prints grid information.
 */
void MAP::printInfo() const {
    std::cout << "Grid Size: " << gridNumberX << " x " << gridNumberY << "\n";
    std::cout << "Total Grid Number: " << gridNumberX * gridNumberY << "\n";
}

/*!
 * @brief Displays the grid.
 */
void MAP::showMap() const {
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            std::cout << (grid[i][j] == 0 ? "." : "x") << " ";
        }
        std::cout << "\n";
    }
}

/*!
 * @brief Returns the number of cells in the X axis of the grid.
 *
 * @return Number of cells in the X axis.
 */
int MAP::getNumberX() const {
    return gridNumberX;
}

/*!
 * @brief Returns the number of cells in the Y axis of the grid.
 *
 * @return Number of cells in the Y axis.
 */
int MAP::getNumberY() const {
    return gridNumberY;
}

/*!
 * @brief Increases the grid size.
 *
 * @param x Number of cells to be added in the X axis.
 * @param y Number of cells to be added in the Y axis.
 */
void MAP::addGridSize(int x, int y) {
    if (x < 0 || y < 0) {
        std::cerr << "Error: Invalid values." << std::endl;
        return;
    }

    int newGridNumberX = gridNumberX + x;
    int newGridNumberY = gridNumberY + y;

    int** newGrid = new int* [newGridNumberY];
    for (int i = 0; i < newGridNumberY; ++i) {
        newGrid[i] = new int[newGridNumberX] {0};
    }

    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            newGrid[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i];
    }
    delete[] grid;

    grid = newGrid;
    setGridSize(newGridNumberX, newGridNumberY);
}

/*!
 * @brief Resizes the grid.
 *
 * @param x New number of cells in the X axis.
 * @param y New number of cells in the Y axis.
 */
void MAP::setGridSize(int x, int y) {
    if (x < 0 || y < 0) {
        std::cerr << "Error: Invalid values." << std::endl;
        return;
    }

    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i];
    }
    delete[] grid;

    gridNumberX = x;
    gridNumberY = y;
    grid = new int* [gridNumberY];
    for (int i = 0; i < gridNumberY; ++i) {
        grid[i] = new int[gridNumberX] {0};
    }
}
