//
// Created by DIEGO on 21/04/2026.
//
#include "Shader.h"
#include <stdexcept>
#include <iostream>

Shader::Shader(const char* vertexSrc, const char* fragmentSrc) {
    unsigned int vert = compilar(GL_VERTEX_SHADER,   vertexSrc);
    unsigned int frag = compilar(GL_FRAGMENT_SHADER, fragmentSrc);

    id = glCreateProgram();
    glAttachShader(id, vert);
    glAttachShader(id, frag);
    glLinkProgram(id);
    std::cerr << "Shader compilado OK, id=" << id << std::endl;

    int ok;
    glGetProgramiv(id, GL_LINK_STATUS, &ok);
    if (!ok) {
        char log[512];
        glGetProgramInfoLog(id, 512, nullptr, log);
        throw std::runtime_error(std::string("Error al enlazar shaders: ") + log);
    }

    // ya enlazados, no los necesitamos más
    glDeleteShader(vert);
    glDeleteShader(frag);
}

Shader::~Shader() {
    glDeleteProgram(id);
}

void Shader::usar() const {
    glUseProgram(id);
}

void Shader::setColor(float r, float g, float b, float a) const {
    int loc = glGetUniformLocation(id, "uColor");
    glUniform4f(loc, r, g, b, a);
}

unsigned int Shader::compilar(unsigned int tipo, const char* src) {
    unsigned int shader = glCreateShader(tipo);
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int ok;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        throw std::runtime_error(std::string("Error al compilar shader: ") + log);
    }
    return shader;
}