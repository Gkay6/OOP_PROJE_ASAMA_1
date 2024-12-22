/**
 * @file   Pose.cpp
 * @author Sefa Celenk
 * @date   December, 2024
 * @brief  Source file for the Pose class, which represents a position and orientation in a 2D space.
 *
 * This file contains the implementation of the Pose class, which allows for the representation and manipulation
 * of positions and orientations in a 2D space. The class provides functionalities for setting and getting
 * the position and orientation, calculating distances and angles to other positions, and performing basic
 * arithmetic operations such as addition and subtraction of poses. Overloaded operators allow for intuitive
 * pose manipulation and comparison.
 */
#include "Pose.h"
#include <cmath> //!< For mathematical functions like sqrt and atan2.

#ifndef M_PI
#define M_PI 3.14159265358979323846 //!< Define PI if not already defined.
#endif

/*!
 * \brief Constructor for the Pose class.
 * \param _x Initial x-coordinate.
 * \param _y Initial y-coordinate.
 * \param _th Initial orientation angle in degrees.
 */
Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}

// Getter and Setter methods

/*!
 * \brief Getter for the x-coordinate.
 * \return The x-coordinate of the Pose.
 */
double Pose::getX() const { return x; }

/*!
 * \brief Setter for the x-coordinate.
 * \param _x The new x-coordinate value.
 */
void Pose::setX(double _x) { x = _x; }

/*!
 * \brief Getter for the y-coordinate.
 * \return The y-coordinate of the Pose.
 */
double Pose::getY() const { return y; }

/*!
 * \brief Setter for the y-coordinate.
 * \param _y The new y-coordinate value.
 */
void Pose::setY(double _y) { y = _y; }

/*!
 * \brief Getter for the orientation angle.
 * \return The orientation angle in degrees.
 */
double Pose::getTh() const { return th; }

/*!
 * \brief Setter for the orientation angle.
 * \param _th The new orientation angle in degrees.
 */
void Pose::setTh(double _th) { th = _th; }

// Operator overloading

/*!
 * \brief Equality operator.
 * \param other Another Pose object to compare.
 * \return True if the Poses are equal, false otherwise.
 */
bool Pose::operator==(const Pose& other) const {
    return x == other.x && y == other.y && th == other.th;
}

/*!
 * \brief Addition operator.
 * \param other Another Pose object to add.
 * \return A new Pose object that is the sum of the two Poses.
 */
Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

/*!
 * \brief In-place addition operator.
 * \param other Another Pose object to add.
 * \return A reference to the modified current Pose object.
 */
Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

/*!
 * \brief Subtraction operator.
 * \param other Another Pose object to subtract.
 * \return A new Pose object that is the difference between the two Poses.
 */
Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

/*!
 * \brief In-place subtraction operator.
 * \param other Another Pose object to subtract.
 * \return A reference to the modified current Pose object.
 */
Pose& Pose::operator-=(const Pose& other) {
    x -= other.x;
    y -= other.y;
    th -= other.th;
    return *this;
}

/*!
 * \brief Less-than operator.
 * \param other Another Pose object for comparison.
 * \return True if the current Pose is less than the other, false otherwise.
 * \note Compares using the distance to the origin (0, 0).
 */
bool Pose::operator<(const Pose& other) const {
    double distanceThis = findDistanceTo(Pose(0.0, 0.0, 0.0));
    double distanceOther = other.findDistanceTo(Pose(0.0, 0.0, 0.0));
    return distanceThis < distanceOther;
}

// Position methods

/*!
 * \brief Setter for all components of the Pose.
 * \param _x New x-coordinate.
 * \param _y New y-coordinate.
 * \param _th New orientation angle in degrees.
 */
void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}

/*!
 * \brief Getter for all components of the Pose.
 * \param _x Reference to store the x-coordinate.
 * \param _y Reference to store the y-coordinate.
 * \param _th Reference to store the orientation angle in degrees.
 */
void Pose::getPose(double& _x, double& _y, double& _th) const {
    _x = x;
    _y = y;
    _th = th;
}

// Distance and angle methods

/*!
 * \brief Calculates the Euclidean distance to another Pose.
 * \param pos Another Pose object for distance calculation.
 * \return The Euclidean distance between the two Poses.
 */
double Pose::findDistanceTo(const Pose& pos) const {
    return sqrt(pow(pos.x - x, 2) + pow(pos.y - y, 2));
}

/*!
 * \brief Calculates the angular difference to another Pose.
 * \param pos Another Pose object for angle calculation.
 * \return The angular difference in degrees.
 */
double Pose::findAngleTo(const Pose& pos) const {
    return atan2(pos.y - y, pos.x - x) * 180.0 / M_PI; //!< Convert radians to degrees.
}
