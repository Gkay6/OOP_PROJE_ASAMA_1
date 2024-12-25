#pragma once
#include "RobotInterface.h"
#include "FestoRobotAPI.h"

class FestoRobotInterface : public RobotInterface {
private:
    FestoRobotAPI* robotAPI;

public:
    FestoRobotInterface(FestoRobotAPI* api);

    void turnLeft() override;
    void turnRight() override;
    void moveForward() override;
    void moveBackward() override;
    void moveLeft() override;
    void moveRight() override;
    void stop() override;
    void getPose() override;
    void print() override;
    bool connectRobot() override;
    bool disconnectRobot() override;
};
