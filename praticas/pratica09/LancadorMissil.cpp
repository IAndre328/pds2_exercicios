#include "LancadorMissil.hpp"

#include <iostream>



void LancadorMissil::atacar(double &danoAcumulado){
    
    if (
        Defesa::isEnergySuficient(CUSTO_MISSIL_EM_UNIDADE)
        && _misseis >= 1
    ){
        Defesa::_consumirEnergia(CUSTO_MISSIL_EM_UNIDADE);
        danoAcumulado += INTENSIDADE_MISSIL;

        _misseis = _misseis - 1;
    }

}
