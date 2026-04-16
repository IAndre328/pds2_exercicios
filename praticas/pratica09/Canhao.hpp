#ifndef CANHAO_HPP
#define CANHAO_HPP

#include "Defesa.hpp"

#define CUSTO_CANHAO_EM_UNIDADE 10

class Canhao : public Defesa
{
private:
    double _intensidade;
    
public:
    Canhao(int id, double energia, double intensidade) 
    : Defesa(id, energia)  ,_intensidade(intensidade) {};
    
    void atacar(double &danoAcumulado) override;

    double get_intensidade();
};

#endif