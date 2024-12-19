#include "MAP.h"

// Constructor: Grid boyutlarýný ayarlar ve tüm gridlere 0 deðeri atar
MAP::MAP(int x, int y) : gridNumberX(x), gridNumberY(y) {
    grid.resize(gridNumberY, std::vector<int>(gridNumberX, 0));
}

// Noktanýn grid üzerindeki koordinatýna 1 deðeri atanýr
void MAP::insertPoint(const POINT& point) {
    int gridX = static_cast<int>(point.getX());
    int gridY = static_cast<int>(point.getY());

    if (gridX >= 0 && gridX < gridNumberX && gridY >= 0 && gridY < gridNumberY) {
        grid[gridY][gridX] = 1;
    }
    else {
        std::cerr << "Error: The point not in the area!\n";
    }
}

// Griddeki deðeri döner
int MAP::getGrid(int x, int y) const {
    assert(x >= 0 && x < gridNumberX && y >= 0 && y < gridNumberY);
    return grid[y][x];
}

// Belirtilen indekse deðer atar
void MAP::setGrid(int x, int y, int value) {
    assert(x >= 0 && x < gridNumberX && y >= 0 && y < gridNumberY);
    grid[y][x] = value;
}

// Tüm gridleri 0 deðerine sýfýrlar
void MAP::clearMap() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

// Harita bilgilerini ekrana bastýrýr
void MAP::printInfo() const {
    std::cout << "Grid Size: " << gridNumberX << " x " << gridNumberY << "\n";
    std::cout << "Total Grid Number: " << gridNumberX * gridNumberY << "\n";
}

// Grid'i ekrana bastýrýr
void MAP::showMap() const {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell == 0 ? "." : "x") << " ";
        }
        std::cout << "\n";
    }
}

// X eksenindeki grid sayýsýný döner
int MAP::getNumberX() const {
    return gridNumberX;
}

// Y eksenindeki grid sayýsýný döner
int MAP::getNumberY() const {
    return gridNumberY;
}

// Grid boyutlarýný büyütür (yeni boyut ekler)
void MAP::addGridSize(int x, int y) {
    gridNumberX += x;
    gridNumberY += y;
    grid.resize(gridNumberY, std::vector<int>(gridNumberX, 0));
}

// Grid boyutlarýný yeniden ayarlar
void MAP::setGridSize(int x, int y) {
    gridNumberX = x;
    gridNumberY = y;
    grid.assign(gridNumberY, std::vector<int>(gridNumberX, 0));
}
