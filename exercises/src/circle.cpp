#include <iostream>
#include "circle.hpp"

void Circle::setRadius(float radius) {
    this->radius = radius;
}

float Circle::computeArea(void){
    return 3.1416 * radius * radius; 
}

float Circle::computePerimeter(void){
    return 2 * 3.1416 * radius; 
}