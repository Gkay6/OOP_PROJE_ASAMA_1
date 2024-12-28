#pragma once
#include "RobotInterface.h"
#include "FestoRobotAPI.h"

class FestoRobotInterface : public RobotInterface {
private:
    FestoRobotAPI* robotAPI;

public:
    FestoRobotInterface(FestoRobotAPI* api);
    ~FestoRobotInterface();

    void turnLeft() override;
    void turnRight() override;
    void moveForward() override;
    void moveBackward() override;
    void moveLeft() override;
    void moveRight() override;
    void stop() override;
    Pose getPose() const override;
    void print() const override;
    bool connectRobot() override;
    bool disconnectRobot() override;
};
