#include "POINT.h"

// Getter fonksiyonlar�
double POINT::getX() const {
    return x;
}

double POINT::getY() const {
    return y;
}

// Setter fonksiyonlar�
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

// �ki nokta aras�ndaki uzakl��� hesaplar
double POINT::findDistanceToPos(const POINT& p) const {
    return std::sqrt(std::pow(p.x - x, 2) + std::pow(p.y - y, 2));
}

// �ki nokta aras�ndaki a��y� hesaplar (radyan cinsinden)
double POINT::findAngleToPos(const POINT& p) const {
    return std::atan2(p.y - y, p.x - x);
}

// Operat�r a��r� y�klemesi: E�itlik kontrol�
bool POINT::operator==(const POINT& p) const {
    return (x == p.x) && (y == p.y);
}
