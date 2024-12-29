#pragma once
#include "Pose.h"
#include <list>
#include "SensorInterface.h"

/** 
 * @file   RobotInterface.h
 * @author Omer Ozkan
 * @date   December, 2024
 * @brief  Header file for the RobotInterface class, which serves as an abstract base class 
 *         for different robot implementations, defining essential robot functionalities.
 *
 * This file contains the declaration of the RobotInterface class, providing an interface 
 * for robot control. It includes pure virtual methods for robot movements, retrieving the 
 * robot's pose, and managing connection states. This interface is intended to be implemented 
 * by specific robot types, ensuring a consistent API for robot interactions.
 */

class RobotInterface {
protected:
    Pose* position = nullptr; //!< Pointer to the robot's position data.
    bool connectionStatus;    //!< Status of the robot's connection (true if connected, false otherwise).

public:
    //! Virtual destructor.
    virtual ~RobotInterface() = default;

    /**
     * @brief Turns the robot to the left.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual void turnLeft() = 0;

    /**
     * @brief Turns the robot to the right.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual void turnRight() = 0;

    /**
     * @brief Moves the robot forward.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual void moveForward() = 0;

    /**
     * @brief Moves the robot backward.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual void moveBackward() = 0;

    /**
     * @brief Moves the robot to the left.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual void moveLeft() = 0;

    /**
     * @brief Moves the robot to the right.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual void moveRight() = 0;

    /**
     * @brief Stops the robot's movement.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual void stop() = 0;

    /**
     * @brief Retrieves the current pose of the robot.
     * 
     * @return Pose object representing the robot's current position and orientation.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual Pose getPose() const = 0;

    /**
     * @brief Prints detailed information about the robot.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual void print() const = 0;

    /**
     * @brief Establishes a connection with the robot.
     * 
     * @return True if the connection is successful, false otherwise.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool connectRobot() = 0;

    /**
     * @brief Disconnects the robot.
     * 
     * @return True if the disconnection is successful, false otherwise.
     * @note This is a pure virtual function to be implemented by derived classes.
     */
    virtual bool disconnectRobot() = 0;
};
