#include <gtest/gtest.h>
#include "Triangulo.h"

// Triángulo rectángulo 3-4-5
static Triangulo tri(
    Punto(0.f, 0.f),
    Punto(3.f, 0.f),
    Punto(0.f, 4.f)
);

TEST(TrianguloTest, NumVertices) {
    EXPECT_EQ(tri.numVertices(), 3u);
}

TEST(TrianguloTest, Perimetro) {
    EXPECT_NEAR(tri.perimetro(), 12.f, 1e-4f);
}

TEST(TrianguloTest, Area) {
    EXPECT_NEAR(tri.area(), 6.f, 1e-4f);
}

TEST(TrianguloTest, Vertices) {
    const auto& v = tri.getVertices();
    ASSERT_EQ(v.size(), 3u);
    EXPECT_FLOAT_EQ(v[0].getX(), 0.f);
    EXPECT_FLOAT_EQ(v[1].getX(), 3.f);
    EXPECT_FLOAT_EQ(v[2].getY(), 4.f);
}