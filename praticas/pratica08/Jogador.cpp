#include "Jogador.hpp"
#include <iostream>


Jogador::Jogador(std::string nome, char simbolo) : nome(nome), simbolo(simbolo) {}

std::string Jogador::getNome() const{
    return this->nome;
}

char Jogador::getSimbolo() const{
    return this->simbolo;
}


// Jogador::~Jogador(){
//     std::cout << "Destruindo jogador: " << this->nome << std::endl;
// }

