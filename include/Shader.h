//
// Created by DIEGO on 21/04/2026.
//

#ifndef CG_PRUEBA_SHADER_H
#define CG_PRUEBA_SHADER_H
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const char* vertexSrc, const char* fragmentSrc);
    ~Shader();

    void usar() const;
    void setColor(float r, float g, float b, float a = 1.0f) const;
    void setMatrix(const std::string& nombre, const glm::mat4& mat) const;
    [[nodiscard]] unsigned int getId() const { return id; }

private:
    unsigned int id;
    static unsigned int compilar(unsigned int tipo, const char* src);
};
#endif //CG_PRUEBA_SHADER_H