#include <iostream>
#include <glad/glad.h>
#include "VentanaCore.h"
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
        VentanaCore ventana(800, 600, "Helpers Demo");
        Shader shader(vertexSrc, fragmentSrc);
        Camara camara(800.f, 600.f);

        // usando helpers no hay que calcular puntos a mano
        auto triangulo  = PoligonoFactory::crearTriangulo(
            Punto( 0.0f,  0.5f, 0.0f),
            Punto(-0.5f, -0.5f, 0.0f),
            Punto( 0.5f, -0.5f, 0.0f)
        );

        auto cuadrado   = PoligonoFactory::crearCuadrado(0.0f, 0.0f, 0.5f);
        auto hexagono   = PoligonoFactory::crearPoligonoRegular(6, 0.0f, 0.0f, 0.4f);
        auto pentagono  = PoligonoFactory::crearPoligonoRegular(5, 0.0f, 0.0f, 0.4f);

        triangulo->setPosicion(-0.6f,  0.5f, 0.f);
        cuadrado->setPosicion ( 0.6f,  0.5f, 0.f);
        hexagono->setPosicion (-0.6f, -0.5f, 0.f);
        pentagono->setPosicion( 0.6f, -0.5f, 0.f);

        camara.agregarPoligono(triangulo.get());
        camara.agregarPoligono(cuadrado.get());
        camara.agregarPoligono(hexagono.get());
        camara.agregarPoligono(pentagono.get());

        glfwSetCursorPosCallback(ventana.getVentana(), Camara::callbackMouse);
        glfwSetScrollCallback(ventana.getVentana(),    Camara::callbackScroll);

        while (!ventana.debeCerrar()) {
            ventana.procesarEntrada();
            ventana.limpiar(0.1f, 0.1f, 0.15f);

            shader.usar();
            shader.setMatrix("view",       camara.getView());
            shader.setMatrix("projection", camara.getProjection());

            triangulo->dibujar(shader);
            cuadrado->dibujar(shader);
            hexagono->dibujar(shader);
            pentagono->dibujar(shader);

            ventana.actualizar();
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}