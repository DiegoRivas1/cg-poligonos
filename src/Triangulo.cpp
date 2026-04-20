//
// Created by DIEGO on 20/04/2026.
//
#include "Triangulo.h"
#include <glad/glad.h>
#include <cmath>

Triangulo::Triangulo(const Punto &p1, const Punto &p2, const Punto &p3) {
    this -> vertices = {p1, p2, p3};
}

float Triangulo::distancia(const Punto &p1, const Punto &p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float dz = p2.z - p1.z;

    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

//Formula de heron
float Triangulo::area() const {
    float a = distancia(vertices[1], vertices[2]);
    float b = distancia(vertices[0], vertices[2]);
    float c = distancia(vertices[0], vertices[1]);

    float s = (a + b + c) / 2.f;

    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

float Triangulo::perimetro() const {
    return distancia(vertices[0], vertices[1]) +
           distancia(vertices[1], vertices[2]) +
           distancia(vertices[2], vertices[0]);
}

unsigned int Triangulo::numVertices() const {
    return this -> vertices.size();//devuelve size_t (sin signo)
}

void Triangulo::dibujar() const {
    glBegin(GL_TRIANGLES);
        glVertex3f(vertices[0].x, vertices[0].y, vertices[0].z);
        glVertex3f(vertices[1].x, vertices[1].y, vertices[1].z);
        glVertex3f(vertices[2].x, vertices[2].y, vertices[2].z);
    glEnd();
}




