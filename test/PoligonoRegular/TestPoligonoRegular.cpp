#include <gtest/gtest.h>
#include <sstream>
#include "PoligonoRegular.h"

// Cuadrado 2x2 — lado=2, apotema=1, area=4, perimetro=8
static PoligonoRegular cuadrado({
    Punto(-1.f,  1.f), Punto(1.f,  1.f),
    Punto( 1.f, -1.f), Punto(-1.f, -1.f)
});

TEST(PoligonoRegularTest, NumVertices) {
    EXPECT_EQ(cuadrado.numVertices(), 4u);
}

TEST(PoligonoRegularTest, LongitudLado) {
    EXPECT_NEAR(cuadrado.longitudLado(), 2.f, 1e-4f);
}

TEST(PoligonoRegularTest, Apotema) {
    EXPECT_NEAR(cuadrado.apotema(), 1.f, 1e-4f);
}

TEST(PoligonoRegularTest, Perimetro) {
    EXPECT_NEAR(cuadrado.perimetro(), 8.f, 1e-4f);
}

TEST(PoligonoRegularTest, Area) {
    EXPECT_NEAR(cuadrado.area(), 4.f, 1e-4f);
}

TEST(PoligonoRegularTest, Print) {
    std::ostringstream os;
    os << cuadrado;
    EXPECT_NE(os.str().find("PoligonoRegular"), std::string::npos);
}