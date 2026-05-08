#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


#include "shape.hpp"

#include <string>

class Rectangle : public Shape
{
private:
    double width_;
    double height_;
public:
    Rectangle(double width, double height);
    ~Rectangle() = default;

    std::string name() const override;
    double area() const override;
};

#endif