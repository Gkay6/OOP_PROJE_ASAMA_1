#include "RobotController.h"
#include "FestoRobotAPI.h"
#include "Pose.h"
#include <iostream>
#include <windows.h>

/**
 * @file RobotController.cpp
 * @brief Implementation file for the RobotController class.
 *
 * @author Sefa Çelenk
 * @date 24.12.2024
 *
 * This file contains the implementation of the RobotController class, which manages robot
 * operations, sensors, and access control. It handles movement commands, connection management,
 * and sensor updates. The class ensures that operations are only performed when access is granted.
 */

 /**
  * @brief Constructor for RobotController.
  *
  * Initializes the robot controller with a specific robot interface and operator. It ensures
  * that the robot interface is not null.
  *
  * @param api The robot API interface.
  * @param operatorObj The robot operator.
  */
RobotController::RobotController(std::list<SensorInterface*> &_sensorList, RobotInterface* api, const string& surname, int code)
    : sensorList(_sensorList), robot(api), robotOperator(surname, code) {
    if (!robot) {
        std::cerr << "Error: Robot Interface cannot be null" << std::endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Turns the robot left.
 *
 * This operation is only performed if access is granted. If access is denied, an error message is printed.
 */
void RobotController::turnLeft() {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot perform operation: turnLeft()\n";
        return;
    }
    std::cout << "Robot turning left...\n";
    robot->turnLeft();
}

/**
 * @brief Turns the robot right.
 *
 * This operation is only performed if access is granted. If access is denied, an error message is printed.
 */
void RobotController::turnRight() {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot perform operation: turnRight()\n";
        return;
    }
    std::cout << "Robot turning right...\n";
    robot->turnRight();
}

/**
 * @brief Moves the robot forward.
 *
 * This operation is only performed if access is granted. If access is denied, an error message is printed.
 */
void RobotController::moveForward() {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot perform operation: moveForward()\n";
        return;
    }
    std::cout << "Robot moving forward...\n";
    robot->moveForward();
}

/**
 * @brief Moves the robot backward.
 *
 * This operation is only performed if access is granted. If access is denied, an error message is printed.
 */
void RobotController::moveBackward() {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot perform operation: moveBackward()\n";
        return;
    }
    std::cout << "Robot moving backward...\n";
    robot->moveBackward();
}

/**
 * @brief Moves the robot left sideways.
 *
 * This operation is only performed if access is granted. If access is denied, an error message is printed.
 */
void RobotController::moveLeft() {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot perform operation: moveLeft()\n";
        return;
    }
    std::cout << "Robot moving left sideways...\n";
    robot->moveLeft();
}

/**
 * @brief Moves the robot right sideways.
 *
 * This operation is only performed if access is granted. If access is denied, an error message is printed.
 */
void RobotController::moveRight() {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot perform operation: moveRight()\n";
        return;
    }
    std::cout << "Robot moving right sideways...\n";
    robot->moveRight();
}

/**
 * @brief Stops the robot.
 *
 * This operation is only performed if access is granted. If access is denied, an error message is printed.
 */
void RobotController::stop() {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot perform operation: stop()\n";
        return;
    }
    std::cout << "Robot stopping...\n";
    robot->stop();
}

/**
 * @brief Gets the current pose of the robot.
 *
 * This operation is only performed if access is granted. If access is denied, a default pose is returned.
 *
 * @return The current pose of the robot.
 */
Pose RobotController::getPose() const {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot retrieve pose.\n";
        return Pose(); // Return default Pose
    }

    return robot->getPose();
}

/**
 * @brief Prints the current sensor values and robot pose.
 *
 * This operation is only performed if access is granted. If access is denied, an error message is printed.
 */
void RobotController::print() const {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot perform operation: print()\n";
        return;
    }
    std::cout << "-------------------- SENSOR VALUES --------------------\n";
    std::cout << "POSE         : (X) " << this->getPose().getX() << " meters, "
        << "(Y) " << this->getPose().getY() << " meters, "
        << "(Th) " << (this->getPose().getTh() * 180) / 3.14 << " degrees\n\n";
}

/**
 * @brief Connects to the robot.
 *
 * This operation is only performed if access is granted. If access is denied, an error message is printed.
 *
 * @return True if the connection is successful, false otherwise.
 */
bool RobotController::connectRobot() {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot perform operation: connectRobot()\n";
        return false;
    }
    return robot->connectRobot();
}

/**
 * @brief Disconnects from the robot.
 *
 * This operation is only performed if access is granted. If access is denied, an error message is printed.
 *
 * @return True if the disconnection is successful, false otherwise.
 */
bool RobotController::disconnectRobot() {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot perform operation: disconnectRobot()\n";
        return false;
    }
    return robot->disconnectRobot();
}

/**
 * @brief Opens access to the robot using a password.
 *
 * @param password The password used to grant access.
 * @return True if access is granted, false otherwise.
 */
bool RobotController::openAccess(int password) {
    if (robotOperator.checkAccessCode(password)) {
        std::cout << "Access granted." << std::endl;
        return true;
    }
    std::cout << "Access denied." << std::endl;
    return false;
}

/**
 * @brief Closes access to the robot using a password.
 *
 * @param password The password used to close access.
 * @return True if access is successfully closed, false otherwise.
 */
bool RobotController::closeAccess(int password) {
    if (this->robotOperator.getAccessState() && robotOperator.checkAccessCode(password,false)) {
        std::cout << "Access closed." << std::endl;
        return true;
    }
    std::cout << "Access closure failed." << std::endl;
    return false;
}

bool RobotController::getAccessState() {
    return robotOperator.getAccessState();
}

/**
 * @brief Adds a sensor to the robot.
 *
 * This function is not yet implemented.
 *
 * @param sensor A pointer to the sensor to be added.
 */
void RobotController::addSensor(SensorInterface* sensor) {
    if (!sensor) {
        std::cerr << "Error: Null sensor cannot be added.\n";
        return;
    }

    sensorList.push_back(sensor);
    std::cout << "Sensor added: " << sensor->getSensorType() << "\n";
}


/**
 * @brief Updates all sensors attached to the robot.
 *
 * This function is not yet implemented.
 */
void RobotController::updateSensors() {
    if (!this->robotOperator.getAccessState()) {
        std::cerr << "Access denied. Cannot update sensors.\n";
        return;
    }

    std::cout << "Updating all sensors...\n";
    for (auto sensor : sensorList) {
        if (sensor) {
            sensor->update();
            std::cout << "Sensor updated: " << sensor->getSensorType() << "\n";
        }
    }
}
