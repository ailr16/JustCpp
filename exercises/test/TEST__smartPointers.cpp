#include <gtest/gtest.h>
#include "smartPointers.hpp"

TEST(SmartPointersTests, testAutoPtr){
    SmartPointersExamples::autoPtr();
}

TEST(SmartPointersTests, testUniquePtr){
    SmartPointersExamples::uniquePtr();
}
