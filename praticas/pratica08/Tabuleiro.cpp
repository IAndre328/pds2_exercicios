#include "Tabuleiro.hpp"

#include <iostream>



void Tabuleiro::preencherTabuleiro3por3ComChar(char c, char (&tab)[3][3]){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            tab[i][j] = c;
        }
    }
}


bool Tabuleiro::verificarSeSimboloGanhouDiagonal(char (&tab)[3][3], char simbolo){
    if (tab[1][1] == tab[2][2] 
        && tab[2][2] == tab[3][3]
        && tab[3][3] == simbolo
    ){
        return true;
    }
    else if (tab[1][3] == tab[2][2]
            && tab[2][2] == tab[3][1]
            && tab[3][1] == simbolo
    ){
        return true;
    }
    else {
        return false;
    }
}

bool Tabuleiro::verificarSeSimboloGanhouColuna(char (&tab)[3][3], char simbolo){
    for (int i = 0; i < 3; i++){
        if (tab[0][i] == tab[1][i] 
            && tab[1][i] == tab[2][i]
            && tab[2][i] == simbolo
        ){
            return true;
        }
    }
    return false;
}

bool Tabuleiro::verificarSeSimboloGanhouLinha(char (&tab)[3][3], char simbolo){
    for (int i = 0; i < 3; i++){
        if (tab[i][0] == tab[i][1] 
            && tab[i][1] == tab[i][2]
            && tab[i][2] == simbolo
        ){
            return true;
        }
    }
    return false;
}

bool Tabuleiro::verificarSeSimboloGanhouGeral(char (&tab)[3][3], char simbolo){
    if (
        Tabuleiro::verificarSeSimboloGanhouLinha(tab, simbolo) 
        || Tabuleiro::verificarSeSimboloGanhouColuna(tab, simbolo)
        || Tabuleiro::verificarSeSimboloGanhouDiagonal(tab, simbolo) == true
    ){
        return true;
    }
    else return false;
}

bool Tabuleiro::verificarSeTabuleiroEncheu(char (&tab)[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(tab[i][j] == ' ') return false;
        }
    }
    return true;
}

Tabuleiro::Tabuleiro() : qtdLinhas(3), qtdColunas(3) {
    preencherTabuleiro3por3ComChar(' ', tabuleiro);
}

bool Tabuleiro::validaJogada(int linha, int coluna, char simbolo){
    if (simbolo != 'X' && simbolo != 'O') return false;

    if (linha < 0 || linha >= this->qtdLinhas) return false; 
    if (coluna < 0 || linha >= this->qtdColunas) return false; 
    if (Tabuleiro::tabuleiro[linha][coluna] != ' ') return false;


    return true;
}

void Tabuleiro::fazerJogada(int linha, int coluna, char simbolo){
    this->tabuleiro[linha][coluna] = simbolo;
}

char Tabuleiro::verificarEstadoPartida(){
    if (verificarSeSimboloGanhouGeral(Tabuleiro::tabuleiro, 'X') == true) return 'X';
    if (verificarSeSimboloGanhouGeral(Tabuleiro::tabuleiro, 'O') == true) return 'O';
    if (verificarSeTabuleiroEncheu(Tabuleiro::tabuleiro) == true) return 'E';
    return 'P';

}

void Tabuleiro::imprimir() {
    for (int i = 0; i < 3; i++) {
        std::cout << " " << tabuleiro[i][0] << " | "
                  << tabuleiro[i][1] << " | "
                  << tabuleiro[i][2] << "\n";
        if (i < 2)
            std::cout << "-----------\n";
    }
}

// Tabuleiro::~Tabuleiro(){
//     std::cout << "Descontruindo Tabuleiro" << std::endl;
// }