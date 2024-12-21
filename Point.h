/** 
 * @file   Point.h
 * @author Omer Ozkan
 * @date   December, 2024
 * @brief  Header file for the Point class that represents a point in a 2D Cartesian coordinate system and provides various operations such as distance and angle calculations.
 *
 * This file contains the definition of the Point class, which represents a point in a two-dimensional
 * Cartesian coordinate system. It includes functions for retrieving and modifying the point's coordinates,
 * as well as performing geometric operations like calculating the distance and angle to other points. 
 * The class provides constructors for initialization and overloaded operators for comparing points.
 */

#pragma once
#include <iostream>  //! For console output.
#include <cmath>     //! For mathematical calculations.
#include <cassert>   //! For error checking (optional).

/**
 * @class Point
 * @brief Class representing a point in a 2D coordinate system.
 *
 * This class is used to store the coordinates of a point, calculate the distance
 * and angle to another point, and perform related operations.
 */
class Point {
public:
    double x; //! X coordinate.
    double y; //! Y coordinate.

    /*!
     * @brief Default and parameterized constructor for the Point class.
     *
     * @param _x: Initial value of the X coordinate (default: 0.0).
     * @param _y: Initial value of the Y coordinate (default: 0.0).
     */
    Point(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

    /*!
     * @brief Returns the X coordinate.
     *
     * @return X coordinate.
     */
    double getX() const;

    /*!
     * @brief Returns the Y coordinate.
     *
     * @return Y coordinate.
     */
    double getY() const;

    /*!
     * @brief Sets the X coordinate.
     *
     * @param value: New value for the X coordinate.
     */
    void setX(double value);

    /*!
     * @brief Sets the Y coordinate.
     *
     * @param value: New value for the Y coordinate.
     */
    void setY(double value);

    /*!
     * @brief Sets both X and Y coordinates.
     *
     * @param _x: New value for the X coordinate.
     * @param _y: New value for the Y coordinate.
     */
    void setPoint(double _x, double _y);

    /*!
     * @brief Calculates the distance to another point.
     *
     * @param p: Target point.
     * @return Distance value.
     */
    double findDistanceToPos(const Point& p) const;

    /*!
     * @brief Calculates the angle to another point.
     *
     * @param p: Target point.
     * @return Angle value (in radians).
     */
    double findAngleToPos(const Point& p) const;

    /*!
     * @brief Checks the equality of two points.
     *
     * @param p: Point to compare with.
     * @return True if the points are equal, otherwise false.
     */
    bool operator==(const Point& p) const;
};
