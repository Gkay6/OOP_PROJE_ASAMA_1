#include "Pose.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Constructor
Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}

// Getter ve Setter metotlarý
double Pose::getX() const { return x; }
void Pose::setX(double _x) { x = _x; }

double Pose::getY() const { return y; }
void Pose::setY(double _y) { y = _y; }

double Pose::getTh() const { return th; }
void Pose::setTh(double _th) { th = _th; }

// operator== : Eþitlik kontrolü
bool Pose::operator==(const Pose& other) const {
    return x == other.x && y == other.y && th == other.th;
}

// operator+ : Ýki Pose'u toplama
Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

// operator+= : Toplamý kendine atama
Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

// operator- : Ýki Pose'u çýkarma
Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

// operator-= : Çýkarmayý kendine atama
Pose& Pose::operator-=(const Pose& other) {
    x -= other.x;
    y -= other.y;
    th -= other.th;
    return *this;
}

// operator< : Küçük karþýlaþtýrma
bool Pose::operator<(const Pose& other) const {
    // (0, 0) noktasýna göre mesafeyi kullanarak karþýlaþtýrma
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

// findDistanceTo : Ýki Pose arasýndaki mesafe
double Pose::findDistanceTo(const Pose& pos) const {
    return sqrt(pow(pos.x - x, 2) + pow(pos.y - y, 2));
}

// findAngleTo : Ýki Pose arasýndaki açý farký
double Pose::findAngleTo(const Pose& pos) const {
    return atan2(pos.y - y, pos.x - x) * 180.0 / M_PI; // Radyaný dereceye çevir
}

