#include "BaseMilitar.hpp"

#include <iostream>
#include <iomanip>

void BaseMilitar::adicionarDefesa(Defesa* d){
    BaseMilitar::_defesas[_qtdAtual] = d;
    _qtdAtual = _qtdAtual + 1;
} 

void BaseMilitar::defender(double &saudeInimigo){
    double danoAcumulado = 0.00;

    for (int i = 0; i < _qtdAtual; i++)
        if (_defesas[i] != nullptr)
            _defesas[i]->atacar(danoAcumulado);
    
   saudeInimigo -= danoAcumulado;
   if (saudeInimigo < 0) saudeInimigo = 0.00; 

   std::cout << std::setprecision(2);
   std::cout << "Saude Inimigo: " << saudeInimigo << std::endl;
            
}

BaseMilitar::~BaseMilitar(){

    for (int i = 0; i < LIMITE_DEFESAS; i++)
        if (BaseMilitar::_defesas[i] != nullptr){
            delete BaseMilitar::_defesas[i];
            BaseMilitar::_defesas[i] = nullptr;
        }
        
}