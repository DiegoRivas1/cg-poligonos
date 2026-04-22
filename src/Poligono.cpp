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

void Poligono::setRotacion(float x, float y, float z) {
    this->rotacion = glm::vec3(x, y, z);
}

void Poligono::addRotacion(float x, float y, float z) {
    this->rotacion += glm::vec3(x, y, z);
}

glm::mat4 Poligono::getModel() const {
    auto model = glm::mat4(1.f);//glm::mat4 model = glm::mat4(1.f); identidad
    model = glm::translate(model, this->posicion);
    model = glm::rotate(model, glm::radians(this->rotacion.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(this->rotacion.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(this->rotacion.z), glm::vec3(0.0f, 0.0f, 1.0f));
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
glm::vec3 Poligono::getRotacion() const { return rotacion; }
// convierte coordenadas de pantalla a NDC (-1 a 1)
bool Poligono::contienePunto(float px, float py, int anchoVentana, int altoVentana) const {
    // pantalla → NDC
    float nx =  (2.f * px / anchoVentana)  - 1.f;
    float ny = -(2.f * py / altoVentana) + 1.f;  // Y invertido

    // aplicar transformacion del poligono al punto
    glm::mat4 inv = glm::inverse(getModel());
    glm::vec4 punto = inv * glm::vec4(nx, ny, 0.f, 1.f);

    // ray casting 2D sobre vertices originales
    float x = punto.x, y = punto.y;
    bool dentro = false;
    unsigned int n = vertices.size();
    for (unsigned int i = 0, j = n - 1; i < n; j = i++) {
        float xi = vertices[i].getX(), yi = vertices[i].getY();
        float xj = vertices[j].getX(), yj = vertices[j].getY();
        if (((yi > y) != (yj > y)) &&
            (x < (xj - xi) * (y - yi) / (yj - yi) + xi))
            dentro = !dentro;
    }
    return dentro;
}