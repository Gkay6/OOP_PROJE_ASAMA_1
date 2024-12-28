#pragma once
#include "Pose.h"
#include <list>
#include "SensorInterface.h"



class RobotInterface {
protected:
    Pose* position = nullptr;
    bool connectionStatus;

public:
    virtual ~RobotInterface() = default;

    // Robot hareket fonksiyonları (saf sanal)
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void stop() = 0;

    // Pozisyon alma fonksiyonu
    virtual Pose getPose() const = 0;

    // Robot bilgilerini yazdırma
    virtual void print() const = 0;

    // Robot bağlantı fonksiyonları
    virtual bool connectRobot() = 0;
    virtual bool disconnectRobot() = 0;
};
