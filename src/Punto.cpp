//
// Created by DIEGO on 20/04/2026.
//

#include "Punto.h"

Punto::Punto() : x(0.0f), y(0.0f), z(0.0f) {}

Punto::~Punto() = default;

Punto::Punto(float x, float y) : x(x), y(y), z(0.0f) {}

Punto::Punto(float x, float y, float z) : x(x), y(y), z(z) {}

float Punto::getX() const {
    return this -> x;
}
float Punto::getY() const {
    return this -> y;
}
float Punto::getZ() const {
    return this -> z;
}

std::ostream& operator<<(std::ostream& os, const Punto& p) {
    if (p.z == 0.f)
        os << "(" << p.x << ", " << p.y << ")";
    else
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
}