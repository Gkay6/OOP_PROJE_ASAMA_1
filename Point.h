#pragma once
#include <iostream>  // For console output
#include <cmath>     // For mathematical calculations
#include <cassert>   // For error checking (optional)

class Point {
public:
    // Member variables
    double x;
    double y;

    // Constructor: Default and parameterized
    Point(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

    // Getter and Setter Functions
    double getX() const;                     // Returns the X coordinate
    double getY() const;                     // Returns the Y coordinate
    void setX(double value);                 // Sets the X coordinate
    void setY(double value);                 // Sets the Y coordinate
    void setPoint(double _x, double _y);     // Sets both X and Y coordinates

    // Operations between points
    double findDistanceToPos(const Point& p) const;  // Calculates the distance to another point
    double findAngleToPos(const Point& p) const;     // Calculates the angle to another point

    // Operator overloads
    bool operator==(const Point& p) const;           // Compares equality between points
};
