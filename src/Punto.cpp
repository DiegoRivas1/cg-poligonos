//
// Created by DIEGO on 20/04/2026.
//

#include "Punto.h"

Punto::Punto() : x(0), y(0), z(0) {}

Punto::~Punto() = default;

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
