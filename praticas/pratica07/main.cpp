// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_controle.hpp"

// g++ -std=c++11 -Wall main.cpp Processo.cpp FilaProcessos.cpp -o main

#include <sstream>
#include <limits>

void limpa_buffer_entrada(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Fazer função para liberar os cara
void deletar_valor_excluido(Processo* processo){
    delete processo;
}

void deletar_array_processos(FilaProcessos* arrayProcessos){
    Processo* temp_processo_atual = arrayProcessos->head;
    Processo* temp_processo_proximo = nullptr;

    while (temp_processo_atual != nullptr){
        temp_processo_proximo = temp_processo_atual->_next;
        deletar_valor_excluido(temp_processo_atual);
        temp_processo_atual = temp_processo_proximo;
    }
    delete arrayProcessos;
}

int main() {

    //
    // Adicione seu código aqui e faça as demais alterações necessárias
    //

    FilaProcessos* arrayProcessos = new FilaProcessos;

    bool done = false;

    int temp_id = 0;
    int temp_prioridade = 0;
    std::string temp_nome;
    Processo* processo_a_ser_excluido = nullptr;


    while (done == false){

        std::string string_input;

        //Importante: verificar se conseguiu ler a linha
        if (!std::getline(std::cin, string_input)) {
            break; 
        }

        std::stringstream stream_input(string_input);
        char comando;

        //Importante: verificar se conseguiu ler a linha
        if (!(stream_input >> comando)) {
            continue;
        }

        //std::cout << comando << endl;

        switch (comando)
        {
        case 'a':
            stream_input >> temp_nome;
            stream_input >> temp_prioridade;

            arrayProcessos->adicionar_processo(temp_nome, temp_prioridade);
            break;
        
        case 'r':
            processo_a_ser_excluido = arrayProcessos->remover_processo_maior_prioridade();
            deletar_valor_excluido(processo_a_ser_excluido);
            break;
        
        case 'i':
            stream_input >> temp_id;
            processo_a_ser_excluido = arrayProcessos ->remover_processo_por_id(temp_id);
            deletar_valor_excluido(processo_a_ser_excluido);
            break;

        case 'p':
            arrayProcessos->imprimir_fila();
            break;

        case 'e':
            stream_input >> temp_id;
            arrayProcessos ->estimativa_tempo_para_execucao(temp_id);
            break;
        
        case 'b':
            avaliacao_basica();
            break;

        // case 'q':
        //     std::cout << "Letra q, encerrando o programa" << endl;
        //     done = true;
        //     break;

        default:
            std::cout << "Letra errada, encerrando o programa" << endl;
            done = true;
            break;
        }
        
        //limpa_buffer_entrada();
    }

    
    return 0;
}