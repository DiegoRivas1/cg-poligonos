//
// Created by DIEGO on 20/04/2026.
//

#ifndef CG_PRUEBA_TRIANGULO_H
#define CG_PRUEBA_TRIANGULO_H
#include "PoligonoIrregular.h"

class Triangulo:public PoligonoIrregular {
    public:
        Triangulo(const Punto& a, const Punto& b, const Punto& c);
};

#endif //CG_PRUEBA_TRIANGULO_H