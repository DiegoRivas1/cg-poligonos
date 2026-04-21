//
// Created by DIEGO on 20/04/2026.
//
#include "PoligonoIrregular.h"
#include <glad/glad.h>
#include <cmath>

PoligonoIrregular::PoligonoIrregular(const std::vector<Punto> &puntos) {
    this -> vertices = puntos;
}

float PoligonoIrregular::distancia(const Punto &a, const Punto &b) {
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    float dz = b.z - a.z;

    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

float PoligonoIrregular::area() const {
    float suma = 0.0f;
    unsigned int n = this->vertices.size();

    for (int i = 0; i < n; i++) {
        int  j = (i + 1) % n;
        suma += vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y;
    }
    return std::abs(suma) / 2.0f;
}

float PoligonoIrregular::perimetro() const {
    float total = 0.0f;
    int n = this->vertices.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        total += distancia(vertices[i], vertices[j]);
    }
    return total;
}

unsigned int PoligonoIrregular::numVertices() const {
    return this->vertices.size();
}

void PoligonoIrregular::dibujar() const {
    glBegin(GL_POLYGON);
    for (const auto &v : vertices) {
        glVertex3f(v.x, v.y, v.z);
    }
    glEnd();
}
