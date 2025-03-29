#include <iostream>
#include "oopExercises.hpp"


int main(void) {
    {
        std::cout << "Exercise 1. Circle Class ------------" << std::endl;
        Circle circleTest;

        circleTest.setRadius(16);

        std::cout << "Area: " << circleTest.computeArea() << std::endl
                  << "Perimeter: " << circleTest.computePerimeter() << std::endl;

        std::cout << "-------------------------------------" << std::endl;
    }
    
    return 0;
}