//
// Created by DIEGO on 21/04/2026.
//

#ifndef CG_PRUEBA_POLIGONOREGULAR_H
#define CG_PRUEBA_POLIGONOREGULAR_H
#include "Poligono.h"

class PoligonoRegular : public Poligono {
    public:
        explicit PoligonoRegular(const std::vector<Punto> &puntos);// p * apotema / 2
        [[nodiscard]] float area() const override; // n * l
        [[nodiscard]] float perimetro() const override;
        [[nodiscard]] float apotema() const;
        [[nodiscard]] float longitudLado() const;
        [[nodiscard]] unsigned int numVertices() const override;
        void dibujar() const override;
        void print(std::ostream &os) const override;

};

#endif //CG_PRUEBA_POLIGONOREGULAR_H