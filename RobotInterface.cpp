#include "RobotInterface.h"
#include <iostream>

// Sensör ekleme fonksiyonu
void RobotInterface::addSensor(SensorInterface* sensor) {
    if (sensor != nullptr) {
        sensorList.push_back(sensor);
    } else {
        std::cerr << "Error: Null sensor cannot be added to the list.\n";
    }
}

// Sensör güncelleme fonksiyonu
void RobotInterface::updateSensors() {
    for (auto sensor : sensorList) {
        if (sensor != nullptr) {
            sensor->update();
        } else {
            std::cerr << "Warning: Encountered null sensor in the list.\n";
        }
    }
}

// Pozisyon alma fonksiyonu
Pose RobotInterface::getPose() const {
    return currentPose;
}

// Robot bilgilerini yazdırma
void RobotInterface::print() const {
    std::cout << "Robot Pose: (" << currentPose.x << ", " << currentPose.y << ", " << currentPose.theta << ")\n";
    std::cout << "Number of sensors: " << sensorList.size() << "\n";
}

// Robot bağlantı fonksiyonları
bool RobotInterface::connectRobot() {
    std::cout << "Robot connected.\n";
    return true;
}

bool RobotInterface::disconnectRobot() {
    std::cout << "Robot disconnected.\n";
    return true;
}

// Hareket fonksiyonları (saf sanal, bu sınıfta tanımlı değil)
