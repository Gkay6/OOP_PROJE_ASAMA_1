#include "MAP.h"
#include <iostream>

// Constructor: Grid boyutlarýný ayarlar ve tüm gridlere 0 deðeri atar
MAP::MAP(int x, int y) : gridNumberX(x), gridNumberY(y) {
    grid = new int* [gridNumberY];
    for (int i = 0; i < gridNumberY; ++i) {
        grid[i] = new int[gridNumberX];
        // Her bir satýrdaki tüm elemanlarý sýfýrla
        for (int j = 0; j < gridNumberX; ++j) {
            grid[i][j] = 0;
        }
    }
}


// Destructor: Dinamik bellek temizliði
MAP::~MAP() {
    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

// Noktanýn grid üzerindeki koordinatýna 1 deðeri atanýr
void MAP::insertPoint(const POINT& point) {
    int gridX = static_cast<int>(point.getX());
    int gridY = static_cast<int>(point.getY());

    if (gridX >= 0 && gridX < gridNumberX && gridY >= 0 && gridY < gridNumberY) {
        grid[gridY][gridX] = 1; // Doðru eriþim
    } else {
        std::cerr << "Error: The point is not in the area!\n";
    }
}

// Griddeki deðeri döner
int MAP::getGrid(int x, int y) const {
    if (x < 0 || y < 0 || x >= gridNumberX || y >= gridNumberY) {
        std::cerr << "Error: Invalid grid coordinates (" << x << ", " << y << ")." << std::endl;
        return -1; // Geçersiz indeks için hata kodu döndürülüyor
    }
    return grid[y][x]; // Doðru eriþim
}


// Belirtilen indekse deðer atar
void MAP::setGrid(int x, int y, int value) {
    if (x < 0 || y < 0 || x >= gridNumberX || y >= gridNumberY) {
        std::cerr << "Error: Invalid grid coordinates (" << x << ", " << y << ")." << std::endl;
        return; // Geçersiz indeks durumunda hiçbir iþlem yapmýyor
    }
    grid[y][x] = value; // Doðru eriþim
}


// Tüm gridleri 0 deðerine sýfýrlar
void MAP::clearMap() {
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            grid[i][j] = 0; // Doðru eriþim
        }
    }
}

// Harita bilgilerini ekrana bastýrýr
void MAP::printInfo() const {
    std::cout << "Grid Size: " << gridNumberX << " x " << gridNumberY << "\n";
    std::cout << "Total Grid Number: " << gridNumberX * gridNumberY << "\n";
}

// Grid'i ekrana bastýrýr
void MAP::showMap() const {
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            std::cout << (grid[i][j] == 0 ? "." : "x") << " "; // Doðru eriþim
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
void MAP::addGridSize(int x, int y) {
    if (x < 0 || y < 0 ) {
        std::cerr << "Error: Invalid values." << std::endl;
        return; // Geçersiz indeks durumunda hiçbir iþlem yapmýyor
    }
    // Mevcut grid boyutlarýný al

    // Yeni grid boyutlarýný hesapla
    int newGridNumberX = gridNumberX + x;
    int newGridNumberY = gridNumberY + y;

    // Yeni grid için bellek tahsis et
    int** newGrid = new int* [newGridNumberY];
    for (int i = 0; i < newGridNumberY; ++i) {
        newGrid[i] = new int[newGridNumberX] {0}; // Yeni grid için 0'larla baþlatma
    }

    // Eski grid verilerini yeni grid'e kopyala
    for (int i = 0; i < gridNumberY; ++i) {
        for (int j = 0; j < gridNumberX; ++j) {
            newGrid[i][j] = grid[i][j]; // Eski veriyi yeni grid'e aktar
        }
    }

    // Eski grid'i temizle
    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i]; // Eski grid'deki her satýrý serbest býrak
    }
    delete[] grid; // Eski grid'in kendisini serbest býrak

    // Yeni grid'i ata
    grid = newGrid;

    // Grid boyutlarýný güncelle
    setGridSize(newGridNumberX, newGridNumberY);
}

// Grid boyutlarýný yeniden ayarlar
void MAP::setGridSize(int x, int y) {
    if (x < 0 || y < 0) {
        std::cerr << "Error: Invalid values." << std::endl;
        return; // Geçersiz indeks durumunda hiçbir iþlem yapmýyor
    }
    // Eski grid'i temizle
    for (int i = 0; i < gridNumberY; ++i) {
        delete[] grid[i];
    }
    delete[] grid;

    // Yeni grid'i oluþtur
    gridNumberX = x;
    gridNumberY = y;
    grid = new int*[gridNumberY];
    for (int i = 0; i < gridNumberY; ++i) {
        grid[i] = new int[gridNumberX]{0};
    }
}
