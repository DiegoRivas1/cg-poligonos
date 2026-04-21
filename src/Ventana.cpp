//
// Created by DIEGO on 21/04/2026.
//
#include "Ventana.h"
#include <iostream>
#include <stdexcept>

Ventana::Ventana() : Ventana(800, 600){}

Ventana::Ventana(int ancho, int alto) : ventana(nullptr), ancho(ancho), alto(alto) {
    if (!glfwInit()) {
        throw std::invalid_argument("Fallo GLFW al iniciar");
    }

    // GLFW qué versión de OpenGL pedir al sistema operativo:
    //Ventana::configurarContexto();
    //this->inicializar("dassda");

}

void Ventana::inicializar(const std::string & titulo) {
    this->ventana = glfwCreateWindow(ancho, alto, titulo.c_str(), nullptr, nullptr);
    if (!this->ventana) {
        glfwTerminate();
        throw std::invalid_argument("Fallo GLFW al iniciar ventana");
    }

    glfwMakeContextCurrent(ventana);
    glfwSetFramebufferSizeCallback(this->ventana, frameBufferSizeCallback);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        glfwTerminate();
        throw std::runtime_error("Fallo glad al iniciar ventana");
    }
}

Ventana::~Ventana() {
    glfwTerminate();
}

bool Ventana::debeCerrar() const {
    return glfwWindowShouldClose(this->ventana);
}

void Ventana::actualizar() const {
    glfwSwapBuffers(this->ventana);
    glfwPollEvents();
}

void Ventana::procesarEntrada() const {
    //glfwMakeContextCurrent(this->ventana);//Por si se  usa varias varias ventanas al mimsmo  tiempo
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