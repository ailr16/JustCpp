#ifndef SMART_POINTERS_HPP
#define SMART_POINTERS_HPP

#include <iostream>
#include <memory>

namespace SmartPointersExamples {
    struct nComplex {
        double real;
        double imaginary;
        nComplex(double real, double imaginary) : real(real), imaginary(imaginary){}
    };

    void autoPtr(void);
    void uniquePtr(void);
    void sharedPtr(void);
    void weakPtr(void);
}

#endif