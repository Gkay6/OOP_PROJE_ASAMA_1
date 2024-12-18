#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include "Pose.h"

class FestoRobotAPI; // FestoRobotAPI s�n�f� i�in ileri bildirim

class RobotController {
private:
    Pose* position;           // Robotun pozisyonu
    FestoRobotAPI* robotAPI;  // Festo Robot API eri�imi (d��ar�dan al�n�r, y�netimi kullan�c�ya aittir)
    bool connectionStatus;    // Robot ba�lant� durumu

public:
    // Constructor ve Destructor
    RobotController(FestoRobotAPI* api); // API nesnesini d��ar�dan alan constructor
    ~RobotController();

    // Robot Kontrol Fonksiyonlar�
    void turnLeft();
    void turnRight();
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void stop();

    // Bilgi Fonksiyonlar�
    Pose getPose() const;
    void print() const;

    // Ba�lant� Fonksiyonlar�
    bool connectRobot();
    bool disconnectRobot();
};

#endif // ROBOTCONTROLLER_H


