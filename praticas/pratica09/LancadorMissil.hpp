#ifndef LANCADOR_MISSIL_HPP
#define LANCADOR_MISSIL_HPP

#include "Canhao.hpp"

#define CUSTO_MISSIL_EM_UNIDADE 5
#define INTENSIDADE_MISSIL 40

class LancadorMissil : public Defesa
{
private:
    int _misseis;
public:

    LancadorMissil(int id, double energia, double qtdMisseis) 
    : Defesa(id, energia), _misseis(qtdMisseis) {};
    
    void atacar(double &danoAcumulado);
};


#endif
