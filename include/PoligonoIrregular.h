//
// Created by DIEGO on 20/04/2026.
//

#ifndef CG_PRUEBA_POLIGONOIRREGULAR_H
#define CG_PRUEBA_POLIGONOIRREGULAR_H
#include "Poligono.h"

class PoligonoIrregular : public Poligono {
    protected:
        [[nodiscard]] static float distancia(const Punto& a, const Punto& b);
    public:
        explicit PoligonoIrregular(const std::vector<Punto>& puntos);

        [[nodiscard]] float area() const override;
        [[nodiscard]] float perimetro() const override;
        void  dibujar() const override;
        [[nodiscard]] unsigned int numVertices() const override;

};

#endif //CG_PRUEBA_POLIGONOIRREGULAR_H