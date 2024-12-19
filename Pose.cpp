#include "Pose.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Constructor
Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}

// Getter and Setter methods
double Pose::getX() const { return x; }
void Pose::setX(double _x) { x = _x; }

double Pose::getY() const { return y; }
void Pose::setY(double _y) { y = _y; }

double Pose::getTh() const { return th; }
void Pose::setTh(double _th) { th = _th; }

// operator== : Equality check
bool Pose::operator==(const Pose& other) const {
    return x == other.x && y == other.y && th == other.th;
}

// operator+ : Add two Pose objects
Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

// operator+= : Add and assign
Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

// operator- : Subtract two Pose objects
Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

// operator-= : Subtract and assign
Pose& Pose::operator-=(const Pose& other) {
    x -= other.x;
    y -= other.y;
    th -= other.th;
    return *this;
}

// operator< : Less-than comparison
bool Pose::operator<(const Pose& other) const {
    // Compare using distance to the origin (0, 0)
    double distanceThis = findDistanceTo(Pose(0.0, 0.0, 0.0));
    double distanceOther = other.findDistanceTo(Pose(0.0, 0.0, 0.0));
    return distanceThis < distanceOther;
}

// setPose : Set position
void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}

// getPose : Get position
void Pose::getPose(double& _x, double& _y, double& _th) const {
    _x = x;
    _y = y;
    _th = th;
}

// findDistanceTo : Calculate the distance between two Pose objects
double Pose::findDistanceTo(const Pose& pos) const {
    return sqrt(pow(pos.x - x, 2) + pow(pos.y - y, 2));
}

// findAngleTo : Calculate the angle difference between two Pose objects
double Pose::findAngleTo(const Pose& pos) const {
    return atan2(pos.y - y, pos.x - x) * 180.0 / M_PI; // Convert radians to degrees
}


