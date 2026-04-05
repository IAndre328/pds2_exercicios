#include "Partida.hpp"

#include <string>
#include <iostream>

int Partida::rodada = 0;

Partida::Partida(Jogador& jogador1, Jogador& jogador2)
    : tabuleiro(Tabuleiro()) ,jogador1(jogador1), jogador2(jogador2){
        atual = &this->jogador1;
}

Jogador& Partida::getJogadorAtual(){
    if (rodada % 2 == 0) return jogador1;
    else return jogador2;
}

void Partida::executarJogada(int linha, int coluna){

    if (Partida::tabuleiro.validaJogada(linha, coluna, atual->getSimbolo()) == true){
        Partida::tabuleiro.fazerJogada(linha, coluna, atual->getSimbolo());
        Partida::rodada++;
        atual = &Partida::getJogadorAtual();
    }
    else {
        std::cout << "Jogada invalida!\n" << std::endl;
    }

}

char Partida::statusPartida(){
    return tabuleiro.verificarEstadoPartida();
}

void Partida::exibirPartida(){
    tabuleiro.imprimir();
}