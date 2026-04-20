//
// Created by DIEGO on 20/04/2026.
//

#ifndef CG_PRUEBA_TRIANGULO_H
#define CG_PRUEBA_TRIANGULO_H
#include "Poligono.h"

class Triangulo:public Poligono {
    private:
        [[nodiscard]] static float distancia(const Punto& p1, const Punto& p2);
    public:
        Triangulo(const Punto& p1, const Punto& p2, const Punto& p3);
        [[nodiscard]] float area() const override;
        [[nodiscard]] float perimetro() const override;
        void dibujar() const override;
        [[nodiscard]] unsigned int numVertices() const override;

};

#endif //CG_PRUEBA_TRIANGULO_H