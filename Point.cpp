#include "Point.h"

// Getter function
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

// Setter function
void Point::setX(double value) {
    x = value;
}

void Point::setY(double value) {
    y = value;
}

void Point::setPoint(double _x, double _y) {
    x = _x;
    y = _y;
}

// Calculate distance at two point
double Point::findDistanceToPos(const Point& p) const {
    return std::sqrt(std::pow(p.x - x, 2) + std::pow(p.y - y, 2));
}

// Decalculates the angle between two points (in radians)
double Point::findAngleToPos(const Point& p) const {
    return std::atan2(p.y - y, p.x - x);
}

// Operator overload: Equality control
bool Point::operator==(const Point& p) const {
    return (x == p.x) && (y == p.y);
}
