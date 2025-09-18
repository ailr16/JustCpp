#include <gtest/gtest.h>
#include "oop.hpp"

TEST(OOP, testAccessModifiers){
    AccessModifiersExample::example();
}

TEST(OOP, testPolymorphism){
    int a = 16;
    ASSERT_EQ(PolymorphismExample::example(a), a*2);
}