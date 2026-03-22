#include "Processo.hpp"
#include <iostream>

int Processo::getID(){
        return this->_id;
}

int Processo::getPrioridade(){
    return this->_prioridade;
}

std::string Processo::getNome(){
        return this->_nome;
    }

Processo::Processo(int id, std::string nome, int prioridade){
        this->_id = id;
        this->_nome = nome;

        //if (prioridade < 0 && prioridade > 2) exit(1);
        this->_prioridade = prioridade;
}

double Processo::tempo_reservado_processo(){
    double tempo_minimo = 0.5;

    if (this->_prioridade > 1) return this->_prioridade + 2 * tempo_minimo;
    else return this->_prioridade + tempo_minimo;
}

std::string Processo::converter_prioridade_em_texto(int prioridade){
    std::string array_prioridades_em_texto[] = {
        "BAIXA",
        "MEDIA",
        "ALTA"
    };
    return array_prioridades_em_texto[prioridade];
}

void Processo::imprimir_dados(){
    std::string prioridade_em_texto = converter_prioridade_em_texto(this->_prioridade);
std::cout << this->_id << " " << this->_nome << " " << prioridade_em_texto << std::endl;}