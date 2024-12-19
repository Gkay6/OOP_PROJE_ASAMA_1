#pragma once
#include <iostream>  // Konsol ��kt�s� i�in
#include <cmath>     // Matematiksel hesaplamalar i�in
#include <cassert>   // Hata kontrol� i�in (opsiyonel)

class POINT {
public:
    // De�i�kenler
    double x;
    double y;

    // Constructor: Varsay�lan ve parametreli
    POINT(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

    // Getter ve Setter Fonksiyonlar�
    double getX() const;                     // X koordinat�n� d�ner
    double getY() const;                     // Y koordinat�n� d�ner
    void setX(double value);                 // X koordinat�n� ayarlar
    void setY(double value);                 // Y koordinat�n� ayarlar
    void setPoint(double _x, double _y);     // X ve Y koordinat�n� ayarlar

    // Noktalar aras� i�lemler
    double findDistanceToPos(const POINT& p) const;  // Ba�ka bir noktaya olan uzakl��� hesaplar
    double findAngleToPos(const POINT& p) const;     // Ba�ka bir noktaya olan a��y� hesaplar

    // Operat�r a��r� y�klemeleri
    bool operator==(const POINT& p) const;           // Nokta e�itli�i kar��la�t�rmas�
};

