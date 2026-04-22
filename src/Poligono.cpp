//
// Created by DIEGO on 20/04/2026.
//

#include "Poligono.h"
#include <cmath>

void Poligono::setPosicion(float x, float y, float z) {
    this->posicion = glm::vec3(x, y, z);
}

void Poligono::setEscala(float x, float y, float z) {
    this->escala = glm::vec3(x, y, z);
}

void Poligono::setRotacion(float grados) {
    this->rotacion = grados;
}

glm::mat4 Poligono::getModel() const {
    auto model = glm::mat4(1.f);//glm::mat4 model = glm::mat4(1.f); identidad
    model = glm::translate(model, this->posicion);
    model = glm::rotate(model, glm::radians(this->rotacion), glm::vec3(0.0f, 0.0f, 1.0f));//rotacion en z
    model = glm::scale(model, this->escala);
    return model;
}

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
