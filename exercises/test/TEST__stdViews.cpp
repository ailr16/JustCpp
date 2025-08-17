#include <gtest/gtest.h>
#include "stdViews.hpp"

TEST(StdViews, testSpanExample){
    SpanExamples::example();
}

TEST(StdViews, teststringViewExample){
    StrviewExamples::example();
}

TEST(StdViews, test){
    ViewExamples::example();
}