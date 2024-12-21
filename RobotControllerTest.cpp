/*!
 * \file RobotControllerTest.cpp
 * \author Sefa Çelenk
 * \date 20.12.2024
 * \brief Test file for the RobotController class. Contains a test function to verify robot movements and pose updates.
 */

#include "RobotController.h"
#include <iostream>
#include <windows.h> // For Sleep function

/*!
 * \brief Prints a separator line for better test output readability.
 */
void printSeparator() {
    std::cout << "-----------------------------\n";
}

/*!
 * \brief Test function for the RobotController class. Verifies robot movements and pose updates.
 * \param robotino Reference to an instance of RobotController.
 */
void RobotControllerTest(RobotController& robotino) {
    std::cout << "RobotControllerTest-start\n";
    printSeparator();

    std::cout << "Initial Pose:\n";
    robotino.print(); // Print the initial position
    printSeparator();

    // 1. Forward and Backward Movement Test
    std::cout << "Test 1: Move Forward and Backward\n";
    robotino.moveForward();
    Sleep(2000); // Move forward for 2 seconds
    robotino.stop();
    robotino.print();

    robotino.moveBackward();
    Sleep(2000); // Move backward for 2 seconds
    robotino.stop();
    robotino.print();
    printSeparator();

    // 2. Left and Right Turn Test
    std::cout << "Test 2: Turn Left and Turn Right\n";
    robotino.turnLeft();
    Sleep(1000); // Turn left for 1 second
    robotino.stop();
    robotino.print();

    robotino.turnRight();
    Sleep(1000); // Turn right for 1 second
    robotino.stop();
    robotino.print();
    printSeparator();

    // 3. Left and Right Sideways Movement Test
    std::cout << "Test 3: Move Left and Move Right (sideways)\n";
    robotino.moveLeft();
    std::cout << "Robot moving left...\n";
    Sleep(2000); // Move left sideways for 2 seconds
    robotino.stop();
    robotino.print();

    robotino.moveRight();
    std::cout << "Robot moving right...\n";
    Sleep(2000); // Move right sideways for 2 seconds
    robotino.stop();
    robotino.print();
    printSeparator();

    // 4. Complex Movement Combination Test
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

    std::cout << "RobotControllerTest-end\n";
}
