#ifndef CUSTOM_EXCEPTION_HPP
#define CUSTOM_EXCEPTION_HPP

#include <exception>
#include <string>
#include <iostream>

class CException : public std::exception {
    private:
        std::string message;

    public:
        explicit CException(const std::string& msg) : message(msg) {}

        const char* what() {
            return message.c_str();
        }
};

namespace CExceptionExamples {
    void example(void);
    int failing_function(void);
}

#endif