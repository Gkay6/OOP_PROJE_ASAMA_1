#include "RobotController.h"
#include "FestoRobotAPI.h"
#include "Pose.h"
#include <iostream>
#include <windows.h> // Sleep için

// Constructor
RobotController::RobotController(FestoRobotAPI* api)
    : position(new Pose()), robotAPI(api), connectionStatus(false) {
    if (!robotAPI) {
        throw std::invalid_argument("Robot API cannot be null");
    }
}

// Destructor
RobotController::~RobotController() {
    if (robotAPI) {
        robotAPI->disconnect();
        delete robotAPI;
    }
    delete position;
    std::cout << "RobotController destroyed.\n";
}

// Robot Kontrol Fonksiyonlarý
void RobotController::turnLeft() {
    std::cout << "Robot turning left...\n";
    robotAPI->rotate(LEFT);
}

void RobotController::turnRight() {
    std::cout << "Robot turning right...\n";
    robotAPI->rotate(RIGHT);
    
}

void RobotController::moveForward() {
    std::cout << "Robot moving forward...\n";
    robotAPI->move(FORWARD);
   
}

void RobotController::moveBackward() {
    std::cout << "Robot moving backward...\n";
    robotAPI->move(BACKWARD);
    
}

void RobotController::moveLeft() {
    std::cout << "Robot moving left sideways...\n";
    robotAPI->move(LEFT);
    
}

void RobotController::moveRight() {
    std::cout << "Robot moving right sideways...\n";
    robotAPI->move(RIGHT);
}

void RobotController::stop() {
    std::cout << "Robot stopping...\n";
    robotAPI->stop();
}

// Bilgi Fonksiyonlarý
Pose RobotController::getPose() const {
    double x, y, th;
    robotAPI->getXYTh(x, y, th);
    position->setPose(x, y, th);
    return *position;
}

void RobotController::print() const {
    double x, y, th;
    robotAPI->getXYTh(x, y, th);

    // Pose bilgilerini yazdýr
    std::cout << "-------------------- SENSOR VALUES --------------------\n";
    std::cout << "POSE         : (X) " << x << " meters, "
        << "(Y) " << y << " meters, "
        << "(Th) " << (th * 180) / 3.14 << " degrees\n\n";

    // IR Sensör deðerlerini yazdýr
    double ir[9];
    for (int i = 0; i < 9; i++)
        ir[i] = robotAPI->getIRRange(i);

    std::cout << "IR RANGES : \n";
    std::cout << "       FRONT           \n";
    std::cout << "        " << ir[0] << "           \n";
    std::cout << "    " << ir[1] << "     " << ir[8] << "      \n";
    std::cout << "    " << ir[2] << "     " << ir[7] << "      \n";
    std::cout << "    " << ir[3] << "     " << ir[6] << "      \n";
    std::cout << "    " << ir[4] << "     " << ir[5] << "      \n";
    std::cout << "------------------------------------------------------\n";

    // Lidar deðerlerini yazdýr
    int number = robotAPI->getLidarRangeNumber();
    float* ranges = new float[number];
    robotAPI->getLidarRange(ranges);

    std::cout << "-------------------- LIDAR VALUES (in meters) --------------------\n";
    for (int i = 0; i < number; i++) {
        std::cout << i << " -> " << ranges[i] << "\n";
    }
    std::cout << "------------------------------------------------------\n";

    delete[] ranges;
}

// Baðlantý Fonksiyonlarý
bool RobotController::connectRobot() {
    if (!connectionStatus) {
        robotAPI->connect();
        Sleep(2000); 
        connectionStatus = true;
        std::cout << "Robot connected successfully.\n";
        return true;
    }
    std::cout << "Robot already connected.\n";
    return false;
}

bool RobotController::disconnectRobot() {
    if (connectionStatus) {
        robotAPI->disconnect();
        connectionStatus = false;
        std::cout << "Robot disconnected successfully.\n";
        return true;
    }
    std::cout << "Robot is not connected.\n";
    return false;
}
