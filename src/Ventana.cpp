//
// Created by DIEGO on 21/04/2026.
//
#include "Ventana.h"
#include <iostream>
#include <stdexcept>

Ventana::Ventana(const std::string &titulo) : Ventana(800, 600, titulo){}

Ventana::Ventana(int ancho, int alto, const std::string &titulo) : ventana(nullptr), ancho(ancho), alto(alto) {
    if (!glfwInit()) {
        throw std::invalid_argument("Fallo GLFW al iniciar");
    }

    // GLFW qué versión de OpenGL pedir al sistema operativo:
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); //2.1 -> OpenGL legacy, soporta glBegin/glEnd, glColor3f, sin shaders obligatorios
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    this->ventana = glfwCreateWindow(ancho, alto, titulo.c_str(), nullptr, nullptr);
    if (!this->ventana) {
        glfwTerminate();
            throw std::invalid_argument("No se pudo crear la ventana");
    }

    glfwMakeContextCurrent(this->ventana);
    glfwSetFramebufferSizeCallback(this->ventana, frameBufferSizeCallback);

    //reinterpret_cast GLFWglproc y GLADloadproc son dos tipos de punteros a función DIFERENTES con firmas distintas
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        glfwTerminate();
        throw std::invalid_argument("No se pudo iniciar GLAD");
    }
}

Ventana::~Ventana() {
    glfwTerminate();
}

bool Ventana::debeCerrar() const {
    return glfwWindowShouldClose(this->ventana);
}

void Ventana::limpiar(float r, float g, float b) {
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Ventana::actualizar() const {
    glfwSwapBuffers(this->ventana);
    glfwPollEvents();
}

void Ventana::procesarEntrada() const {
    if (glfwGetKey(this->ventana, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->ventana, true);
    }
}

GLFWwindow* Ventana::getVentana() const {
    return this->ventana;
}

void Ventana::frameBufferSizeCallback(GLFWwindow*, int ancho, int alto) {
    glViewport(0, 0, ancho, alto);
}