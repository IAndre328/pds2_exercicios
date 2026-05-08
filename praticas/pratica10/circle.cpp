#include "circle.hpp"

Circle::Circle(double radius)
    : radius_(radius) {}

std::string Circle::name() const{
    return "Circulo";
}

double Circle::area() const{
    return std::acos(-1.0) * this->radius_ * this->radius_;
}