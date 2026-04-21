#include <gtest/gtest.h>
#include "PoligonoFactory.h"
#include "PoligonoRegular.h"
#include "PoligonoIrregular.h"

TEST(PoligonoFactoryTest, CreaRegular) {
    auto p = PoligonoFactory::crear({
        Punto(-1.f,  1.f), Punto(1.f,  1.f),
        Punto( 1.f, -1.f), Punto(-1.f, -1.f)
    });
    EXPECT_NE(dynamic_cast<PoligonoRegular*>(p.get()), nullptr);
}   // unique_ptr libera la memoria aquí automáticamente

TEST(PoligonoFactoryTest, CreaIrregular) {
    auto p = PoligonoFactory::crear({
        Punto(0.f, 0.f),
        Punto(3.f, 0.f),
        Punto(0.f, 4.f)
    });
    EXPECT_NE(dynamic_cast<PoligonoIrregular*>(p.get()), nullptr);
}

TEST(PoligonoFactoryTest, MenosDeTresVertices) {
    EXPECT_THROW(
        (void)PoligonoFactory::crear({Punto(0.f, 0.f), Punto(1.f, 0.f)}),
        std::invalid_argument
    );
}