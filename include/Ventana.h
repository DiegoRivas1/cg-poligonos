//
// Created by DIEGO on 21/04/2026.
//

#ifndef CG_PRUEBA_VENTANA_H
#define CG_PRUEBA_VENTANA_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Ventana {
    protected:
        GLFWwindow* ventana;
        int ancho, alto;

        virtual void configurarContexto() = 0; //Cada hijo usara una version de Opengl
        void inicializar(const std::string & titulo);
    private:
        static void frameBufferSizeCallback(GLFWwindow* ventana, int ancho, int alto);

    public:
        Ventana();
        Ventana(int ancho, int alto);
        virtual ~Ventana();

        [[nodiscard]] bool debeCerrar() const;
        virtual void limpiar(float r, float g, float b) const = 0;
        void actualizar() const;
        void procesarEntrada() const;

        [[nodiscard]] GLFWwindow* getVentana() const;
};

#endif //CG_PRUEBA_VENTANA_H