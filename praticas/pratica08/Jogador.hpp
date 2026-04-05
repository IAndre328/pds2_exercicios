#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <string>

class Jogador{
    private:
        std::string nome;
        char simbolo;
        
    public:

        Jogador(std::string nome, char simbolo);

        std::string getNome() const;
        char getSimbolo() const;

        //~Jogador();
};


#endif