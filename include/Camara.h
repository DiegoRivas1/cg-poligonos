//
// Created by DIEGO on 21/04/2026.
//

#ifndef CG_PRUEBA_CAMARA_H
#define CG_PRUEBA_CAMARA_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camara {
    private:
        glm::vec3 posicion;   // donde esta la camara
        glm::vec3 objetivo;   // a donde mira
        glm::vec3 arriba;     // cual es arriba (0,1,0 normalmente)

        float ancho, alto;
        float fov;            // campo de vision en grados
        float nearPlane;      // plano cercano
        float farPlane;       // plano lejano
    public:
        Camara(float ancho, float alto);

        // mueve la camara
        void setPosicion(float x, float y, float z);
        void setObjetivo(float x, float y, float z);

        [[nodiscard]] glm::mat4 getView()       const;
        [[nodiscard]] glm::mat4 getProjection() const;

};
#endif //CG_PRUEBA_CAMARA_H