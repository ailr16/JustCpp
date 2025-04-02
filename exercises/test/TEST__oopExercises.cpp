#include <gtest/gtest.h>

TEST( test1, myFirstTest ){
    ASSERT_EQ( 1, 1 );
}

TEST( test1, mySecondTest ){
    ASSERT_EQ( 1, 0 );
}