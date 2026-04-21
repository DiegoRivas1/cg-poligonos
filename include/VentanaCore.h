//
// Created by DIEGO on 21/04/2026.
//

#ifndef CG_PRUEBA_VENTANACORE_H
#define CG_PRUEBA_VENTANACORE_H
#include "Ventana.h"

class VentanaCore : public Ventana {
    protected:
        void configurarContexto() override;
    public:
        VentanaCore(const std::string& titulo);
        VentanaCore(int ancho, int alto, const std::string &titulo);
        void limpiar(float r, float g, float b) const override;
};

#endif //CG_PRUEBA_VENTANACORE_H