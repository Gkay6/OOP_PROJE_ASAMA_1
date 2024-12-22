#include "Pose.h"
#include <iostream>

void printSeparator() {
    std::cout << "-----------------------------\n";
}

void PoseTest() {
    std::cout << "PoseTest - Start" << std::endl;
    printSeparator();

    // 1. Default and Parameterized Constructor Test
    std::cout << "Test 1: Constructors\n";
    Pose p1; // Default constructor
    Pose p2(3.0, 4.0, 45.0); // Parameterized constructor
    std::cout << "Default Pose p1: (" << p1.getX() << ", " << p1.getY() << ", " << p1.getTh() << ")\n";
    std::cout << "Parameterized Pose p2: (" << p2.getX() << ", " << p2.getY() << ", " << p2.getTh() << ")\n";
    printSeparator();

    // 2. Getter and Setter Methods Test
    std::cout << "Test 2: Getter and Setter Methods\n";
    p1.setX(1.0);
    p1.setY(2.0);
    p1.setTh(30.0);
    std::cout << "Updated Pose p1: (" << p1.getX() << ", " << p1.getY() << ", " << p1.getTh() << ")\n";
    printSeparator();

    // 3. Equality Operator Test
    std::cout << "Test 3: Equality Operator (==)\n";
    Pose p3(1.0, 2.0, 30.0); // Construct a Pose identical to p1
    if (p1 == p3) {
        std::cout << "p1 is equal to p3\n";
    } else {
        std::cout << "p1 is not equal to p3\n";
    }
    printSeparator();

    // 4. Addition and Subtraction Operators Test
    std::cout << "Test 4: Addition and Subtraction Operators\n";
    Pose p4 = p1 + p2; // Addition of two Pose objects
    Pose p5 = p2 - p1; // Subtraction of two Pose objects
    std::cout << "p4 (p1 + p2): (" << p4.getX() << ", " << p4.getY() << ", " << p4.getTh() << ")\n";
    std::cout << "p5 (p2 - p1): (" << p5.getX() << ", " << p5.getY() << ", " << p5.getTh() << ")\n";
    printSeparator();

    // 5. Compound Assignment Operators Test
    std::cout << "Test 5: Compound Assignment Operators (+=, -=)\n";
    p1 += p2; // Increment p1 by p2
    std::cout << "p1 after += p2: (" << p1.getX() << ", " << p1.getY() << ", " << p1.getTh() << ")\n";
    p1 -= p3; // Decrement p1 by p3
    std::cout << "p1 after -= p3: (" << p1.getX() << ", " << p1.getY() << ", " << p1.getTh() << ")\n";
    printSeparator();

    // 6. Less-than Operator Test
    std::cout << "Test 6: Less-than Operator (<)\n";
    if (p1 < p2) {
        std::cout << "p1 is closer to the origin than p2\n";
    } else {
        std::cout << "p1 is not closer to the origin than p2\n";
    }
    printSeparator();

    // 7. setPose and getPose Test
    std::cout << "Test 7: setPose and getPose\n";
    p1.setPose(0.0, 0.0, 0.0); // Reset p1 to the origin
    double x, y, th;
    p1.getPose(x, y, th); // Retrieve components of p1
    std::cout << "Pose of p1 after setPose: (" << x << ", " << y << ", " << th << ")\n";
    printSeparator();

    // 8. Distance and Angle Calculation Test
    std::cout << "Test 8: Distance and Angle Calculations\n";
    double distance = p2.findDistanceTo(p1); // Calculate distance between p2 and p1
    double angle = p2.findAngleTo(p1); // Calculate angle between p2 and p1
    std::cout << "Distance from p2 to p1: " << distance << "\n";
    std::cout << "Angle from p2 to p1: " << angle << " degrees\n";
    printSeparator();

    std::cout << "PoseTest - End" << std::endl;
}
