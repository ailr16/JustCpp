#ifndef OOP_EXERCISES_H
#define OOP_EXERCISES_H

class Circle {
    private:
        float radius;
    
    public:
        void setRadius( float radius ) {
            this->radius = radius;
        };

        float computeArea( void ) {
            return (3.1416 * radius * radius);
        }

        float computePerimeter( void ) {
            return (2 * 3.1416 * radius);
        }
};

#endif