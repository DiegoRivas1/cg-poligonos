//
// Created by DIEGO on 21/04/2026.
//

#ifndef CG_PRUEBA_VENTANALEGACY_H
#define CG_PRUEBA_VENTANALEGACY_H
#include "Ventana.h"

class VentanaLegacy : public Ventana {
    public:
        VentanaLegacy(const std::string& titulo);
        VentanaLegacy(int ancho, int alto, const std::string& titulo);
        void limpiar(float r, float g, float b) const override;
    protected:
        void configurarContexto() override;
};

#endif //CG_PRUEBA_VENTANALEGACY_H