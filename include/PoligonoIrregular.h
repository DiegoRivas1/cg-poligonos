//
// Created by DIEGO on 20/04/2026.
//

#ifndef CG_PRUEBA_POLIGONOIRREGULAR_H
#define CG_PRUEBA_POLIGONOIRREGULAR_H
#include "Poligono.h"
#include <iostream>
#include "Shader.h"
class PoligonoIrregular : public Poligono {
    private:
        //mutable unsigned int VAO = 0, VBO = 0;
        //mutable bool gpuListo = false;
        void subirGpu() const;
    public:
        explicit PoligonoIrregular(const std::vector<Punto>& puntos);

        [[nodiscard]] float area() const override;
        [[nodiscard]] float perimetro() const override;
        void dibujar() const override;
        void dibujar(const Shader &shader) const override;
        [[nodiscard]] unsigned int numVertices() const override;
        void print(std::ostream &os) const override;

};

#endif //CG_PRUEBA_POLIGONOIRREGULAR_H