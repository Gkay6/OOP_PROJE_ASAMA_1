#include "POINT.h"

// Getter function
double POINT::getX() const {
    return x;
}

double POINT::getY() const {
    return y;
}

// Setter function
void POINT::setX(double value) {
    x = value;
}

void POINT::setY(double value) {
    y = value;
}

void POINT::setPoint(double _x, double _y) {
    x = _x;
    y = _y;
}

// Calculate distance at two point
double POINT::findDistanceToPos(const POINT& p) const {
    return std::sqrt(std::pow(p.x - x, 2) + std::pow(p.y - y, 2));
}

// Decalculates the angle between two points (in radians)
double POINT::findAngleToPos(const POINT& p) const {
    return std::atan2(p.y - y, p.x - x);
}

// Operator overload: Equality control
bool POINT::operator==(const POINT& p) const {
    return (x == p.x) && (y == p.y);
}
