#ifndef FILAPROCESSOS_HPP
#define FILAPROCESSOS_HPP

#include "Processo.hpp"

struct FilaProcessos{
    Processo* head = nullptr;
    Processo* tail = nullptr;
    int id_criacao = 1;
    
    void adicionar_processo(std::string nome, int prioridade);

    Processo* retorna_endereco_ultimo_da_prioridade(int prioridade);

    Processo* remover_processo_maior_prioridade(); 
    Processo* remover_processo_por_id(int id);

    void estimativa_tempo_para_execucao(int id);
    void imprimir_fila();
};

#endif