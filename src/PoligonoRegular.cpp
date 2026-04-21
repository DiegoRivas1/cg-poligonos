#include "PoligonoRegular.h"
#include <glad/glad.h>
#include <cmath>

#include "Shader.h"

PoligonoRegular::PoligonoRegular(const std::vector<Punto> &puntos) {
    this->vertices = puntos;
}

float PoligonoRegular::longitudLado() const {
    return PoligonoRegular::distancia(vertices[0], vertices[1]);
}

float PoligonoRegular::apotema() const {
    // a = l / (2 * tan(π/n))
    const unsigned int n = this->vertices.size();
    const float l = this->longitudLado();
    return l / (2.f * static_cast<float>(std::tan(M_PI / n)));
}

float PoligonoRegular::perimetro() const {
    return static_cast<float>(this->vertices.size()) * this->longitudLado();
}

float PoligonoRegular::area() const {
    return this->perimetro() * this->apotema() / 2.f;
}

unsigned int PoligonoRegular::numVertices() const {
    return static_cast<unsigned int>(this->vertices.size());
}

void PoligonoRegular::dibujar() const {
    glBegin(GL_POLYGON);
    for (const auto& v : this->vertices) {
        glVertex3f(v.x, v.y, v.z);
    }
    glEnd();
}

void PoligonoRegular::dibujar(const Shader &shader) const {
    if (!gpuListo) {
        subirGpu();
    }

    shader.usar();
    shader.setColor(0.8f, 0.2f, 0.2f); // rojo por ejemplo

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());
    glBindVertexArray(0);
}
void PoligonoRegular::subirGpu() const {
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    gpuListo = true;
}

void PoligonoRegular::print(std::ostream& os) const {
    os << "PoligonoRegular[vertices=" << numVertices()
       << ", lado="      << longitudLado()
       << ", apotema="   << apotema()
       << ", area="      << area()
       << ", perimetro=" << perimetro() << "]\n";
    for (const auto& v : vertices)
        os << "  " << v << "\n";
}
