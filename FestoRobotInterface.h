#pragma once
#include "RobotInterface.h"
#include "FestoRobotAPI.h"

/** 
 * @file   FestoRobotInterface.h
 * @author Omer Ozkan,Gokay Taspinar
 * @date   December, 2024
 * @brief  Header file for the FestoRobotInterface class, which provides a concrete implementation 
 *         of the RobotInterface for controlling a Festo robot using FestoRobotAPI.
 *
 * This file contains the declaration of the FestoRobotInterface class, which extends the 
 * RobotInterface class to control a Festo robot. It encapsulates FestoRobotAPI to perform 
 * robot movements, retrieve the robot's pose, and manage connection states, providing a 
 * high-level abstraction for interacting with the robot.
 */

class FestoRobotInterface : public RobotInterface {
private:
    FestoRobotAPI* robotAPI; //!< Pointer to the API used for interacting with the Festo robot.

public:
    /**
     * @brief Constructor for the FestoRobotInterface class.
     * 
     * @param api Pointer to an instance of FestoRobotAPI for interacting with the robot.
     */
    FestoRobotInterface(FestoRobotAPI* api);

    //! Destructor for the FestoRobotInterface class.
    ~FestoRobotInterface();

    /**
     * @brief Turns the robot to the left.
     * 
     * Overrides the pure virtual function in RobotInterface.
     */
    void turnLeft() override;

    /**
     * @brief Turns the robot to the right.
     * 
     * Overrides the pure virtual function in RobotInterface.
     */
    void turnRight() override;

    /**
     * @brief Moves the robot forward.
     * 
     * Overrides the pure virtual function in RobotInterface.
     */
    void moveForward() override;

    /**
     * @brief Moves the robot backward.
     * 
     * Overrides the pure virtual function in RobotInterface.
     */
    void moveBackward() override;

    /**
     * @brief Moves the robot to the left.
     * 
     * Overrides the pure virtual function in RobotInterface.
     */
    void moveLeft() override;

    /**
     * @brief Moves the robot to the right.
     * 
     * Overrides the pure virtual function in RobotInterface.
     */
    void moveRight() override;

    /**
     * @brief Stops the robot's movement.
     * 
     * Overrides the pure virtual function in RobotInterface.
     */
    void stop() override;

    /**
     * @brief Retrieves the current pose of the robot.
     * 
     * @return Pose object representing the robot's current position and orientation.
     * Overrides the pure virtual function in RobotInterface.
     */
    Pose getPose() const override;

    /**
     * @brief Prints detailed information about the robot.
     * 
     * Overrides the pure virtual function in RobotInterface.
     */
    void print() const override;

    /**
     * @brief Establishes a connection with the robot.
     * 
     * @return True if the connection is successful, false otherwise.
     * Overrides the pure virtual function in RobotInterface.
     */
    bool connectRobot() override;

    /**
     * @brief Disconnects the robot.
     * 
     * @return True if the disconnection is successful, false otherwise.
     * Overrides the pure virtual function in RobotInterface.
     */
    bool disconnectRobot() override;
};
