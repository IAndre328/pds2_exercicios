#include "Pessoa.hpp"

double convertor_rad_para_grau(double rad){
    double resultado = rad * (180/M_PI);
    return resultado;
}


    Pessoa::Pessoa(){
        this->x = -1.69;
        this->y = -1.69;
    };

    Pessoa::Pessoa(double x, double y){
        this->x = x;
        this->y = y;
    };

    double Pessoa::getX(){
        return this->x;
    };

    double Pessoa::getY(){
        return this->y;
    };

    void Pessoa::mover(double dx, double dy){
        this->x += dx;
        this->y += dy;
    };
