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
        src/Triangulo.cpp
        include/PoligonoIrregular.h
        src/PoligonoIrregular.cpp
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

### TEST
enable_testing()

find_package(GTest REQUIRED)

add_executable(tests
        test/TestTriangulo.cpp
        src/Punto.cpp
        src/Poligono.cpp
        src/Triangulo.cpp
        external/glad/src/glad.c
)

target_include_directories(tests PRIVATE
        external/glad/include
        include
)

target_link_libraries(tests PRIVATE
        GTest::GTest
        GTest::Main
        opengl32
        gdi32
)

add_test(NAME TrianguloTests COMMAND tests)