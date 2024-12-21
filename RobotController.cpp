/*!
 * \file RobotController.cpp
 * \author Sefa Çelenk
 * \date 20.12.2024
 * \brief Implementation file for the RobotController class, which manages robot control and state using the FestoRobotAPI.
 */

#include "RobotController.h"
#include "FestoRobotAPI.h"
#include "Pose.h"
#include <iostream>
#include <windows.h> // For Sleep function

// Constructor
/*!
 * \brief Initializes the RobotController with a FestoRobotAPI object.
 * \param api Pointer to an instance of FestoRobotAPI.
 * \throws std::invalid_argument if the API object is null.
 */
RobotController::RobotController(FestoRobotAPI* api)
    : position(new Pose()), robotAPI(api), connectionStatus(false) {
    if (!robotAPI) {
        throw std::invalid_argument("Robot API cannot be null");
    }
}

// Destructor
/*!
 * \brief Cleans up resources and disconnects the robot if necessary.
 */
RobotController::~RobotController() {
    if (robotAPI) {
        robotAPI->disconnect();
        delete robotAPI;
    }
    delete position;
    std::cout << "RobotController destroyed.\n";
}

// Robot Control Functions
/*!
 * \brief Commands the robot to turn left.
 */
void RobotController::turnLeft() {
    std::cout << "Robot turning left...\n";
    robotAPI->rotate(LEFT);
}

/*!
 * \brief Commands the robot to turn right.
 */
void RobotController::turnRight() {
    std::cout << "Robot turning right...\n";
    robotAPI->rotate(RIGHT);
}

/*!
 * \brief Commands the robot to move forward.
 */
void RobotController::moveForward() {
    std::cout << "Robot moving forward...\n";
    robotAPI->move(FORWARD);
}

/*!
 * \brief Commands the robot to move backward.
 */
void RobotController::moveBackward() {
    std::cout << "Robot moving backward...\n";
    robotAPI->move(BACKWARD);
}

/*!
 * \brief Commands the robot to move left sideways.
 */
void RobotController::moveLeft() {
    std::cout << "Robot moving left sideways...\n";
    robotAPI->move(LEFT);
}

/*!
 * \brief Commands the robot to move right sideways.
 */
void RobotController::moveRight() {
    std::cout << "Robot moving right sideways...\n";
    robotAPI->move(RIGHT);
}

/*!
 * \brief Commands the robot to stop moving.
 */
void RobotController::stop() {
    std::cout << "Robot stopping...\n";
    robotAPI->stop();
}

// Information Functions
/*!
 * \brief Retrieves the current pose of the robot.
 * \return A Pose object representing the robot's current position and orientation.
 */
Pose RobotController::getPose() const {
    double x, y, th;
    robotAPI->getXYTh(x, y, th);
    position->setPose(x, y, th);
    return *position;
}

/*!
 * \brief Prints the current state of the robot to the console.
 */
void RobotController::print() const {
    std::cout << "-------------------- SENSOR VALUES --------------------\n";
    std::cout << "POSE         : (X) " << this->getPose().getX() << " meters, "
              << "(Y) " << this->getPose().getY() << " meters, "
              << "(Th) " << (this->getPose().getTh() * 180) / 3.14 << " degrees\n\n";
}

// Connection Functions
/*!
 * \brief Connects the robot to the API.
 * \return True if the connection is successful, false otherwise.
 */
bool RobotController::connectRobot() {
    if (!connectionStatus) {
        robotAPI->connect();
        Sleep(2000);
        connectionStatus = true;
        double x = 0, y = 0, th = 0;
        robotAPI->getXYTh(x, y, th);
        position->setPose(x, y, th);
        std::cout << "Robot connected successfully.\n";
        return true;
    }
    std::cout << "Robot already connected.\n";
    return false;
}

/*!
 * \brief Disconnects the robot from the API.
 * \return True if the disconnection is successful, false otherwise.
 */
bool RobotController::disconnectRobot() {
    if (connectionStatus) {
        robotAPI->disconnect();
        connectionStatus = false;
        std::cout << "Robot disconnected successfully.\n";
        return true;
    }
    std::cout << "Robot is not connected.\n";
    return false;
}
