//
// Created by DIEGO on 20/04/2026.
//

#ifndef CG_PRUEBA_PUNTO_H
#define CG_PRUEBA_PUNTO_H
#include <iosfwd>
#include <ostream>

class Punto;
std::ostream& operator<<(std::ostream& os, const Punto& punto);
class Punto {
    private:
        float x;
        float y;
        float z;
    public:
        Punto();
        Punto(float x, float y);
        Punto(float x, float y, float z);
        ~Punto();

        [[nodiscard]] float getX() const;
        [[nodiscard]] float getY() const;
        [[nodiscard]] float getZ() const;
        friend std::ostream& operator<<(std::ostream& os, const Punto& punto);
        //friend class Triangulo;
        friend class PoligonoIrregular;
        friend class Poligono;

};

#endif //CG_PRUEBA_PUNTO_H