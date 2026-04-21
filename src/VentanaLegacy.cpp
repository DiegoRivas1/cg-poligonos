#include "VentanaLegacy.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

VentanaLegacy::VentanaLegacy(const std::string &titulo) : VentanaLegacy(800, 600, titulo) {}

VentanaLegacy::VentanaLegacy(int ancho, int alto, const std::string &titulo) : Ventana(ancho, alto) {
    VentanaLegacy::configurarContexto(); //hints antes de crear ventana
    this->inicializar(titulo);
}

void VentanaLegacy::configurarContexto() {
    ////2.1 -> OpenGL legacy, soporta glBegin/glEnd, glColor3f, sin shaders obligatorios
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
}

void VentanaLegacy::limpiar(float r, float g, float b) const {
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
