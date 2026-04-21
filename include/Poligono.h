//
// Created by DIEGO on 20/04/2026.
//

#ifndef CG_PRUEBA_POLIGONO_H
#define CG_PRUEBA_POLIGONO_H

#pragma once
#include <vector>
#include <ostream>
#include "Punto.h"

class Poligono;
std::ostream& operator<<(std::ostream& os, const Poligono& punto);

class Poligono {
    protected:
        std::vector<Punto> vertices;
        [[nodiscard]] static float distancia(const Punto& a, const Punto& b);
    public:
        virtual ~Poligono() = default;

        [[nodiscard]] virtual float area() const = 0;
        [[nodiscard]] virtual float perimetro() const = 0;
        virtual void dibujar() const = 0;          // cada figura decidira como se dibuja
        [[nodiscard]] virtual unsigned int numVertices() const = 0;

        //Cada hijo definia como se imprimira
        virtual void print(std::ostream& os) const = 0;
        [[nodiscard]] const std::vector<Punto>& getVertices() const;

        //
        friend std::ostream& operator<<(std::ostream& os, const Poligono& p);
};

#endif //CG_PRUEBA_POLIGONO_H