#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP


#include "shape.hpp"
#include <string>

class Triangle : public Shape
{
private:
    double a_;
    double b_;
    double c_;
    double perimeter_;
public:
    Triangle(double a, double b, double c);
    ~Triangle() = default;

    std::string name() const override;
    double area() const override;
};



#endif