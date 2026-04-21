#include "PoligonoRegular.h"
#include <glad/glad.h>
#include <cmath>

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
void PoligonoRegular::print(std::ostream& os) const {
    os << "PoligonoRegular[vertices=" << numVertices()
       << ", lado="      << longitudLado()
       << ", apotema="   << apotema()
       << ", area="      << area()
       << ", perimetro=" << perimetro() << "]\n";
    for (const auto& v : vertices)
        os << "  " << v << "\n";
}
