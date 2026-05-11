#include "energia.hpp"

Energia::Energia(int carga_inicial):carga_(carga_inicial){
    if (carga_inicial < 0) carga_ = 0;
}


int Energia::getCarga() const {
    return this->carga_;
}

void Energia::consumir(int quantidade) {
    if (this->carga_ <= quantidade) this->carga_ = 0;
    else if (quantidade < 0) return;
    else carga_ -= quantidade;
}