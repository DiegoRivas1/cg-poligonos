#include <iostream>
#include "Ventana.h"
#include "PoligonoFactory.h"

int main() {
    try {
        Ventana ventana(800, 600, "Poligonos");

        auto triangulo = PoligonoFactory::crear({
            Punto( 0.0f,  0.5f),
            Punto(-0.5f, -0.5f),
            Punto( 0.5f, -0.5f)
        });

        while (!ventana.debeCerrar()) {
            ventana.procesarEntrada();
            Ventana::limpiar(0.1f, 0.1f, 0.15f);

            glColor3f(0.2f, 0.8f, 0.4f);
            triangulo->dibujar();

            std::cout << *triangulo << std::endl;
            ventana.actualizar();
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}