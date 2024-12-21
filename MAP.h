/** 
 * @file   MAP.h
 * @author Omer Ozkan
 * @date   December, 2024
 * @brief  Header file for the MAP class, which represents a 2D grid map, supporting operations 
 *         such as adding points, resizing the grid, and visualizing the map.
 *
 * This file contains the definition of the MAP class, which is used to create a 2D grid map with specified 
 * dimensions. The class allows for inserting points into the grid, retrieving and setting values at specific 
 * grid cells, and resizing the grid. Additionally, it provides methods for clearing the map, printing map 
 * information, and visually displaying the grid. The map is represented by a 2D array, where grid cells can 
 * either be empty or filled. This class is useful for applications involving spatial mapping, visualization, 
 * and grid-based operations.
 */

#pragma once
#include <iostream>
#include "Point.h"

/**
 * @class MAP
 * @brief Class representing a 2D grid map.
 *
 * This class is used to create a map, add points, and visualize the map.
 * It also supports operations such as resizing the grid.
 */
class MAP {
private:
    int gridNumberX; //! Number of grids along the X axis.
    int gridNumberY; //! Number of grids along the Y axis.
    int room_X;      //! X coordinate of the room.
    int room_Y;      //! Y coordinate of the room.
    int** grid;      //! 2D grid (0: empty, 1: filled).

public:
    /*!
     * @brief Constructor for the MAP class.
     *
     * @param x Number of grids along the X axis (default: 10).
     * @param y Number of grids along the Y axis (default: 10).
     * @param roomx X coordinate of the room (default: 0).
     * @param roomy Y coordinate of the room (default: 0).
     */
    MAP(int x = 10, int y = 10, int roomx = 0, int roomy = 0);

    //! Destructor.
    ~MAP();

    /*!
     * @brief Adds a point to the grid.
     *
     * @param point The point to be added.
     */
    void insertPoint(const Point& point);

    /*!
     * @brief Returns the value at a specific grid cell.
     *
     * @param x X coordinate.
     * @param y Y coordinate.
     * @return The value at the cell.
     */
    int getGrid(int x, int y) const;

    /*!
     * @brief Sets a value at a specific grid cell.
     *
     * @param x X coordinate.
     * @param y Y coordinate.
     * @param value The value to set.
     */
    void setGrid(int x, int y, int value);

    /*!
     * @brief Clears the map.
     */
    void clearMap();

    /*!
     * @brief Prints map information to the console.
     */
    void printInfo() const;

    /*!
     * @brief Displays the map visually in the console.
     */
    void showMap() const;

    /*!
     * @brief Returns the number of grids along the X axis.
     *
     * @return Number of grids along the X axis.
     */
    int getNumberX() const;

    /*!
     * @brief Returns the number of grids along the Y axis.
     *
     * @return Number of grids along the Y axis.
     */
    int getNumberY() const;

    /*!
     * @brief Expands the grid size.
     *
     * @param x Additional size for the X axis.
     * @param y Additional size for the Y axis.
     */
    void addGridSize(int x, int y);

    /*!
     * @brief Updates the grid size.
     *
     * @param x New size for the X axis.
     * @param y New size for the Y axis.
     */
    void setGridSize(int x, int y);
};
