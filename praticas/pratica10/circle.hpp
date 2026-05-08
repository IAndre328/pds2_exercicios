#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include <string>
#include <cmath>


class Circle : public Shape
{
private:
    double radius_;
public:
    Circle(double radius);
    ~Circle() = default;

    std::string name() const override;
    double area() const override;
};


#endif