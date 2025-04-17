#include <gtest/gtest.h>
#include "simpleCalc.hpp"

TEST( ClassSimpleCalcTest, DisplayPrintResult ){
    std::string consoleOutput;

    testing::internal::CaptureStdout();
    Display::printResult(MathOperations::OPERATION::ADD, 0);
    consoleOutput = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(consoleOutput.c_str(), "The result of Addition is: 0\n");

    testing::internal::CaptureStdout();
    Display::printResult(MathOperations::OPERATION::ADD, 16);
    consoleOutput = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(consoleOutput.c_str(), "The result of Addition is: 16\n");

    testing::internal::CaptureStdout();
    Display::printResult(MathOperations::OPERATION::ADD, 17);
    consoleOutput = testing::internal::GetCapturedStdout();
    ASSERT_STRNE(consoleOutput.c_str(), "The result of Addition is: 16\n");

    testing::internal::CaptureStdout();
    Display::printResult(MathOperations::OPERATION::SUBSTRACT, 8);
    consoleOutput = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(consoleOutput.c_str(), "The result of Substraction is: 8\n");

    testing::internal::CaptureStdout();
    Display::printResult(MathOperations::OPERATION::MULTIPLY, 2);
    consoleOutput = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(consoleOutput.c_str(), "The result of Multiply is: 2\n");

    testing::internal::CaptureStdout();
    Display::printResult(MathOperations::OPERATION::DIVIDE, 6);
    consoleOutput = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(consoleOutput.c_str(), "The result of Division is: 6\n");

    testing::internal::CaptureStderr();
    Display::printResult(4, 6);
    consoleOutput = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(consoleOutput.c_str(), "map::at\n");
}

TEST( ClassSimpleCalcTest, MathOperationsAdd ){
    ASSERT_EQ(MathOperations::add(1, 2), 3);
    ASSERT_EQ(MathOperations::add(-10, 2), -8);
    ASSERT_EQ(MathOperations::add(-10, -2), -12);
    ASSERT_EQ(MathOperations::add(0xFFFE, 1), 0xFFFF);
    ASSERT_EQ(MathOperations::add(2147483647, 1), -2147483648);
    ASSERT_EQ(MathOperations::add(-2147483648, -1), 2147483647);
}

TEST( ClassSimpleCalcTest, MathOperationsSubstract ){
    ASSERT_EQ(MathOperations::substract(2, 1), 1);
    ASSERT_EQ(MathOperations::substract(-2, 1), -3);
    ASSERT_EQ(MathOperations::substract(-2423, -2423), 0);
    ASSERT_EQ(MathOperations::substract(2423, -2423), 2423 + 2423);
    ASSERT_EQ(MathOperations::substract(2147483647, -1), -2147483648);
    ASSERT_EQ(MathOperations::substract(-2147483648, 1), 2147483647);
}
