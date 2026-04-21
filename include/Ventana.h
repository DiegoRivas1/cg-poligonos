//
// Created by DIEGO on 21/04/2026.
//

#ifndef CG_PRUEBA_VENTANA_H
#define CG_PRUEBA_VENTANA_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Ventana {
    private:
        GLFWwindow* ventana;
        int ancho, alto;
        static void frameBufferSizeCallback(GLFWwindow* ventana, int ancho, int alto);

    public:
        Ventana(const std::string & titulo);
        Ventana(int ancho, int alto, const std::string& titulo);
        ~Ventana();

        [[nodiscard]] bool debeCerrar() const;
        static void limpiar(float r, float g, float b) ;
        void actualizar()const;
        void procesarEntrada() const;

        [[nodiscard]] GLFWwindow* getVentana() const;
};

#endif //CG_PRUEBA_VENTANA_H