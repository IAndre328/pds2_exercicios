#include "comunicacao.hpp"
#include <string>



    Comunicacao::Comunicacao(){}

    std::string Comunicacao::gerarRelatorio(int posicao, int bateria, bool completou_missao){
        std::string statusFormatado = completou_missao ? "Concluida" : "Pendente";
        std::string relatorio = "R2D2 em " + std::to_string(posicao) + 
        ", Bateria: " + std::to_string(bateria) + "%, Missao: " + statusFormatado;

        return relatorio;
    }

    bool Comunicacao::enviarSinal(std::string mensagem, int bateria, bool completou_missao){
        if (
            completou_missao == true &&
            bateria >= 5
        )   
            return true;
        
        else return false;

    }


