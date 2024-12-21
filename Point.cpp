#include "Point.h"

/*!
 * @brief Returns the X coordinate.
 *
 * @return The value of the X coordinate.
 */
double Point::getX() const {
    return x;
}

/*!
 * @brief Returns the Y coordinate.
 *
 * @return The value of the Y coordinate.
 */
double Point::getY() const {
    return y;
}

/*!
 * @brief Sets the X coordinate.
 *
 * @param value: The new value for the X coordinate.
 */
void Point::setX(double value) {
    x = value;
}

/*!
 * @brief Sets the Y coordinate.
 *
 * @param value: The new value for the Y coordinate.
 */
void Point::setY(double value) {
    y = value;
}

/*!
 * @brief Sets both the X and Y coordinates.
 *
 * @param _x: The new value for the X coordinate.
 * @param _y: The new value for the Y coordinate.
 */
void Point::setPoint(double _x, double _y) {
    x = _x;
    y = _y;
}

/*!
 * @brief Calculates the distance between two points.
 *
 * @param p: The target point.
 * @return The distance value.
 */
double Point::findDistanceToPos(const Point& p) const {
    return std::sqrt(std::pow(p.x - x, 2) + std::pow(p.y - y, 2));
}

/*!
 * @brief Calculates the angle between two points (in radians).
 *
 * @param p: The target point.
 * @return The angle value (in radians).
 */
double Point::findAngleToPos(const Point& p) const {
    return std::atan2(p.y - y, p.x - x);
}

/*!
 * @brief Checks the equality of two points.
 *
 * @param p: The point to compare with.
 * @return A boolean value indicating equality.
 * @retval true: If the points are equal.
 * @retval false: If the points are not equal.
 */
bool Point::operator==(const Point& p) const {
    return (x == p.x) && (y == p.y);
}
