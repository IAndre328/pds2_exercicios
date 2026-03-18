#ifndef PESSOA_HPP
#define PESSOA_HPP


#include <cmath>


struct Pessoa{
    double x;
    double y;

    Pessoa();

    Pessoa(double x, double y);

    double getX();

    double getY();

    void mover(double dx, double dy);
};

double convertor_rad_para_grau(double rad);


#endif
