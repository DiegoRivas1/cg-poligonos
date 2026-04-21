#include <iostream>
#include <glad/glad.h>
#include "VentanaLegacy.h"
#include "Punto.h"
#include "PoligonoFactory.h"

int main() {
    try {
        VentanaLegacy ventana(800, 600, "Legacy 2D");

        auto poligono = PoligonoFactory::crear({
            Punto( 0.0f,  0.5f),
            Punto(-0.5f, -0.5f),
            Punto( 0.5f, -0.5f)
        });

        while (!ventana.debeCerrar()) {
            glfwMakeContextCurrent(ventana.getVentana());

            ventana.procesarEntrada();
            ventana.limpiar(0.1f, 0.1f, 0.15f);

            glColor3f(0.2f, 0.8f, 0.4f);
            poligono->dibujar();

            ventana.actualizar();
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    glfwTerminate();
    return 0;
}