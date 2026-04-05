#include "Jogador.hpp"
#include "Tabuleiro.hpp"

#include <string>

class Partida{
    public:
        Tabuleiro tabuleiro;
        Jogador jogador1;
        Jogador jogador2;
        Jogador* atual;
        static int rodada;


        Partida(Jogador& jogador1, Jogador& jogador2);

        Jogador& getJogadorAtual();
        void executarJogada(int linha, int coluna);

        char statusPartida();
        void exibirPartida();
};
