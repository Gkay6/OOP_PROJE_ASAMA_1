#include "FestoRobotInterface.h"
#include <iostream>

/** 
 * @file   FestoRobotInterface.cpp
 * @author Omer Ozkan, Gokay Taspinar
 * @date   December, 2024
 * @brief  Implementation file for the FestoRobotInterface class, defining methods 
 *         for controlling a Festo robot using FestoRobotAPI.
 *
 * This file contains the implementation of the FestoRobotInterface class, which provides 
 * concrete methods for robot movements, pose retrieval, and connection management. 
 * It integrates FestoRobotAPI to handle low-level robot operations, offering a simplified 
 * interface for interacting with the robot.
 */

FestoRobotInterface::FestoRobotInterface(FestoRobotAPI* _robotAPI) {
    robotAPI = _robotAPI;
}

/**
 * @brief Destructor for the FestoRobotInterface.
 *
 * Deletes the FestoRobotAPI instance to free allocated memory.
 */
FestoRobotInterface::~FestoRobotInterface() {
    delete robotAPI;
}

/**
 * @brief Turns the robot to the left by invoking the API's rotate function.
 */
void FestoRobotInterface::turnLeft() {
    robotAPI->rotate(LEFT);
}

/**
 * @brief Turns the robot to the right by invoking the API's rotate function.
 */
void FestoRobotInterface::turnRight() {
    robotAPI->rotate(RIGHT);
}

/**
 * @brief Moves the robot forward by invoking the API's move function.
 */
void FestoRobotInterface::moveForward() {
    robotAPI->move(FORWARD);
}

/**
 * @brief Moves the robot backward by invoking the API's move function.
 */
void FestoRobotInterface::moveBackward() {
    robotAPI->move(BACKWARD);
}

/**
 * @brief Moves the robot to the left by invoking the API's move function.
 */
void FestoRobotInterface::moveLeft() {
    robotAPI->move(LEFT);
}

/**
 * @brief Moves the robot to the right by invoking the API's move function.
 */
void FestoRobotInterface::moveRight() {
    robotAPI->move(RIGHT);
}

/**
 * @brief Stops the robot's movement by invoking the API's stop function.
 */
void FestoRobotInterface::stop() {
    robotAPI->stop();
}

/**
 * @brief Retrieves the current pose of the robot.
 * 
 * @return Pose object representing the robot's position (X, Y) and orientation (TH).
 */
Pose FestoRobotInterface::getPose() const {
    double x;
    double y;
    double th;
    robotAPI->getXYTh(x, y, th);
    return Pose(x, y, th);
}

/**
 * @brief Prints the robot's current pose to the console.
 */
void FestoRobotInterface::print() const {
    double x;
    double y;
    double th;
    robotAPI->getXYTh(x, y, th);
    std::cout << "Pose: X = " << x << ", Y = " << y << ", TH = " << th << "\n";
}

/**
 * @brief Establishes a connection with the robot.
 * 
 * Initializes the robot's position and sets the connection status to true.
 * 
 * @return True if the connection is successful, false otherwise.
 */
bool FestoRobotInterface::connectRobot() {
    if (!connectionStatus) {
        robotAPI->connect();
        Sleep(2000);
        connectionStatus = true;
        double x = 0, y = 0, th = 0;

        if (position == nullptr) {
            position = new Pose();  //!< Dynamically allocate memory for position.
        }

        robotAPI->getXYTh(x, y, th);
        position->setPose(x, y, th);
        std::cout << "Robot connected successfully.\n";
        return true;
    }
    std::cout << "Robot already connected.\n";
    return false;
}

/**
 * @brief Disconnects the robot and updates the connection status.
 * 
 * @return True if the disconnection is successful, false otherwise.
 */
bool FestoRobotInterface::disconnectRobot() {
    if (connectionStatus) {
        robotAPI->disconnect();
        connectionStatus = false;
        std::cout << "Robot disconnected successfully.\n";
        return true;
    }
    std::cout << "Robot is not connected.\n";
    return false;
}
