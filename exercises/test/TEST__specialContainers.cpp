#include <gtest/gtest.h>
#include "specialContainters.hpp"

TEST(SpecialContainers, testPair){
    PairExamples::example();
}

TEST(SpecialContainers, testTuple){
    TupleExamples::example();
}

TEST(SpecialContainers, testOptional){
    OptionalExamples::example();
}

TEST(SpecialContainers, testVariant){
    VariantExamples::example();
}

TEST(SpecialContainers, testAny){
    AnyExamples::example();
}