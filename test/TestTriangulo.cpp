#include <gtest/gtest.h>
#include "Triangulo.h"
#include <cmath>

// Triángulo rectángulo 3-4-5
static Triangulo tri3_4_5(
    Punto(0.f, 0.f, 0.f),
    Punto(3.f, 0.f, 0.f),
    Punto(0.f, 4.f, 0.f)
);

TEST(TrianguloTest, NumVertices) {
    EXPECT_EQ(tri3_4_5.numVertices(), 3);
}

TEST(TrianguloTest, Perimetro) {
    // 3 + 4 + 5 = 12
    EXPECT_NEAR(tri3_4_5.perimetro(), 12.f, 1e-4f);
}

TEST(TrianguloTest, Area) {
    // base*altura/2 = 3*4/2 = 6
    EXPECT_NEAR(tri3_4_5.area(), 6.f, 1e-4f);
}

TEST(TrianguloTest, Vertices) {
    const auto& verts = tri3_4_5.getVertices();
    ASSERT_EQ(verts.size(), 3u);
    EXPECT_FLOAT_EQ(verts[0].getX(), 0.f);
    EXPECT_FLOAT_EQ(verts[1].getY(), 0.f);
    EXPECT_FLOAT_EQ(verts[2].getZ(), 0.f);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}