//
// Created by DIEGO on 21/04/2026.
//

#ifndef CG_PRUEBA_POLIGONOFACTORY_H
#define CG_PRUEBA_POLIGONOFACTORY_H
#include <memory>
#include <vector>
#include "Poligono.h"
#include "Punto.h"

class PoligonoFactory {
    private:
        static bool esRegular(const std::vector<Punto>& puntos);
        static constexpr float TOLERANCIA = 1e-4f;
    public:
        //Devolvera PoligonoRegular o PoligonoIrregular de acuerdo a neusytors vertices
        // El caller es responsable de liberar la memoria (o usar smart pointer)
        [[nodiscard]] static std::unique_ptr<Poligono> crear(const std::vector<Punto>& puntos);

        // helpers para formas comunes
        [[nodiscard]] static std::unique_ptr<Poligono> crearTriangulo(
            const Punto& a, const Punto& b, const Punto& c);

        [[nodiscard]] static std::unique_ptr<Poligono> crearCuadrado(
            float cx, float cy, float lado);

        [[nodiscard]] static std::unique_ptr<Poligono> crearPoligonoRegular(
            int lados, float cx, float cy, float radio);
};

#endif //CG_PRUEBA_POLIGONOFACTORY_H