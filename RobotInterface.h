#pragma once
#include <list>
#include "Robotcontroler.h"
#include "Pose.h"
#include "SensorInterface.h" // SensorInterface tanımlı olmalı

class RobotInterface {
private:
    Pose* position;
    bool connectionstatus();
protected:
    std::list<SensorInterface*> sensorList; // Sensör adreslerini tutan liste
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
