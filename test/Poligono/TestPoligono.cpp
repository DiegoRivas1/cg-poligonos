#include <gtest/gtest.h>
#include <sstream>
#include "Triangulo.h"
#include "PoligonoIrregular.h"

// Probamos polimorfismo con referencias a Poligono base
TEST(PoligonoTest, PolimorfismoNumVertices) {
    Triangulo tri(Punto(0.f, 0.f), Punto(1.f, 0.f), Punto(0.f, 1.f));
    PoligonoIrregular cuad({
        Punto(-1.f,  1.f), Punto(1.f,  1.f),
        Punto( 1.f, -1.f), Punto(-1.f, -1.f)
    });

    Poligono* polis[] = { &tri, &cuad };
    EXPECT_EQ(polis[0]->numVertices(), 3u);
    EXPECT_EQ(polis[1]->numVertices(), 4u);
}

TEST(PoligonoTest, PolimorfismoArea) {
    Triangulo tri(Punto(0.f, 0.f), Punto(3.f, 0.f), Punto(0.f, 4.f));
    PoligonoIrregular cuad({
        Punto(-1.f,  1.f), Punto(1.f,  1.f),
        Punto( 1.f, -1.f), Punto(-1.f, -1.f)
    });

    Poligono* polis[] = { &tri, &cuad };
    EXPECT_NEAR(polis[0]->area(), 6.f, 1e-4f);
    EXPECT_NEAR(polis[1]->area(), 4.f, 1e-4f);
}

TEST(PoligonoTest, PolimorfismoPrint) {
    Triangulo tri(Punto(0.f, 0.f), Punto(1.f, 0.f), Punto(0.f, 1.f));
    Poligono& p = tri;

    std::ostringstream os;
    os << p;                        // llama a print() del hijo via operator
    EXPECT_FALSE(os.str().empty());
}

TEST(PoligonoTest, GetVertices) {
    Triangulo tri(Punto(1.f, 2.f), Punto(3.f, 4.f), Punto(5.f, 6.f));
    const auto& v = tri.getVertices();
    ASSERT_EQ(v.size(), 3u);
    EXPECT_FLOAT_EQ(v[0].getX(), 1.f);
    EXPECT_FLOAT_EQ(v[1].getX(), 3.f);
    EXPECT_FLOAT_EQ(v[2].getX(), 5.f);
}