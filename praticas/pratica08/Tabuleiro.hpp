#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

class Tabuleiro{
    private:
        int qtdLinhas;
        int qtdColunas;
        char tabuleiro[3][3];

    public:
    Tabuleiro();
    void preencherTabuleiro3por3ComChar(char c, char (&tab)[3][3]);

    bool validaJogada(int linha, int coluna, char simbolo);
    void fazerJogada(int linha, int coluna, char simbolo);

    bool verificarSeSimboloGanhouDiagonal(char (&tab)[3][3], char simbolo);
    bool verificarSeSimboloGanhouColuna(char (&tab)[3][3], char simbolo);
    bool verificarSeSimboloGanhouLinha(char (&tab)[3][3], char simbolo);
    bool verificarSeSimboloGanhouGeral(char (&tab)[3][3], char simbolo);
    bool verificarSeTabuleiroEncheu(char (&tab)[3][3]);
    char verificarEstadoPartida();

    void imprimir();


    //~Tabuleiro();
};

#endif