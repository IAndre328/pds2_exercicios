#ifndef CANHAO_ORBITAL_HPP
#define CANHAO_ORBITAL_HPP

#include "Canhao.hpp"

class CanhaoOrbital : public Canhao
{
private:
    double _multiplicadorGravitacional;
public:
    CanhaoOrbital(int id, double energia, double intensidade, double multiplicadorGravitacional) 
    : Canhao(id, energia, intensidade), _multiplicadorGravitacional(multiplicadorGravitacional) {};

    void atacar(double &danoAcumulado) override;

};



#endif