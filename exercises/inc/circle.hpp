#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle {
    private:
        float radius;
    
    public:
        void setRadius( float radius );
        float computeArea( void );
        float computePerimeter( void );
};

#endif