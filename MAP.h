#pragma once
#include <iostream>
#include "Point.h"

class MAP {
private:
    int gridNumberX; // X eksenindeki grid sayısı
    int gridNumberY; // Y eksenindeki grid sayısı
    int** grid;      // 2D grid (0: boş, 1: dolu)

public:
    // Constructor ve Destructor
    MAP(int x = 10, int y = 10);
    ~MAP();

    // Nokta ekleme
    void insertPoint(const Point& point);

    // Getter ve Setter
    int getGrid(int x, int y) const;
    void setGrid(int x, int y, int value);

    // Harita işlemleri
    void clearMap(); //map temizleme
    void printInfo() const; // bilgileri döndürme
    void showMap() const; //map konsola yazdırma

    // Grid boyut işlemleri
    int getNumberX() const;
    int getNumberY() const;

    void addGridSize(int x, int y); // grid büyütme
    void setGridSize(int x, int y); // grid boyutunu güncelleme
};
