#include "FestoRobotInterface.h"
#include <iostream>

FestoRobotInterface::FestoRobotInterface() {
    robotAPI = new FestoRobotAPI();
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

void FestoRobotInterface::getPose(double& x, double& y, double& th) {
    robotAPI->getXYTh(x, y, th);
}

void FestoRobotInterface::print() {
    double x, y, th;
    getPose(x, y, th);
    std::cout << "Pose: X = " << x << ", Y = " << y << ", TH = " << th << std::endl;
}

bool FestoRobotInterface::connectRobot() {
    robotAPI->connect();
    return true;
}

bool FestoRobotInterface::disconnectRobot() {
    robotAPI->disconnect();
    return true;
}
void FestoRobotInterface::addSensor(SensorInterface* sensor) {
    sensorList.push_back(sensor);
}

void FestoRobotInterface::updateSensors() {
    for (auto& sensor : sensorList) {
        if (sensor) {
            sensor->updateSensor();
        }
    }
}
