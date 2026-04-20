//
// Created by DIEGO on 20/04/2026.
//

#ifndef CG_PRUEBA_POLIGONO_H
#define CG_PRUEBA_POLIGONO_H

#pragma once
#include <vector>
#include "Punto.h"

class Poligono {
    protected:
        std::vector<Punto> vertices;

    public:
        virtual ~Poligono() = default;

        [[nodiscard]] virtual float area() const = 0;
        [[nodiscard]] virtual float perimetro() const = 0;
        virtual void dibujar() const = 0;          // cada figura decidira como se dibuja
        [[nodiscard]] virtual unsigned int numVertices() const = 0;

        [[nodiscard]] const std::vector<Punto>& getVertices() const;
};

#endif //CG_PRUEBA_POLIGONO_H