#include "Pose.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Constructor
Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}

// Getter ve Setter metotlar�
double Pose::getX() const { return x; }
void Pose::setX(double _x) { x = _x; }

double Pose::getY() const { return y; }
void Pose::setY(double _y) { y = _y; }

double Pose::getTh() const { return th; }
void Pose::setTh(double _th) { th = _th; }

// operator== : E�itlik kontrol�
bool Pose::operator==(const Pose& other) const {
    return x == other.x && y == other.y && th == other.th;
}

// operator+ : �ki Pose'u toplama
Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

// operator+= : Toplam� kendine atama
Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

// operator- : �ki Pose'u ��karma
Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

// operator-= : ��karmay� kendine atama
Pose& Pose::operator-=(const Pose& other) {
    x -= other.x;
    y -= other.y;
    th -= other.th;
    return *this;
}

// operator< : K���k kar��la�t�rma
bool Pose::operator<(const Pose& other) const {
    // (0, 0) noktas�na g�re mesafeyi kullanarak kar��la�t�rma
    double distanceThis = findDistanceTo(Pose(0.0, 0.0, 0.0));
    double distanceOther = other.findDistanceTo(Pose(0.0, 0.0, 0.0));
    return distanceThis < distanceOther;
}

// setPose : Pozisyon ayarlama
void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}

// getPose : Pozisyonu alma
void Pose::getPose(double& _x, double& _y, double& _th) const {
    _x = x;
    _y = y;
    _th = th;
}

// findDistanceTo : �ki Pose aras�ndaki mesafe
double Pose::findDistanceTo(const Pose& pos) const {
    return sqrt(pow(pos.x - x, 2) + pow(pos.y - y, 2));
}

// findAngleTo : �ki Pose aras�ndaki a�� fark�
double Pose::findAngleTo(const Pose& pos) const {
    return atan2(pos.y - y, pos.x - x) * 180.0 / M_PI; // Radyan� dereceye �evir
}

