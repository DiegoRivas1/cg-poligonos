#include <iostream>
#include <glad/glad.h>
#include "VentanaLegacy.h"
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
        // ── Ventana Legacy — triángulo isósceles irregular ────────────
        VentanaLegacy ventanaLegacy(800, 600, "Irregular - Legacy");

        auto irregular = PoligonoFactory::crear({
            Punto( 0.0f,  0.5f),
            Punto(-0.5f, -0.5f),
            Punto( 0.5f, -0.5f)
        });

        // ── Ventana Core — cuadrado regular ───────────────────────────
        VentanaCore ventanaCore(800, 600, "Regular - Core");

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


        // ── Loop principal ────────────────────────────────────────────
        while (!ventanaLegacy.debeCerrar() && !ventanaCore.debeCerrar()) {

            // Legacy
            glfwMakeContextCurrent(ventanaLegacy.getVentana());

            ventanaLegacy.procesarEntrada();
            ventanaLegacy.limpiar(0.1f, 0.1f, 0.15f);
            glColor3f(0.2f, 0.8f, 0.4f);
            irregular->dibujar();
            ventanaLegacy.actualizar();

            // Core
            glfwMakeContextCurrent(ventanaCore.getVentana());
            ventanaCore.procesarEntrada();
            ventanaCore.limpiar(0.15f, 0.1f, 0.1f);
            poligono1->dibujar(shader);
            poligono2->dibujar(shader);
            ventanaCore.actualizar();
        }


    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    //glfwTerminate();
    return 0;
}