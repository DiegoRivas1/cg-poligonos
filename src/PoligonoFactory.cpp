#include "PoligonoFactory.h"
#include "PoligonoRegular.h"
#include "PoligonoIrregular.h"
#include <cmath>
#include <stdexcept>

bool PoligonoFactory::esRegular(const std::vector<Punto>& puntos) {
    if (puntos.size() < 3)
        throw std::invalid_argument("NUn poligono necesita minimo 3 vertices");
    // Calculamos la longitud del primer lado como referencia
    auto distancia = [](const Punto& a, const Punto& b) {
        float dx = b.getX() - a.getX();
        float dy = b.getY() - a.getY();
        float dz = b.getZ() - a.getZ();
        return std::sqrt(dx*dx + dy*dy + dz*dz);
    };

    const unsigned int n = puntos.size();
    const float ladoRef = distancia(puntos[0], puntos[1]);

    for (unsigned int i = 1; i < n; i++) {
        unsigned int j = (i + 1) % n;
        if (std::abs(distancia(puntos[i], puntos[j]) - ladoRef) > TOLERANCIA)
            return false;
    }
    return true;
}
std::unique_ptr<Poligono> PoligonoFactory::crear(const std::vector<Punto>& puntos) {
    if (puntos.size() < 3)
        throw std::invalid_argument("NUn poligono necesita mino 3 vertices");
    if (PoligonoFactory::esRegular(puntos))
        return std::make_unique<PoligonoRegular>(puntos);
    else
        return std::make_unique<PoligonoIrregular>(puntos);

}