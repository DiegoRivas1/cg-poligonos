#include <iostream>
#include <glad/glad.h>
#include "VentanaCore.h"
#include "Punto.h"
#include "PoligonoFactory.h"
#include "Shader.h"

const char* vertexSrc = R"(
    #version 460 core
    layout(location = 0) in vec2 aPos;
    void main() {
        gl_Position = vec4(aPos, 0.0, 1.0);
    }
)";

const char* fragmentSrc = R"(
    #version 460 core
    uniform vec4 uColor;
    out vec4 FragColor;
    void main() {
        FragColor = uColor;
    }
)";

int main() {
    try {
        VentanaCore ventana(800, 600, "Core 2D");

        //glfwMakeContextCurrent(ventana.getVentana());
        Shader shader(vertexSrc, fragmentSrc);

        auto poligono1 = PoligonoFactory::crear({
            Punto( 0.0f,  0.5f),
            Punto(-0.5f, -0.5f),
            Punto( 0.5f, -0.5f)
        });

        auto poligono2 = PoligonoFactory::crear({
            Punto(-0.7f,  0.7f),
            Punto(-0.2f,  0.7f),
            Punto(-0.2f,  0.2f),
            Punto(-0.7f,  0.2f)
        });

        while (!ventana.debeCerrar()) {
            ventana.procesarEntrada();
            ventana.limpiar(0.1f, 0.1f, 0.15f);

            poligono1->dibujar(shader);
            poligono2->dibujar(shader);

            ventana.actualizar();
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    glfwTerminate();
    return 0;
}