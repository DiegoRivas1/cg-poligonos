#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Triangulo.h"

static const int WIDTH = 800;
static const int HEIGHT = 600;

void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

int main() {
    if (!glfwInit()) {
        std::cerr << "No se pudo iniciar glfw"<<std::endl;
        return -1;
    }

    //Pedimos contexto
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Traingulo", nullptr, nullptr);

    if (!window) {
        std::cerr << "Error al crear ventana"<<std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "No se pudo iniciar glad"<<std::endl;
        return -1;
    }

    //Traingulo  centrado en pantalla
    Triangulo tri(
        Punto(0.0f, 0.5f, 0.0f), // arriba
        Punto(-0.5f, -0.5f, 0.0f), //abajo-izqrieda
        Punto(0.5f, -0.5f, 0.0f) //abajo-derecha
    );

    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.2f, 0.8f, 0.4f);
        tri.dibujar();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void frameBufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}




