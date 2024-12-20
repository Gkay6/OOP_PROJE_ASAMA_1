#pragma once
#include <iostream>
#include "POINT.h"

class MAP {
private:
    int gridNumberX; // Number of grids along the X-axis
    int gridNumberY; // Number of grids along the Y-axis
    int** grid;      // 2D grid (0: empty, 1: filled)

public:
    // Constructor and Destructor
    MAP(int x = 10, int y = 10);  // Constructor with default values for grid size
    ~MAP();                      // Destructor to clean up dynamically allocated memory

    // Point insertion
    void insertPoint(const POINT& point);  // Adds a point to the map

    // Getter and Setter
    int getGrid(int x, int y) const;  // Gets the value at the specified grid coordinates
    void setGrid(int x, int y, int value);  // Sets the value at the specified grid coordinates

    // Map operations
    void clearMap();  // Clears the map (sets all grid cells to empty)
    void printInfo() const;  // Prints map-related information
    void showMap() const;    // Displays the grid visually

    // Grid size operations
    int getNumberX() const;  // Gets the number of grids along the X-axis
    int getNumberY() const;  // Gets the number of grids along the Y-axis

    void addGridSize(int x, int y);  // Adds to the grid size in both X and Y directions
    void setGridSize(int x, int y);  // Sets a new grid size along both X and Y axes
};
