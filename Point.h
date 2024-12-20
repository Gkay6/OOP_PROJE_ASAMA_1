#pragma once
#include <iostream>  // Konsol çýktýsý için
#include <cmath>     // Matematiksel hesaplamalar için
#include <cassert>   // Hata kontrolü için (opsiyonel)

class POINT {
public:
    // Deðiþkenler
    double x;
    double y;

    // Constructor: Varsayýlan ve parametreli
    POINT(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

    // Getter ve Setter Fonksiyonlarý
    double getX() const;                     // X koordinatýný döner
    double getY() const;                     // Y koordinatýný döner
    void setX(double value);                 // X koordinatýný ayarlar
    void setY(double value);                 // Y koordinatýný ayarlar
    void setPoint(double _x, double _y);     // X ve Y koordinatýný ayarlar

    // Noktalar arasý iþlemler
    double findDistanceToPos(const POINT& p) const;  // Baþka bir noktaya olan uzaklýðý hesaplar
    double findAngleToPos(const POINT& p) const;     // Baþka bir noktaya olan açýyý hesaplar

    // Operatör aþýrý yüklemeleri
    bool operator==(const POINT& p) const;           // Nokta eþitliði karþýlaþtýrmasý
};

