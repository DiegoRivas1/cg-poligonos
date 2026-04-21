#include <gtest/gtest.h>
#include <sstream>
#include "Punto.h"

TEST(PuntoTest, Constructor2D) {
    Punto p(1.f, 2.f);
    EXPECT_FLOAT_EQ(p.getX(), 1.f);
    EXPECT_FLOAT_EQ(p.getY(), 2.f);
    EXPECT_FLOAT_EQ(p.getZ(), 0.f);  // Z se pone 0 automáticamente
}

TEST(PuntoTest, Constructor3D) {
    Punto p(1.f, 2.f, 3.f);
    EXPECT_FLOAT_EQ(p.getX(), 1.f);
    EXPECT_FLOAT_EQ(p.getY(), 2.f);
    EXPECT_FLOAT_EQ(p.getZ(), 3.f);
}

TEST(PuntoTest, ConstructorDefault) {
    Punto p;
    EXPECT_FLOAT_EQ(p.getX(), 0.f);
    EXPECT_FLOAT_EQ(p.getY(), 0.f);
    EXPECT_FLOAT_EQ(p.getZ(), 0.f);
}

TEST(PuntoTest, Print2D) {
    Punto p(1.5f, 2.5f);
    std::ostringstream os;
    os << p;
    EXPECT_EQ(os.str(), "(1.5, 2.5)");
}

TEST(PuntoTest, Print3D) {
    Punto p(1.f, 2.f, 3.f);
    std::ostringstream os;
    os << p;
    EXPECT_EQ(os.str(), "(1, 2, 3)");
}