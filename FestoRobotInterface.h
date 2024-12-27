#pragma once
#include "RobotInterface.h"
#include "FestoRobotAPI.h"
#include "SensorInterface.h"

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
    Pose getPose() const override;         //bunu pose classından buraya nasıl çekicem anlamadım robot interface aracılığıyla
    void print() override;
    bool connectRobot() override;
    bool disconnectRobot() override;

    // Yeni sensör fonksiyonları
    void addSensor(SensorInterface* sensor) override;
    void updateSensors() override;
};
