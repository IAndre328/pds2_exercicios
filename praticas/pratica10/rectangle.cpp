#include "rectangle.hpp"


Rectangle::Rectangle(double width, double height)
    : width_(width), height_(height) {}

std::string Rectangle::name() const{
    return "Retangulo";
}

double Rectangle::area() const{
    return this->height_ * this->width_;
}