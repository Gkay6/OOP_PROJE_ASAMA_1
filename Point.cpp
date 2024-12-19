#include "POINT.h"

// Getter fonksiyonlarý
double POINT::getX() const {
    return x;
}

double POINT::getY() const {
    return y;
}

// Setter fonksiyonlarý
void POINT::setX(double value) {
    x = value;
}

void POINT::setY(double value) {
    y = value;
}

void POINT::setPoint(double _x, double _y) {
    x = _x;
    y = _y;
}

// Ýki nokta arasýndaki uzaklýðý hesaplar
double POINT::findDistanceToPos(const POINT& p) const {
    return std::sqrt(std::pow(p.x - x, 2) + std::pow(p.y - y, 2));
}

// Ýki nokta arasýndaki açýyý hesaplar (radyan cinsinden)
double POINT::findAngleToPos(const POINT& p) const {
    return std::atan2(p.y - y, p.x - x);
}

// Operatör aþýrý yüklemesi: Eþitlik kontrolü
bool POINT::operator==(const POINT& p) const {
    return (x == p.x) && (y == p.y);
}
