#include "simpleCalc.hpp"

namespace MathOperations {
    std::map<int, std::string> operationMap = {
        {ADD, "Addition"},
        {SUBSTRACT, "Substraction"},
        {MULTIPLY, "Multiply"},
        {DIVIDE, "Division"}
    };

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
        try{
            std::cout << "The result of " << MathOperations::operationMap.at(operation) << " is: " << result << std::endl;
        }
        catch(const std::exception& e){
            printError(e);
        }
    }

    void printError(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}