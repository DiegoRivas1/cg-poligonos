#include "Camara.h"
#include <glm/gtc/matrix_transform.hpp>

Camara::Camara(float ancho, float alto)
    : posicion(0.f, 0.f, 3.f)   // camara 3 unidades atras en Z
    , objetivo(0.f, 0.f, 0.f)   // mirando al origen
    , arriba(0.f, 1.f, 0.f)     // Y es arriba
    , ancho(ancho), alto(alto)
    , fov(45.f)
    , nearPlane(0.1f)
    , farPlane(100.f)
{}

void Camara::setPosicion(float x, float y, float z) {
    posicion = glm::vec3(x, y, z);
}

void Camara::setObjetivo(float x, float y, float z) {
    objetivo = glm::vec3(x, y, z);
}

glm::mat4 Camara::getView() const {
    return glm::lookAt(posicion, objetivo, arriba);
}

glm::mat4 Camara::getProjection() const {
    return glm::perspective(
        glm::radians(fov),
        ancho / alto,
        nearPlane,
        farPlane
    );
}