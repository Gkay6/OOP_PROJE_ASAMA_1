#ifndef POSE_H
#define POSE_H

#include <cmath> // sqrt, atan2
#include <iostream>

class Pose {
private:
    double x;   // X koordinatı
    double y;   // Y koordinatı
    double th;  // Derece cinsinden yön açısı

public:
    // Constructor
    Pose(double _x = 0.0, double _y = 0.0, double _th = 0.0);

    // Getter ve Setter metotları
    double getX() const;
    void setX(double _x);

    double getY() const;
    void setY(double _y);

    double getTh() const;
    void setTh(double _th);

    // Operatör aşırı yükleme
    bool operator==(const Pose& other) const;
    Pose operator+(const Pose& other) const;
    Pose operator-(const Pose& other) const;
    Pose& operator+=(const Pose& other);
    Pose& operator-=(const Pose& other);
    bool operator<(const Pose& other) const;

    // Pozisyon ayarlama ve alma
    void setPose(double _x, double _y, double _th);
    void getPose(double& _x, double& _y, double& _th) const;

    // İki Pose arasındaki mesafe ve açı farkı
    double findDistanceTo(const Pose& pos) const;
    double findAngleTo(const Pose& pos) const;
};
#endif // POSE_H


