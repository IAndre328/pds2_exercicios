#include "Jogador.hpp"
#include "Tabuleiro.hpp"

#include <iostream>

// g++ -std=c++11 -Wall teste.cpp

// std::cout << << std::endl;

int main()
{
    Jogador jogador1 = Jogador("Andre", 'X');
    Jogador jogador2 = Jogador("Ana",'O');

    std::cout << jogador1.getSimbolo() << std::endl;

    Tabuleiro Tab{};

    Tab.fazerJogada(0,0,'X');
    Tab.fazerJogada(0,1,'X');
    Tab.fazerJogada(0,2,'X');

    std::cout << Tab.verificarEstadoPartida() << std::endl;

    Tab.imprimir();

    return 0;
}
