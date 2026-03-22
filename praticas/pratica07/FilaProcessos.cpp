#include <iostream>
#include <iomanip>

#include "FilaProcessos.hpp"

Processo* FilaProcessos::retorna_endereco_ultimo_da_prioridade(int prioridade){
    if (this->head == nullptr) return nullptr;

    Processo* processo_anterior = nullptr;
    Processo* processo_atual = this->head;

    while (
        processo_atual != nullptr &&
        processo_atual->getPrioridade() >= prioridade 
    ){
        processo_anterior = processo_atual;
        processo_atual = processo_atual->_next;
    }

    return processo_anterior;
}

void FilaProcessos::adicionar_processo(std::string nome, int prioridade){

    Processo* processo_a_ser_adicionado = new Processo(id_criacao, nome, prioridade);

    if (
        this->head == nullptr || 
        prioridade > this->head->getPrioridade()
    ){
        processo_a_ser_adicionado->_next = this->head;
        this->head = processo_a_ser_adicionado;
        if (this->tail == nullptr){
            this->tail = processo_a_ser_adicionado;
        }
        this->id_criacao++;
        return;
    }

    Processo* endereco_ultimo_da_prioridade = retorna_endereco_ultimo_da_prioridade(processo_a_ser_adicionado->getPrioridade());
    processo_a_ser_adicionado->_next = endereco_ultimo_da_prioridade->_next;

    endereco_ultimo_da_prioridade->_next = processo_a_ser_adicionado;

    if(processo_a_ser_adicionado->_next == nullptr) this->tail = processo_a_ser_adicionado;

    this->id_criacao++;
}

Processo* FilaProcessos::remover_processo_maior_prioridade(){
    
    Processo* processo_atual = this->head;

    if (this->head == nullptr) return nullptr;

    this->head = processo_atual->_next;

    if (this->head == nullptr) this->tail = nullptr;

    processo_atual->_next = nullptr;
    return processo_atual;
}

Processo* FilaProcessos::remover_processo_por_id(int id){
    Processo* processo_anterior = nullptr;
    Processo* processo_atual = this->head;

    while (processo_atual != nullptr && processo_atual->getID() != id) {
        processo_anterior = processo_atual;
        processo_atual = processo_atual->_next;
    }

    if (processo_atual == nullptr) return nullptr;

    if (processo_atual == this->head){
        this->head = processo_atual->_next;
    }
    else {
        processo_anterior->_next = processo_atual->_next;
    }

    if (processo_atual == this->tail){
        this->tail = processo_anterior;
    }
    
    processo_atual->_next = nullptr;
    return processo_atual;

}

void FilaProcessos::estimativa_tempo_para_execucao(int id){
    Processo* processo_atual = this->head;
    double estimativa_tempo = 0;

    while (processo_atual != nullptr && processo_atual->getID() != id)
    {
        estimativa_tempo += processo_atual->tempo_reservado_processo();
        processo_atual = processo_atual->_next;
    }

    if (processo_atual == nullptr){
        std::cout << "Tarefa não existe" << std::endl;
        return;
    }

    //estimativa_tempo += processo_atual->tempo_reservado_processo();

    

    std::cout << "Tempo estimado para execução do processo " << processo_atual->getNome() 
              << " (id=" << processo_atual->getID() << ") eh " 
              << std::fixed << std::setprecision(1) << estimativa_tempo
              << " segundos." << std::endl;
    
}

void FilaProcessos::imprimir_fila(){

    Processo* processo_atual = this->head;

    while (processo_atual != nullptr)
    {
        processo_atual->imprimir_dados();
        processo_atual = processo_atual->_next;
    }
    
}