#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include "Pose.h"

class FestoRobotAPI; // FestoRobotAPI sýnýfý için ileri bildirim

class RobotController {
private:
    Pose* position;           // Robotun pozisyonu
    FestoRobotAPI* robotAPI;  // Festo Robot API eriþimi
    bool connectionStatus;    // Robot baðlantý durumu

public:
    // Constructor ve Destructor
    RobotController();
    ~RobotController();

    // Robot Kontrol Fonksiyonlarý
    void turnLeft();
    void turnRight();
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void stop();

    // Bilgi Fonksiyonlarý
    Pose getPose() const;
    void print() const;

    // Baðlantý Fonksiyonlarý
    bool connectRobot();
    bool disconnectRobot();
};

#endif // ROBOTCONTROLLER_H

