#include "RobotController.h"
#include <iostream>
#include <windows.h> // Sleep i�in

void printSeparator() {
    std::cout << "-----------------------------\n";
}

void RobotControllerTest(RobotController& robotino) {

    // Robota ba�lan
    /*
    if (robot.connectRobot()) {
        std::cout << "Robot successfully connected.\n";
    }
    else {
        std::cout << "Failed to connect to the robot.\n";
        return;
    }
    */
    std::cout << "RobotControllerTest-start" << std::endl;
    printSeparator();
    std::cout << "Initial Pose:\n";
    robotino.print();  // �lk pozisyonu yazd�r
    printSeparator();

    // 1. �leri ve Geri Hareket Testi
    std::cout << "Test 1: Move Forward and Backward\n";
    robotino.moveForward();
    Sleep(2000);  // 2 saniye ileri hareket et
    robotino.stop();
    robotino.print();

    robotino.moveBackward();
    Sleep(2000);  // 2 saniye geri hareket et
    robotino.stop();
    robotino.print();

    printSeparator();

    // 2. Sa�a ve Sola D�n�� Testi
    std::cout << "Test 2: Turn Left and Turn Right\n";
    robotino.turnLeft();
    Sleep(1000);  // 1 saniye sola d�n
    robotino.stop();
    robotino.print();

    robotino.turnRight();
    Sleep(1000);  // 1 saniye sa�a d�n
    robotino.stop();
    robotino.print();

    printSeparator();

    // 3. Sa�a ve Sola Yana Hareket Testi
    std::cout << "Test 3: Move Left and Move Right (sideways)\n";
    robotino.moveLeft();
    std::cout << "Robot moving left...\n";
    Sleep(2000);  // 2 saniye sola hareket et
    robotino.stop();
    robotino.print();

    robotino.moveRight();
    std::cout << "Robot moving right...\n";
    Sleep(2000);  // 2 saniye sa�a hareket et
    robotino.stop();
    robotino.print();

    printSeparator();

    // 4. Karma��k Hareket Kombinasyonu Testi
    std::cout << "Test 4: Complex Movement\n";

    robotino.moveForward();
    std::cout << "Moving forward...\n";
    Sleep(2000);
    robotino.stop();
    robotino.print();

    robotino.moveRight();
    std::cout << "Moving right sideways...\n";
    Sleep(2000);
    robotino.stop();
    robotino.print();

    robotino.turnLeft();
    std::cout << "Turning left...\n";
    Sleep(1000);
    robotino.stop();
    robotino.print();

    robotino.moveLeft();
    std::cout << "Moving left sideways...\n";
    Sleep(2000);
    robotino.stop();
    robotino.print();

    robotino.moveBackward();
    std::cout << "Moving backward...\n";
    Sleep(2000);
    robotino.stop();
    robotino.print();

    printSeparator();
    std::cout << "RobotControllerTest-end" << std::endl;
    // Robot ba�lant�s�n� kes
    //robot.disconnectRobot();
    //std::cout << "Robot disconnected successfully.\n";
}
