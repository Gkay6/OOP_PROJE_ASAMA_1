#include "MAP.h"

// Constructor: Grid boyutlar�n� ayarlar ve t�m gridlere 0 de�eri atar
MAP::MAP(int x, int y) : gridNumberX(x), gridNumberY(y) {
    grid.resize(gridNumberY, std::vector<int>(gridNumberX, 0));
}

// Noktan�n grid �zerindeki koordinat�na 1 de�eri atan�r
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

// Griddeki de�eri d�ner
int MAP::getGrid(int x, int y) const {
    assert(x >= 0 && x < gridNumberX && y >= 0 && y < gridNumberY);
    return grid[y][x];
}

// Belirtilen indekse de�er atar
void MAP::setGrid(int x, int y, int value) {
    assert(x >= 0 && x < gridNumberX && y >= 0 && y < gridNumberY);
    grid[y][x] = value;
}

// T�m gridleri 0 de�erine s�f�rlar
void MAP::clearMap() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

// Harita bilgilerini ekrana bast�r�r
void MAP::printInfo() const {
    std::cout << "Grid Size: " << gridNumberX << " x " << gridNumberY << "\n";
    std::cout << "Total Grid Number: " << gridNumberX * gridNumberY << "\n";
}

// Grid'i ekrana bast�r�r
void MAP::showMap() const {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell == 0 ? "." : "x") << " ";
        }
        std::cout << "\n";
    }
}

// X eksenindeki grid say�s�n� d�ner
int MAP::getNumberX() const {
    return gridNumberX;
}

// Y eksenindeki grid say�s�n� d�ner
int MAP::getNumberY() const {
    return gridNumberY;
}

// Grid boyutlar�n� b�y�t�r (yeni boyut ekler)
void MAP::addGridSize(int x, int y) {
    gridNumberX += x;
    gridNumberY += y;
    grid.resize(gridNumberY, std::vector<int>(gridNumberX, 0));
}

// Grid boyutlar�n� yeniden ayarlar
void MAP::setGridSize(int x, int y) {
    gridNumberX = x;
    gridNumberY = y;
    grid.assign(gridNumberY, std::vector<int>(gridNumberX, 0));
}
