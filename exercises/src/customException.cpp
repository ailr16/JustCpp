#include "customException.hpp"

void CExceptionExamples::example(void) {
    try {
        int ret = failing_function();
    }
    catch(CException& e) {
        std::cout << e.what() << std::endl;
    }
}

int CExceptionExamples::failing_function(void) {
    throw CException("Testing Failure");
}