#include "FestoRobotInterface.h"
#include <iostream>

FestoRobotInterface::FestoRobotInterface(FestoRobotAPI* _robotAPI) {
    robotAPI = _robotAPI;
}

FestoRobotInterface::~FestoRobotInterface() {
    delete robotAPI;
}

void FestoRobotInterface::turnLeft() {
    robotAPI->rotate(LEFT);
}

void FestoRobotInterface::turnRight() {
    robotAPI->rotate(RIGHT);
}

void FestoRobotInterface::moveForward() {
    robotAPI->move(FORWARD);
}

void FestoRobotInterface::moveBackward() {
    robotAPI->move(BACKWARD);
}

void FestoRobotInterface::moveLeft() {
    robotAPI->move(LEFT);
}

void FestoRobotInterface::moveRight() {
    robotAPI->move(RIGHT);
}

void FestoRobotInterface::stop() {
    robotAPI->stop();
}

Pose FestoRobotInterface::getPose() const {
    double x;
    double y;
    double th;
    robotAPI->getXYTh(x, y, th);
    return Pose(x, y, th);
}

void FestoRobotInterface::print() const {
    double x;
    double y;
    double th;
    robotAPI->getXYTh(x, y, th);
    std::cout << "Pose: X = " << x << ", Y = " << y << ", TH = " << th << "\n";
}

bool FestoRobotInterface::connectRobot() {
    if (!connectionStatus) {
        robotAPI->connect();
        Sleep(2000);
        connectionStatus = true;
        double x = 0, y = 0, th = 0;

        if (position == nullptr) {
            position = new Pose();  // Dynamically allocate memory for position
        }

        robotAPI->getXYTh(x, y, th);
        position->setPose(x, y, th);
        std::cout << "Robot connected successfully.\n";
        return true;
    }
    std::cout << "Robot already connected.\n";
    return false;
}

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
