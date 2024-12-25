#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include "Pose.h"
#include "FestoRobotAPI.h"
#include "RobotOperator.h"
#include "SensorInterface.h"
#include <list>
/**
 * @file RobotController.h
 * @brief Header file for the RobotController class.
 * 
 * @author Sefa Çelenk
 * @date 24.12.2024
 * 
 * This file contains the declaration of the RobotController class, which manages robot
 * operations, sensors, and access control. The class allows controlling robot movement, 
 * interacting with sensors, and managing connection to the robot.
 */

/**
 * @class RobotController
 * @brief Manages robot operations, sensors, and access control.
 * 
 * This class is responsible for controlling the robot's movements, handling sensor updates,
 * and managing access control through password authentication. It interacts with the robot
 * API, updates sensor information, and allows operators to command the robot.
 */
class RobotController {
private:
    std::list<SensorInterface*> sensorList; ///< List of sensors attached to the robot.
    RobotInterface* robot; ///< Robot API interface.
    RobotOperator robotOperator; ///< Operator responsible for controlling the robot.
    bool accessGranted; ///< Flag to indicate if access is granted.

public:
    /**
     * @brief Constructor for RobotController.
     * 
     * Initializes the robot controller with a specific robot interface and operator.
     * 
     * @param api The robot API interface.
     * @param operatorObj The robot operator.
     */
    RobotController(RobotInterface* api, const RobotOperator& operatorObj);
    /**
     * @brief Destructor for RobotController.
     * 
     * Cleans up resources and disconnects the robot if necessary.
     */
    ~RobotController();

    /**
     * @brief Turns the robot left.
     */
    void turnLeft();

    /**
     * @brief Turns the robot right.
     */
    void turnRight();

    /**
     * @brief Moves the robot forward.
     */
    void moveForward();

    /**
     * @brief Moves the robot backward.
     */
    void moveBackward();

    /**
     * @brief Moves the robot left.
     */
    void moveLeft();

    /**
     * @brief Moves the robot right.
     */
    void moveRight();

    /**
     * @brief Stops the robot's movement.
     */
    void stop();

    /**
     * @brief Gets the current pose of the robot.
     * 
     * @return The current pose of the robot.
     */
    Pose getPose() const;
    /**
     * @brief Prints information about the robot.
     */
    void print() const;
    /**
     * @brief Connects to the robot.
     * 
     * Establishes a connection with the robot.
     * 
     * @return True if the connection is successful, false otherwise.
     */
    bool connectRobot();
    /**
     * @brief Disconnects from the robot.
     * 
     * Terminates the connection with the robot.
     * 
     * @return True if the disconnection is successful, false otherwise.
     */
    bool disconnectRobot();

    /**
     * @brief Opens access to the robot using a password.
     * 
     * @param password The password used to grant access.
     * @return True if access is granted, false otherwise.
     */
    bool openAccess(int password);

    /**
     * @brief Closes access to the robot using a password.
     * 
     * @param password The password used to close access.
     * @return True if access is successfully closed, false otherwise.
     */
    bool closeAccess(int password);

    /**
     * @brief Adds a sensor to the robot.
     * 
     * @param sensor A pointer to the sensor to be added.
     */
    void addSensor(SensorInterface* sensor);

    /**
     * @brief Updates all sensors attached to the robot.
     */
    void updateSensors();
};

/**
 * @brief Test function for RobotController.
 * 
 * Tests the functionality of the RobotController by simulating commands.
 * 
 * @param robotino The robot controller to be tested.
 */
void RobotControllerTest(RobotController& robotino);
