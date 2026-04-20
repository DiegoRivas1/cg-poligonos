cmake_minimum_required(VERSION 4.1)
project(cg_prueba)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)

add_executable(OpenGLTest
        src/main.cpp
        external/glad/src/glad.c
        include/Punto.h
        src/Punto.cpp
        include/Poligono.h
        src/Poligono.cpp
        include/Triangulo.h
)

target_include_directories(OpenGLTest PRIVATE
        external/glad/include
)

# Buscar GLFW instalado por MSYS2
find_package(glfw3 REQUIRED)

target_link_libraries(OpenGLTest
        glfw
        opengl32
        gdi32
)