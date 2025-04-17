#include "simpleCalc.hpp"

namespace MathOperations {
    int add(int op1, int op2){
        return op1 + op2;
    }

    int substract(int op1, int op2){
        return op1 - op2;
    }

    int multiply(int op1, int op2){
        return op1 * op2;
    }

    int divide(int op1, int op2){
        return op1 / op2;
    }
}

namespace Display {
    void printResult(int operation, int result){
        std::cout << "The result of " << MathOperations::operationMap.at(operation) << " is: " << result << std::endl;
    }

    void printError(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}