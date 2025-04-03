#include <gtest/gtest.h>
#include "circle.hpp"

TEST( ClassCircleTest, testAreaMethod ){
    Circle circleTest;

    circleTest.setRadius( 1 );
    ASSERT_EQ( circleTest.computeArea(), 3.1416f );
    circleTest.setRadius( 2 );
    ASSERT_EQ( circleTest.computeArea(), 12.5664f );
}

TEST( ClassCircleTest, testPerimeterMethod ){
    Circle circleTest;

    circleTest.setRadius( 1 );
    ASSERT_EQ( circleTest.computePerimeter(), 6.2832f );
    circleTest.setRadius( 2 );
    ASSERT_EQ( circleTest.computePerimeter(), 12.5664f );
}