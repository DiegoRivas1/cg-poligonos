#include <gtest/gtest.h>
#include <sstream>
#include "PoligonoIrregular.h"

// Cuadrado 2x2 área=4, perímetro=8
static PoligonoIrregular cuadrado({
    Punto(-1.f,  1.f), Punto(1.f,  1.f),
    Punto( 1.f, -1.f), Punto(-1.f, -1.f)
});

// Pentágono irregular simple
static PoligonoIrregular pentagono({
    Punto( 0.f,  2.f), Punto( 2.f,  1.f),
    Punto( 1.f, -1.f), Punto(-1.f, -1.f),
    Punto(-2.f,  1.f)
});

TEST(PoligonoIrregularTest, CuadradoNumVertices) {
    EXPECT_EQ(cuadrado.numVertices(), 4u);
}

TEST(PoligonoIrregularTest, CuadradoArea) {
    EXPECT_NEAR(cuadrado.area(), 4.f, 1e-4f);
}

TEST(PoligonoIrregularTest, CuadradoPerimetro) {
    EXPECT_NEAR(cuadrado.perimetro(), 8.f, 1e-4f);
}

TEST(PoligonoIrregularTest, PentagonoNumVertices) {
    EXPECT_EQ(pentagono.numVertices(), 5u);
}

TEST(PoligonoIrregularTest, Print) {
    std::ostringstream os;
    os << cuadrado;
    EXPECT_NE(os.str().find('4'), std::string::npos);  // menciona 4 vertices
}