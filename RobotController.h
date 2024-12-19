#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include "Pose.h"
#include "FestoRobotAPI.h"
// Forward declaration for the FestoRobotAPI class

class RobotController {
private:
    Pose* position;           // Position of the robot
    FestoRobotAPI* robotAPI;  // Access to the Festo Robot API (provided externally, managed by the user)
    bool connectionStatus;    // Connection status of the robot

public:
    // Constructor and Destructor
    RobotController(FestoRobotAPI* api); // Constructor that takes an API object
    ~RobotController();

    // Robot Control Functions
    void turnLeft();
    void turnRight();
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void stop();

    // Information Functions
    Pose getPose() const;
    void print() const;

    // Connection Functions
    bool connectRobot();
    bool disconnectRobot();
};

void RobotControllerTest(RobotController& robotino);
#endif // ROBOTCONTROLLER_H



