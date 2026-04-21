cmake_minimum_required(VERSION 3.20)
project(cg_prueba)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)

# ── Ejecutable principal ──────────────────────────────────────────────
add_executable(cg_prueba
        src/main.cpp
        src/Punto.cpp
        src/Poligono.cpp
        src/PoligonoIrregular.cpp
        src/Triangulo.cpp
        external/glad/src/glad.c
)

target_include_directories(cg_prueba PRIVATE
        external/glad/include
        include
)

find_package(glfw3 REQUIRED)

target_link_libraries(cg_prueba PRIVATE
        glfw
        opengl32
        gdi32
)

# ── Tests ─────────────────────────────────────────────────────────────
enable_testing()
find_package(GTest REQUIRED)

# Fuentes comunes a todos los tests (sin main.cpp ni glad para OpenGL)
set(COMMON_SOURCES
        src/Punto.cpp
        src/Poligono.cpp
        src/PoligonoIrregular.cpp
        src/Triangulo.cpp
        external/glad/src/glad.c
)

set(COMMON_INCLUDES
        external/glad/include
        include
)

set(COMMON_LIBS
        GTest::GTest
        GTest::Main
        opengl32
        gdi32
)

# ── TestPunto ─────────────────────────────────────────────────────────
add_executable(TestPunto test/Punto/TestPunto.cpp ${COMMON_SOURCES})
target_include_directories(TestPunto PRIVATE ${COMMON_INCLUDES})
target_link_libraries(TestPunto PRIVATE ${COMMON_LIBS})
add_test(NAME TestPunto COMMAND TestPunto)

# ── TestPoligono ──────────────────────────────────────────────────────
add_executable(TestPoligono test/Poligono/TestPoligono.cpp ${COMMON_SOURCES})
target_include_directories(TestPoligono PRIVATE ${COMMON_INCLUDES})
target_link_libraries(TestPoligono PRIVATE ${COMMON_LIBS})
add_test(NAME TestPoligono COMMAND TestPoligono)

# ── TestTriangulo ─────────────────────────────────────────────────────
add_executable(TestTriangulo test/Triangulo/TestTriangulo.cpp ${COMMON_SOURCES})
target_include_directories(TestTriangulo PRIVATE ${COMMON_INCLUDES})
target_link_libraries(TestTriangulo PRIVATE ${COMMON_LIBS})
add_test(NAME TestTriangulo COMMAND TestTriangulo)

# ── TestPoligonoIrregular ──────────────────────────────────────────────────────
add_executable(TestPoligonoIrregular
        test/PoligonoIrregular/TestPoligonoIrregular.cpp
        ${COMMON_SOURCES}
        test/TestPoligonoIrregular/TestPoligonoIrregular.cpp
)
target_include_directories(TestPoligonoIrregular PRIVATE ${COMMON_INCLUDES})
target_link_libraries(TestPoligonoIrregular PRIVATE ${COMMON_LIBS})
add_test(NAME TestPoligonoIrregular COMMAND TestPoligonoIrregular)