#include <gtest/gtest.h>
#include "sequenceContainers.hpp"

TEST(SequenceContainers, testArray){
    ArrayExamples::example();
}

TEST(SequenceContainers, testVector){
    VectorExamples::example();
}

TEST(SequenceContainers, testDeque){
    DequeExamples::example();
}