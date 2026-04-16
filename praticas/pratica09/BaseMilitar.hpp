#ifndef BASE_MILITAR_HPP
#define BASE_MILITAR_HPP

#include "CanhaoOrbital.hpp"
#include "LancadorMissil.hpp"

#define LIMITE_DEFESAS 100

class BaseMilitar
{
private:
    Defesa* _defesas[LIMITE_DEFESAS];
    int _qtdAtual;
public:
    BaseMilitar() : _defesas{}, _qtdAtual(0) {}

    void adicionarDefesa(Defesa* d);
    void defender(double &saudeInimigo);


   virtual ~BaseMilitar();
};

#endif