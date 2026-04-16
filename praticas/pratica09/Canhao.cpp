#include "Canhao.hpp"

void Canhao::atacar(double &danoAcumulado) {
    if (Defesa::isEnergySuficient(CUSTO_CANHAO_EM_UNIDADE)){
        Defesa::_consumirEnergia(CUSTO_CANHAO_EM_UNIDADE);
        danoAcumulado += Canhao::get_intensidade();
    }
      
}

double Canhao::get_intensidade(){
    return Canhao::_intensidade;
}