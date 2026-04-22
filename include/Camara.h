#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <vector>
#include "Poligono.h"

class Camara {
    public:
        Camara(float ancho, float alto);

        void setPosicion(float x, float y, float z);
        void procesarMouse(float xOffset, float yOffset);
        void procesarScroll(float yOffset);

        // agrega poligonos para seleccion y rotacion
        void agregarPoligono(Poligono* p);

        [[nodiscard]] glm::mat4 getView()       const;
        [[nodiscard]] glm::mat4 getProjection() const;

        static void callbackMouse(GLFWwindow* w, double x, double y);
        static void callbackScroll(GLFWwindow* w, double x, double y);
        static Camara* instancia;

    private:
        glm::vec3 posicion;
        glm::vec3 frente;
        glm::vec3 arriba;

        float yaw, pitch, fov;
        float ancho, alto;
        float nearPlane, farPlane;
        float sensibilidad;

        float ultimoX, ultimoY;
        bool  primerMouse;

        std::vector<Poligono*> poligonos;   // poligonos conocidos
        Poligono*              seleccionado; // el que esta bajo el mouse

        void actualizarFrente();
        void evaluarSeleccion(float x, float y, bool clickActivo);
};