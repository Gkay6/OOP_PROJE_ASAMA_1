#pragma once
#include <iostream>
#include "POINT.h"

class MAP {
private:
    int gridNumberX; // X eksenindeki grid sayýsý
    int gridNumberY; // Y eksenindeki grid sayýsý
    int** grid;      // 2D grid (0: boþ, 1: dolu)

public:
    // Constructor ve Destructor
    MAP(int x = 10, int y = 10);
    ~MAP();

    // Nokta ekleme
    void insertPoint(const POINT& point);

    // Getter ve Setter
    int getGrid(int x, int y) const;
    void setGrid(int x, int y, int value);

    // Harita iþlemleri
    void clearMap();
    void printInfo() const;
    void showMap() const;

    // Grid boyut iþlemleri
    int getNumberX() const;
    int getNumberY() const;

    void addGridSize(int x, int y);
    void setGridSize(int x, int y);
};
