#include <gtest/gtest.h>
#include "smartPointers.hpp"

TEST(SmartPointersTests, testAutoPtr){
    SmartPointersExamples::autoPtr();
}

TEST(SmartPointersTests, testUniquePtr){
    SmartPointersExamples::uniquePtr();
}

TEST(SmartPointersTests, testSharedPtr){
    SmartPointersExamples::sharedPtr();
}

TEST(SmartPointersTests, testWeakPtr){
    SmartPointersExamples::weakPtr();
}