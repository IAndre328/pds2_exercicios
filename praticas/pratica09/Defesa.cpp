#include <iostream>

#include "Defesa.hpp"

Defesa::Defesa(int id, double energia) 
    : _id(id), _energia(energia){};

void Defesa::_consumirEnergia(double qtd){
    Defesa::_energia -= qtd;
    if (_energia <= 0) _energia = 0;
}

bool Defesa::isEnergySuficient(double custo){
    return (Defesa::get_energia() >= custo);
}

int Defesa::get_id(){ return Defesa::_id; }

double Defesa::get_energia(){ return Defesa::_energia;}

Defesa::~Defesa(){
    std::cout << "Defesa " << Defesa::_id << " desativada." << std::endl;
}