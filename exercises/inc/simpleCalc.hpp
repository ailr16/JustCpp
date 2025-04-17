#ifndef SIMPLE_CALC_HPP
#define SIMPLE_CALC_HPP

#include <map>
#include <iostream>
#include <cassert>
#include <exception>
#include <functional>

typedef std::map<int, int> MyMap;

namespace MathOperations {
    enum OPERATION{
        ADD,
        SUBSTRACT,
        MULTIPLY,
        DIVIDE
    };

    std::map<int, std::string> operationMap = {
        {ADD, "Addition"},
        {SUBSTRACT, "Substraction"},
        {MULTIPLY, "Multiply"},
        {DIVIDE, "Division"}
    };

    int add(int op1, int op2);
    int substract(int op1, int op2);
    int multiply(int op1, int op2);
    int divide(int op1, int op2);
}

namespace Display {
    void printResult(int operation, int result);
    void printError(const std::exception& e);
}

#endif