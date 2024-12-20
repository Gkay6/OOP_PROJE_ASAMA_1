#include <iostream>
#include "MAP.h"
#include "POINT.h"

// Positive Test Cases
void test_insertPoint();
void test_getSetGrid();
void test_clearMap();
void test_printInfo();
void test_showMap();
void test_getNumberXandY();
void test_addGridSize();
void test_setGridSize();
void test_getSetXandY();
void test_setPoint();
void test_findDistanceToPos();
void test_findAngleToPos();
void test_operatorEquality();

int main() {
    // Positive tests
    test_insertPoint();
    test_getSetGrid();
    test_clearMap();
    test_printInfo();
    test_showMap();
    test_getNumberXandY();
    test_addGridSize();
    test_setGridSize();
    test_getSetXandY();
    test_setPoint();
    test_findDistanceToPos();
    test_findAngleToPos();
    test_operatorEquality();


    return 0;
}

void test_insertPoint() {
    std::cout << "==== TEST: insertPoint ====" << std::endl;
    MAP myMap(5, 5);

    POINT validPoint(2, 3);
    POINT invalidPoint(6, 7); // Point outside the map

    myMap.insertPoint(validPoint);
    std::cout << "Valid point (2,3) added to the grid:" << std::endl;
    myMap.showMap();

    myMap.insertPoint(invalidPoint);
    std::cout << "Invalid point (6,7) could not be added to the grid:" << std::endl;
    myMap.showMap();
}

void test_getSetGrid() {
    std::cout << "\n==== TEST: getGrid and setGrid ====" << std::endl;
    MAP myMap(5, 5);

    // Valid grid setting
    myMap.setGrid(2, 2, 1);
    std::cout << "After setGrid(2, 2, 1), map:" << std::endl;
    myMap.showMap();

    // Valid grid reading
    std::cout << "getGrid(2, 2): " << myMap.getGrid(2, 2) << std::endl;
}

void test_clearMap() {
    std::cout << "\n==== TEST: clearMap ====" << std::endl;
    MAP myMap(5, 5);

    myMap.setGrid(2, 2, 1);
    myMap.setGrid(3, 3, 1);
    std::cout << "Map before clearMap:" << std::endl;
    myMap.showMap();

    myMap.clearMap();
    std::cout << "Map after clearMap:" << std::endl;
    myMap.showMap();
}

void test_printInfo() {
    std::cout << "\n==== TEST: printInfo ====" << std::endl;
    MAP myMap(5, 5);

    std::cout << "Map information:" << std::endl;
    myMap.printInfo();
}

void test_showMap() {
    std::cout << "\n==== TEST: showMap ====" << std::endl;
    MAP myMap(5, 5);

    myMap.setGrid(1, 1, 1);
    myMap.setGrid(3, 3, 1);

    std::cout << "Map display:" << std::endl;
    myMap.showMap();
}

void test_getNumberXandY() {
    std::cout << "\n==== TEST: getNumberX and getNumberY ====" << std::endl;
    MAP myMap(5, 10);

    std::cout << "Number of X grids: " << myMap.getNumberX() << std::endl;
    std::cout << "Number of Y grids: " << myMap.getNumberY() << std::endl;
}

void test_addGridSize() {
    std::cout << "\n==== TEST: addGridSize ====" << std::endl;
    MAP myMap(5, 5);

    std::cout << "Initial map:" << std::endl;
    myMap.showMap();

    myMap.addGridSize(2, 3);
    std::cout << "After addGridSize(2, 3), map:" << std::endl;
    myMap.showMap();
    std::cout << "New number of X grids: " << myMap.getNumberX() << std::endl;
    std::cout << "New number of Y grids: " << myMap.getNumberY() << std::endl;
}

void test_setGridSize() {
    std::cout << "\n==== TEST: setGridSize ====" << std::endl;
    MAP myMap(5, 5);

    std::cout << "Initial map:" << std::endl;
    myMap.showMap();

    myMap.setGridSize(7, 8);
    std::cout << "After setGridSize(7, 8), map:" << std::endl;
    myMap.showMap();
    std::cout << "New number of X grids: " << myMap.getNumberX() << std::endl;
    std::cout << "New number of Y grids: " << myMap.getNumberY() << std::endl;
}

void test_getSetXandY() {
    std::cout << "==== TEST: getX, getY, setX, setY ====" << std::endl;

    POINT p(2, 3);  // Create point (2,3)
    std::cout << "Initial Point: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

    // Set new coordinates
    p.setX(5);
    p.setY(7);
    std::cout << "After setting X to 5 and Y to 7: (" << p.getX() << ", " << p.getY() << ")" << std::endl;
}

void test_setPoint() {
    std::cout << "\n==== TEST: setPoint ====" << std::endl;

    POINT p(2, 3);
    std::cout << "Initial Point: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

    // Set both X and Y
    p.setPoint(6, 8);
    std::cout << "After setting point to (6, 8): (" << p.getX() << ", " << p.getY() << ")" << std::endl;
}

void test_findDistanceToPos() {
    std::cout << "\n==== TEST: findDistanceToPos ====" << std::endl;

    POINT p1(2, 3);
    POINT p2(6, 8);

    double distance = p1.findDistanceToPos(p2);
    std::cout << "Distance between point (" << p1.getX() << ", " << p1.getY() << ") and point ("
        << p2.getX() << ", " << p2.getY() << "): " << distance << std::endl;
}

void test_findAngleToPos() {
    std::cout << "\n==== TEST: findAngleToPos ====" << std::endl;

    POINT p1(1, 1);
    POINT p2(4, 5);

    double angle = p1.findAngleToPos(p2);
    std::cout << "Angle between point (" << p1.getX() << ", " << p1.getY() << ") and point ("
        << p2.getX() << ", " << p2.getY() << "): " << angle << " degrees" << std::endl;
}

void test_operatorEquality() {
    std::cout << "\n==== TEST: operator== ====" << std::endl;

    POINT p1(2, 3);
    POINT p2(2, 3);
    POINT p3(5, 7);

    if (p1 == p2)
        std::cout << "p1 and p2 are equal." << std::endl;
    else
        std::cout << "p1 and p2 are not equal." << std::endl;

    if (p1 == p3)
        std::cout << "p1 and p3 are equal." << std::endl;
    else
        std::cout << "p1 and p3 are not equal." << std::endl;
}
