//
// Created by DIEGO on 20/04/2026.
//
#include "PoligonoIrregular.h"
#include <glad/glad.h>
#include <cmath>

PoligonoIrregular::PoligonoIrregular(const std::vector<Punto> &puntos) {
    this -> vertices = puntos;
}

float PoligonoIrregular::area() const {
    float suma = 0.0f;
    unsigned int n = this->vertices.size();

    for (unsigned int i = 0; i < n; i++) {
        unsigned int j = (i + 1) % n;
        suma += vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y;
    }
    return std::abs(suma) / 2.0f;
}

float PoligonoIrregular::perimetro() const {
    float total = 0.0f;
    unsigned int n = this->vertices.size();
    for (unsigned int i = 0; i < n; i++) {
        unsigned int j = (i + 1) % n;
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

void PoligonoIrregular::subirGpu() const {
    std::vector<float> data;
    for (const auto &v : vertices) {
        data.push_back(v.x);
        data.push_back(v.y);
        data.push_back(v.z);
    }

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void *>(nullptr));
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    gpuListo = true;
}

void PoligonoIrregular::dibujar(const Shader &shader) const {
    if (!this->gpuListo) {
        this->subirGpu();
    }

    shader.usar();
    shader.setColor(0.2f, 0.8f, 0.4f);//// verde por defecto, luego lo parametrizamos
    shader.setMatrix("model", getModel());

    //GLenum err = glGetError();
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<int>(this->vertices.size()));
    glBindVertexArray(0);

}

void PoligonoIrregular::print(std::ostream &os) const {
    os << "PoligonIrregular[vectices=" << this->numVertices()
       << ", area=" << this->area()
       << ", perimetro=" << this->perimetro() << "]\n";

    for (const auto &v : vertices) {
        os << v;
    }
}



