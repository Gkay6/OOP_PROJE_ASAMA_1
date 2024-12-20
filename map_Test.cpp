#include <iostream>
#include "MAP.h"
#include "POINT.h"

// Positive and Negative Test Cases
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
    // Tests
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
    std::cout << "==== TEST: insertPoint ====\n";
    MAP myMap(5, 5);

    POINT validPoint(2, 3);
    POINT invalidPoint(-1, 7); // Negative coordinates
    POINT outOfBoundsPoint(10, 10); // Out-of-bounds coordinates

    myMap.insertPoint(validPoint);
    std::cout << "Valid point (2,3) added to the grid:\n";
    myMap.showMap();

    myMap.insertPoint(invalidPoint);
    std::cout << "Invalid point (-1,7) could not be added to the grid:\n";
    myMap.showMap();

    myMap.insertPoint(outOfBoundsPoint);
    std::cout << "Out-of-bounds point (10,10) could not be added to the grid:\n";
    myMap.showMap();
}

void test_getSetGrid() {
    std::cout << "\n==== TEST: getGrid and setGrid ====\n";
    MAP myMap(5, 5);

    myMap.setGrid(2, 2, 1);
    std::cout << "After setGrid(2, 2, 1), map:\n";
    myMap.showMap();
    std::cout << "getGrid(2, 2): " << myMap.getGrid(2, 2) << "\n";
    //hatalý olacak durumlar
    myMap.setGrid(6, 6, 1);//bu nokta yok
     myMap.getGrid(-1, -1);//bu negatif
}

void test_clearMap() {
    std::cout << "\n==== TEST: clearMap ====\n";
    MAP myMap(5, 5);

    myMap.setGrid(2, 2, 1);
    myMap.setGrid(3, 3, 1);
    std::cout << "Map before clearMap:\n";
    myMap.showMap();

    myMap.clearMap();
    std::cout << "Map after clearMap:\n";
    myMap.showMap();
}

void test_printInfo() {
    std::cout << "\n==== TEST: printInfo ====\n";
    MAP myMap(5, 5);

    std::cout << "Map information:\n";
    myMap.printInfo();
}

void test_showMap() {
    std::cout << "\n==== TEST: showMap ====\n";
    MAP myMap(5, 5);

    myMap.setGrid(1, 1, 1);
    myMap.setGrid(3, 3, 1);

    std::cout << "Map display:\n";
    myMap.showMap();
}

void test_getNumberXandY() {
    std::cout << "\n==== TEST: getNumberX and getNumberY ====\n";
    MAP myMap(5, 10);

    std::cout << "Number of X grids: " << myMap.getNumberX() << "\n";
    std::cout << "Number of Y grids: " << myMap.getNumberY() << "\n";
}

void test_addGridSize() {
    std::cout << "\n==== TEST: addGridSize ====\n";
    MAP myMap(5, 5);

    std::cout << "Initial map:\n";
    myMap.showMap();

    myMap.addGridSize(2, 3);
    std::cout << "After addGridSize(2, 3), map:\n";
    myMap.showMap();

        myMap.addGridSize(-1, -1);
}

void test_setGridSize() {
    std::cout << "\n==== TEST: setGridSize ====\n";
    MAP myMap(5, 5);

    std::cout << "Initial map:\n";
    myMap.showMap();

    myMap.setGridSize(7, 8);
    std::cout << "After setGridSize(7, 8), map:\n";
    myMap.showMap();

    myMap.setGridSize(-5, -5);
    myMap.setGridSize(3, 3);

    std::cout << "After setGridSize(3, 3), map:\n";
    myMap.showMap();
}

void test_getSetXandY() {
    std::cout << "\n==== TEST: getX, getY, setX, setY ====\n";

    POINT p(2, 3);
    std::cout << "Initial Point: (" << p.getX() << ", " << p.getY() << ")\n";

    p.setX(5);
    p.setY(7);
    std::cout << "After setting X to 5 and Y to 7: (" << p.getX() << ", " << p.getY() << ")\n";
}

void test_setPoint() {
    std::cout << "\n==== TEST: setPoint ====\n";

    POINT p(2, 3);
    std::cout << "Initial Point: (" << p.getX() << ", " << p.getY() << ")\n";

    p.setPoint(6, 8);
    std::cout << "After setting point to (6, 8): (" << p.getX() << ", " << p.getY() << ")\n";
}

void test_findDistanceToPos() {
    std::cout << "\n==== TEST: findDistanceToPos ====\n";

    POINT p1(2, 3);
    POINT p2(6, 8);

    double distance = p1.findDistanceToPos(p2);
    std::cout << "Distance between (" << p1.getX() << ", " << p1.getY() << ") and ("
        << p2.getX() << ", " << p2.getY() << "): " << distance << "\n";

    distance = p1.findDistanceToPos(p1);
    std::cout << "Distance between the same point: " << distance << "\n";
}

void test_findAngleToPos() {
    std::cout << "\n==== TEST: findAngleToPos ====\n";

    POINT p1(1, 1);
    POINT p2(1, 1);

    try {
        double angle = p1.findAngleToPos(p2);
        std::cout << "Angle between identical points: " << angle << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error during angle calculation: " << e.what() << "\n";
    }
}

void test_operatorEquality() {
    std::cout << "\n==== TEST: operator== ====\n";

    POINT p1(2, 3);
    POINT p2(2, 3);
    POINT p3(5, 7);

    if (p1 == p2)
        std::cout << "p1 and p2 are equal.\n";
    else
        std::cout << "p1 and p2 are not equal.\n";

    if (p1 == p3)
        std::cout << "p1 and p3 are equal.\n";
    else
        std::cout << "p1 and p3 are not equal.\n";
}
