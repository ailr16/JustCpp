#include <gtest/gtest.h>
#include "associativeContainers.hpp"

TEST(AssociativeContainers, testSet){
    SetExamples::example();
}

TEST(AssociativeContainers, testMap){
    MapExamples::example();
}

TEST(AssociativeContainers, testUnorSet){
    USetExamples::example();
}

TEST(AssociativeContainers, testUnordMap){
    EXPECT_THROW(
        UMapExamples::example(),
        std::exception
    );
}