#pragma once
#include <list>
#include "SensorInterface.h"

class Pose {
public:
    double x, y, theta;

    Pose(double x = 0, double y = 0, double theta = 0) : x(x), y(y), theta(theta) {}
};

class RobotInterface {
protected:
    std::list<SensorInterface*> sensorList; //!< Sensörlerin adreslerini tutan liste
    Pose currentPose; //!< Robotun mevcut pozisyonu

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
    virtual Pose getPose() const;

    // Robot bilgilerini yazdırma
    virtual void print() const;

    // Robot bağlantı fonksiyonları
    virtual bool connectRobot();
    virtual bool disconnectRobot();

    // Sensör ekleme fonksiyonu
    void addSensor(SensorInterface* sensor);

    // Sensör güncelleme fonksiyonu
    void updateSensors();
};
