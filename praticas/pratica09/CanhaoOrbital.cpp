#include "CanhaoOrbital.hpp"

#include <iostream>

void CanhaoOrbital::atacar(double &danoAcumulado) {
    
    if (Defesa::isEnergySuficient(CUSTO_CANHAO_EM_UNIDADE)){
        
        Canhao::atacar(danoAcumulado);
        danoAcumulado += Canhao::get_intensidade() * (_multiplicadorGravitacional -1);
        std::cout << "Ataque Orbital realizado!" << std::endl;
    }

}