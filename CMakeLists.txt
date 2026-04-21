cmake_minimum_required(VERSION 3.20)
project(cg_prueba)

#
find_package(glm REQUIRED)

target_link_libraries(cg_prueba PRIVATE
        glfw
        opengl32
        gdi32
        glm::glm
)
#
set(CMAKE_CXX_STANDARD 20)
include_directories(include)
set(APP_SOURCES
        src/Punto.cpp
        src/Poligono.cpp
        src/PoligonoIrregular.cpp
        src/PoligonoRegular.cpp
        src/PoligonoFactory.cpp
        src/Triangulo.cpp
        src/Ventana.cpp
        src/VentanaLegacy.cpp
        src/VentanaCore.cpp
        src/Shader.cpp
        external/glad/src/glad.c
)
# ── Ejecutable principal ──────────────────────────────────────────────
add_executable(core_app
        src/main_core.cpp
        ${APP_SOURCES}
)

target_include_directories(core_app PRIVATE
        external/glad/include
        include
)

target_link_libraries(core_app PRIVATE
        glfw3
        opengl32
        gdi32
)

#legacy
add_executable(legacy_app
        src/main_legacy.cpp
        ${APP_SOURCES}
)

target_include_directories(legacy_app PRIVATE
        external/glad/include
        include
)

target_link_libraries(legacy_app PRIVATE
        glfw3
        opengl32
        gdi32
)
#dual
add_executable(dual_app
        src/main_dual.cpp
        ${APP_SOURCES}
)

target_include_directories(dual_app PRIVATE
        external/glad/include
        include
)

target_link_libraries(dual_app PRIVATE
        glfw3
        opengl32
        gdi32
)
# ── Tests ─────────────────────────────────────────────────────────────
enable_testing()
find_package(GTest REQUIRED)

set(COMMON_SOURCES
        src/Punto.cpp
        src/Poligono.cpp
        src/PoligonoIrregular.cpp
        src/PoligonoRegular.cpp
        src/PoligonoFactory.cpp
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

# ── TestPoligonoIrregular ─────────────────────────────────────────────
add_executable(TestPoligonoIrregular test/PoligonoIrregular/TestPoligonoIrregular.cpp ${COMMON_SOURCES})
target_include_directories(TestPoligonoIrregular PRIVATE ${COMMON_INCLUDES})
target_link_libraries(TestPoligonoIrregular PRIVATE ${COMMON_LIBS})
add_test(NAME TestPoligonoIrregular COMMAND TestPoligonoIrregular)

# ── TestPoligonoRegular ───────────────────────────────────────────────
add_executable(TestPoligonoRegular test/PoligonoRegular/TestPoligonoRegular.cpp ${COMMON_SOURCES})
target_include_directories(TestPoligonoRegular PRIVATE ${COMMON_INCLUDES})
target_link_libraries(TestPoligonoRegular PRIVATE ${COMMON_LIBS})
add_test(NAME TestPoligonoRegular COMMAND TestPoligonoRegular)

# ── TestPoligonoFactory ───────────────────────────────────────────────
add_executable(TestPoligonoFactory test/PoligonoFactory/TestPoligonoFactory.cpp ${COMMON_SOURCES})
target_include_directories(TestPoligonoFactory PRIVATE ${COMMON_INCLUDES})
target_link_libraries(TestPoligonoFactory PRIVATE ${COMMON_LIBS})
add_test(NAME TestPoligonoFactory COMMAND TestPoligonoFactory)

# ── TestTriangulo ─────────────────────────────────────────────────────
add_executable(TestTriangulo test/Triangulo/TestTriangulo.cpp ${COMMON_SOURCES})
target_include_directories(TestTriangulo PRIVATE ${COMMON_INCLUDES})
target_link_libraries(TestTriangulo PRIVATE ${COMMON_LIBS})
add_test(NAME TestTriangulo COMMAND TestTriangulo)