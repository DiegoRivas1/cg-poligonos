#include "Camara.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>

Camara* Camara::instancia = nullptr;

Camara::Camara(float ancho, float alto)
    : posicion(0.f, 0.f, 3.f)
    , frente(0.f, 0.f, -1.f)
    , arriba(0.f, 1.f, 0.f)
    , yaw(-90.f)    // apunta hacia -Z
    , pitch(0.f)
    , fov(45.f)
    , ancho(ancho), alto(alto)
    , nearPlane(0.1f), farPlane(100.f)
    , sensibilidad(0.1f)
    , ultimoX(ancho / 2.f), ultimoY(alto / 2.f)
    , primerMouse(true)
{
    instancia = this;
    actualizarFrente();
}

void Camara::actualizarFrente() {
    glm::vec3 dir;
    dir.x = std::cos(glm::radians(yaw)) * std::cos(glm::radians(pitch));
    dir.y = std::sin(glm::radians(pitch));
    dir.z = std::sin(glm::radians(yaw)) * std::cos(glm::radians(pitch));
    frente = glm::normalize(dir);
}

void Camara::procesarMouse(float xOffset, float yOffset) {
    yaw   += xOffset * sensibilidad;
    pitch += yOffset * sensibilidad;

    // limitar pitch para no voltear la camara
    if (pitch >  89.f) pitch =  89.f;
    if (pitch < -89.f) pitch = -89.f;

    actualizarFrente();
}

void Camara::procesarScroll(float yOffset) {
    fov -= yOffset;
    if (fov <  1.f) fov =  1.f;
    if (fov > 90.f) fov = 90.f;
}

void Camara::setPosicion(float x, float y, float z) {
    posicion = glm::vec3(x, y, z);
}

glm::mat4 Camara::getView() const {
    return glm::lookAt(posicion, posicion + frente, arriba);
}

glm::mat4 Camara::getProjection() const {
    return glm::perspective(
        glm::radians(fov),
        ancho / alto,
        nearPlane,
        farPlane
    );
}

void Camara::callbackMouse(GLFWwindow* w, double x, double y) {
    if (!instancia) return;

    float fx = static_cast<float>(x);
    float fy = static_cast<float>(y);
    bool  clickActivo = glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    instancia->evaluarSeleccion(fx, fy, clickActivo);
}

void Camara::callbackScroll(GLFWwindow*, double, double y) {
    if (instancia)
        instancia->procesarScroll(static_cast<float>(y));
}
void Camara::agregarPoligono(Poligono* p) {
    poligonos.push_back(p);
}

void Camara::evaluarSeleccion(float x, float y, bool clickActivo) {
    if (!clickActivo) {
        seleccionado = nullptr;
        primerMouse  = true;
        return;
    }

    if (primerMouse) {
        // al hacer click seleccionamos el poligono bajo el mouse
        seleccionado = nullptr;
        for (auto* p : poligonos) {
            if (p->contienePunto(x, y, static_cast<int>(ancho), static_cast<int>(alto))) {
                seleccionado = p;
                break;
            }
        }
        ultimoX = x;
        ultimoY = y;
        primerMouse = false;
    }

    if (seleccionado) {
        float xOffset = (x - ultimoX) * 0.5f;
        float yOffset = (y - ultimoY) * 0.5f;
        float delta   = xOffset - yOffset;
        seleccionado->addRotacion(yOffset, xOffset, 0.f);
    }

    ultimoX = x;
    ultimoY = y;
}