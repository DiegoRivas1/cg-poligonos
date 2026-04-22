//
// Created by DIEGO on 20/04/2026.
//

#ifndef CG_PRUEBA_POLIGONO_H
#define CG_PRUEBA_POLIGONO_H

#pragma once
#include <vector>
#include <ostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Punto.h"
class Shader;

class Poligono;
std::ostream& operator<<(std::ostream& os, const Poligono& punto);

class Poligono {
    protected:
        mutable unsigned int VAO = 0;
        mutable unsigned int VBO = 0;
        mutable bool gpuListo = false;
        std::vector<Punto> vertices;

        //tranfromaciones
        glm::vec3 posicion = glm::vec3(0.f);
        glm::vec3 escala = glm::vec3(1.f);
        glm::vec3 rotacion = glm::vec3(0.f); // angulos en x , y ,z

        [[nodiscard]] static float distancia(const Punto& a, const Punto& b);
    public:
        virtual ~Poligono() = default;

        //transformacions
        void setPosicion(float x, float y, float z = 0.f);
        void setEscala(float x, float y, float z = 1.f);
        void setRotacion(float x, float y, float z);
        void addRotacion(float x, float y, float z); // suma a la rotacon actual
        [[nodiscard]] glm::mat4 getModel() const;

        [[nodiscard]] virtual float area() const = 0;
        [[nodiscard]] virtual float perimetro() const = 0;
        virtual void dibujar() const = 0;          // cada figura decidira como se dibuja
        virtual void dibujar(const Shader& shader) const;
        [[nodiscard]] virtual unsigned int numVertices() const = 0;

        //Cada hijo definia como se imprimira
        virtual void print(std::ostream& os) const = 0;
        [[nodiscard]] const std::vector<Punto>& getVertices() const;

        //
        friend std::ostream& operator<<(std::ostream& os, const Poligono& p);
        [[nodiscard]] glm::vec3 getRotacion() const ;
        [[nodiscard]] bool contienePunto(float px, float py, int anchoVentana, int altoVentana) const;
};

#endif //CG_PRUEBA_POLIGONO_H