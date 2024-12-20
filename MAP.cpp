#include "MAP.h"
#include <iostream>

// Constructor: Grid boyutlar�n� ayarlar ve t�m gridlere 0 de�eri atar
MAP::MAP(int x, int y) : gridNumberX(x), gridNumberY(y) {
    grid = new int* [gridNumberY];
    for (int i = 0; i < gridNumberY; ++i) {
        grid[i] = new int[gridNumberX];
        // Her bir sat�rdaki t�m elemanlar� s�f�rla
        for (int j = 0; j < gridNumberX; ++j) {
            grid[i][j] = 0;
        }
    }
}


// Destructor: Dinamik bellek temizli�i
MAP::~MAP() {
    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

// Noktan�n grid �zerindeki koordinat�na 1 de�eri atan�r
void MAP::insertPoint(const POINT& point) {
    int gridX = static_cast<int>(point.getX());
    int gridY = static_cast<int>(point.getY());

    if (gridX >= 0 && gridX < gridNumberX && gridY >= 0 && gridY < gridNumberY) {
        grid[gridY][gridX] = 1; // Do�ru eri�im
    } else {
        std::cerr << "Error: The point is not in the area!\n";
    }
}

// Griddeki de�eri d�ner
int MAP::getGrid(int x, int y) const {
    if (x < 0 || y < 0 || x >= gridNumberX || y >= gridNumberY) {
        std::cerr << "Error: Invalid grid coordinates (" << x << ", " << y << ")." << std::endl;
        return -1; // Ge�ersiz indeks i�in hata kodu d�nd�r�l�yor
    }
    return grid[y][x]; // Do�ru eri�im
}


// Belirtilen indekse de�er atar
void MAP::setGrid(int x, int y, int value) {
    if (x < 0 || y < 0 || x >= gridNumberX || y >= gridNumberY) {
        std::cerr << "Error: Invalid grid coordinates (" << x << ", " << y << ")." << std::endl;
        return; // Ge�ersiz indeks durumunda hi�bir i�lem yapm�yor
    }
    grid[y][x] = value; // Do�ru eri�im
}


// T�m gridleri 0 de�erine s�f�rlar
void MAP::clearMap() {
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            grid[i][j] = 0; // Do�ru eri�im
        }
    }
}

// Harita bilgilerini ekrana bast�r�r
void MAP::printInfo() const {
    std::cout << "Grid Size: " << gridNumberX << " x " << gridNumberY << "\n";
    std::cout << "Total Grid Number: " << gridNumberX * gridNumberY << "\n";
}

// Grid'i ekrana bast�r�r
void MAP::showMap() const {
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            std::cout << (grid[i][j] == 0 ? "." : "x") << " "; // Do�ru eri�im
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
void MAP::addGridSize(int x, int y) {
    if (x < 0 || y < 0 ) {
        std::cerr << "Error: Invalid values." << std::endl;
        return; // Ge�ersiz indeks durumunda hi�bir i�lem yapm�yor
    }
    // Mevcut grid boyutlar�n� al

    // Yeni grid boyutlar�n� hesapla
    int newGridNumberX = gridNumberX + x;
    int newGridNumberY = gridNumberY + y;

    // Yeni grid i�in bellek tahsis et
    int** newGrid = new int* [newGridNumberY];
    for (int i = 0; i < newGridNumberY; ++i) {
        newGrid[i] = new int[newGridNumberX] {0}; // Yeni grid i�in 0'larla ba�latma
    }

    // Eski grid verilerini yeni grid'e kopyala
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            newGrid[i][j] = grid[i][j]; // Eski veriyi yeni grid'e aktar
        }
    }

    // Eski grid'i temizle
    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i]; // Eski grid'deki her sat�r� serbest b�rak
    }
    delete[] grid; // Eski grid'in kendisini serbest b�rak

    // Yeni grid'i ata
    grid = newGrid;

    // Grid boyutlar�n� g�ncelle
    setGridSize(newGridNumberX, newGridNumberY);
}

// Grid boyutlar�n� yeniden ayarlar
void MAP::setGridSize(int x, int y) {
    if (x < 0 || y < 0) {
        std::cerr << "Error: Invalid values." << std::endl;
        return; // Ge�ersiz indeks durumunda hi�bir i�lem yapm�yor
    }
    // Eski grid'i temizle
    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i];
    }
    delete[] grid;

    // Yeni grid'i olu�tur
    gridNumberX = x;
    gridNumberY = y;
    grid = new int*[gridNumberY];
    for (int i = 0; i < gridNumberY; ++i) {
        grid[i] = new int[gridNumberX]{0};
    }
}
