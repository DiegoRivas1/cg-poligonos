#include "VentanaCore.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

VentanaCore::VentanaCore(const std::string &titulo) : VentanaCore(800, 600, titulo) {
}

VentanaCore::VentanaCore(int ancho, int alto, const std::string &titulo) : Ventana(ancho, alto) {
    VentanaCore::configurarContexto(); //hints antesa de crear la ventana
    this->inicializar(titulo);
}

void VentanaCore::configurarContexto() {
    //4.0 -> OpenGL moderno (core profile), glBegin/glEnd no existe, todo debe hacerse con shaders, VAOs, VBOs
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void VentanaCore::limpiar(float r, float g, float b) const {
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
