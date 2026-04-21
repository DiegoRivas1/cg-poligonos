//
// Created by DIEGO on 20/04/2026.
//

#include "Poligono.h"
#include <cmath>

float Poligono::distancia(const Punto &a, const Punto &b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

void Poligono::dibujar(const Shader &shader) const {

}

const std::vector<Punto>& Poligono::getVertices() const {
    return vertices;
}

std::ostream& operator<<(std::ostream& os, const Poligono& p) {
    p.print(os);
    return os;
}
