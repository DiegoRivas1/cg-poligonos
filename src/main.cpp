#include <iostream>
#include <glad/glad.h>
#include "VentanaCore.h"
#include "Punto.h"
#include "PoligonoFactory.h"
#include "Shader.h"
#include "Camara.h"

const char* vertexSrc = R"(
    #version 460 core
    layout(location = 0) in vec3 aPos;
    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;
    void main() {
        gl_Position = projection * view * model * vec4(aPos, 1.0);
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
        VentanaCore ventana(800, 600, "Core 3D");
        Shader shader(vertexSrc, fragmentSrc);
        Camara camara(800.f, 600.f);

        auto poligono1 = PoligonoFactory::crear({
            Punto( 0.0f,  0.5f,  0.5f),
            Punto(-0.5f, -0.5f,  -0.5f),
            Punto( 0.5f, -0.5f,  0.0f)
        });

        auto poligono2 = PoligonoFactory::crear({
            Punto(-0.5f,  0.5f,  0.0f),
            Punto( 0.5f,  0.5f,  0.0f),
            Punto( 0.5f, -0.5f,  0.0f),
            Punto(-0.5f, -0.5f,  0.0f)
        });

        poligono1->setPosicion( 0.6f, 0.f, 0.f);
        poligono2->setPosicion(-0.6f, 0.f, 0.f);

        while (!ventana.debeCerrar()) {
            ventana.procesarEntrada();
            ventana.limpiar(0.1f, 0.1f, 0.15f);

            shader.usar();
            shader.setMatrix("view",       camara.getView());
            shader.setMatrix("projection", camara.getProjection());

            poligono1->dibujar(shader);
            poligono2->dibujar(shader);

            ventana.actualizar();
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}