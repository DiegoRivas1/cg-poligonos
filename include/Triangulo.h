//
// Created by DIEGO on 20/04/2026.
//

#ifndef CG_PRUEBA_TRIANGULO_H
#define CG_PRUEBA_TRIANGULO_H
#include "Poligono.h"

class Triangulo:public Poligono {
    private:
        [[nodiscard]] float distancia(const Punto& p1, const Punto& p2) const;
    public:

};

#endif //CG_PRUEBA_TRIANGULO_H