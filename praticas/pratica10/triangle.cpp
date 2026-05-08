#include "triangle.hpp"
#include <cmath>


Triangle::Triangle(double a, double b, double c)
    : a_(a), b_(b), c_(c), perimeter_((a+b+c)/2) {}

std::string Triangle::name() const{
    return "Triangulo";
}

double Triangle::area() const {
    return sqrt(
        this->perimeter_ * (
            (this->perimeter_ - this->a_) *
            (this->perimeter_ - this->b_) *
            (this->perimeter_ - this->c_)
        )
    );
}