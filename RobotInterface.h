#pragma once
#include <list>
#include "Robotcontroler.h"
#include "Pose.h"
#include "SensorInterface.h" 

class RobotInterface {
private:
    Pose* position;
    protected:
    bool connectionStatus
    std::list<SensorInterface*> sensorList;
public:
    virtual ~RobotInterface() = default;

    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void stop() = 0;

    virtual Pose getPose() const = 0;

    virtual void print() const = 0;

    virtual bool connectRobot() = 0;
    virtual bool disconnectRobot() = 0;

    // Yeni sensör fonksiyonları
    virtual void addSensor(SensorInterface* sensor) = 0;
    virtual void updateSensors() = 0;
};
