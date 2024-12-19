#ifndef POSE_H
#define POSE_H

#include <cmath> // For sqrt and atan2
#include <iostream>

class Pose {
private:
    double x;   // X coordinate
    double y;   // Y coordinate
    double th;  // Orientation angle in degrees

public:
    // Constructor
    Pose(double _x = 0.0, double _y = 0.0, double _th = 0.0);

    // Getter and Setter methods
    double getX() const;
    void setX(double _x);

    double getY() const;
    void setY(double _y);

    double getTh() const;
    void setTh(double _th);

    // Operator overloading
    bool operator==(const Pose& other) const;
    Pose operator+(const Pose& other) const;
    Pose operator-(const Pose& other) const;
    Pose& operator+=(const Pose& other);
    Pose& operator-=(const Pose& other);
    bool operator<(const Pose& other) const;

    // Set and get position
    void setPose(double _x, double _y, double _th);
    void getPose(double& _x, double& _y, double& _th) const;

    // Distance and angle difference between two Poses
    double findDistanceTo(const Pose& pos) const;
    double findAngleTo(const Pose& pos) const;
};

#endif // POSE_H



