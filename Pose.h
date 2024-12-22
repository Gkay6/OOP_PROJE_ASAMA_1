/**
 * @file   Pose.h
 * @author Sefa Çelenk
 * @date   December, 2024
 * @brief  Header file for the Pose class, which represents a position and orientation in 2D space.
 *
 * This file contains the definition of the Pose class, which is used to represent a position and orientation
 * in a 2D space. The class provides methods for setting and getting the position and orientation, calculating
 * distances and angles to other positions, and performing basic arithmetic operations. Overloaded operators
 * enable intuitive manipulation and comparison of Pose objects. This class is useful for applications involving
 * robotics, navigation, and spatial calculations.
 */
#ifndef POSE_H
#define POSE_H

#include <cmath> //!< For mathematical functions like sqrt and atan2.
#include <iostream> //!< For input/output operations.


class Pose {
private:
    double x;   //!< X-coordinate of the Pose.
    double y;   //!< Y-coordinate of the Pose.
    double th;  //!< Orientation angle in degrees.

public:
    /*!
     * \brief Constructor for the Pose class.
     * \param _x Initial x-coordinate (default is 0.0).
     * \param _y Initial y-coordinate (default is 0.0).
     * \param _th Initial angle in degrees (default is 0.0).
     */
    Pose(double _x = 0.0, double _y = 0.0, double _th = 0.0);

    /*!
     * \brief Getter for the x-coordinate.
     * \return The x-coordinate of the Pose.
     */
    double getX() const;

    /*!
     * \brief Setter for the x-coordinate.
     * \param _x The new x-coordinate value.
     */
    void setX(double _x);

    /*!
     * \brief Getter for the y-coordinate.
     * \return The y-coordinate of the Pose.
     */
    double getY() const;

    /*!
     * \brief Setter for the y-coordinate.
     * \param _y The new y-coordinate value.
     */
    void setY(double _y);

    /*!
     * \brief Getter for the orientation angle.
     * \return The orientation angle in degrees.
     */
    double getTh() const;

    /*!
     * \brief Setter for the orientation angle.
     * \param _th The new orientation angle in degrees.
     */
    void setTh(double _th);

    /*!
     * \brief Equality operator.
     * \param other Another Pose object to compare.
     * \return True if the Poses are equal, false otherwise.
     */
    bool operator==(const Pose& other) const;

    /*!
     * \brief Addition operator.
     * \param other Another Pose object to add.
     * \return A new Pose object that is the sum of the two Poses.
     */
    Pose operator+(const Pose& other) const;

    /*!
     * \brief Subtraction operator.
     * \param other Another Pose object to subtract.
     * \return A new Pose object that is the difference between the two Poses.
     */
    Pose operator-(const Pose& other) const;

    /*!
     * \brief In-place addition operator.
     * \param other Another Pose object to add.
     * \return A reference to the modified current Pose object.
     */
    Pose& operator+=(const Pose& other);

    /*!
     * \brief In-place subtraction operator.
     * \param other Another Pose object to subtract.
     * \return A reference to the modified current Pose object.
     */
    Pose& operator-=(const Pose& other);

    /*!
     * \brief Less-than operator.
     * \param other Another Pose object for comparison.
     * \return True if the current Pose is less than the other, false otherwise.
     */
    bool operator<(const Pose& other) const;

    /*!
     * \brief Setter for all components of the Pose.
     * \param _x New x-coordinate.
     * \param _y New y-coordinate.
     * \param _th New orientation angle in degrees.
     */
    void setPose(double _x, double _y, double _th);

    /*!
     * \brief Getter for all components of the Pose.
     * \param _x Reference to store the x-coordinate.
     * \param _y Reference to store the y-coordinate.
     * \param _th Reference to store the orientation angle in degrees.
     */
    void getPose(double& _x, double& _y, double& _th) const;

    /*!
     * \brief Calculates the Euclidean distance to another Pose.
     * \param pos Another Pose object for distance calculation.
     * \return The Euclidean distance between the two Poses.
     */
    double findDistanceTo(const Pose& pos) const;

    /*!
     * \brief Calculates the angular difference to another Pose.
     * \param pos Another Pose object for angle calculation.
     * \return The angular difference in degrees.
     */
    double findAngleTo(const Pose& pos) const;
};

/*!
 * \brief Test function for the Pose class.
 * \author Sefa Çelenk
 * \date 20.12.2024
 */
void PoseTest();

#endif // POSE_H
