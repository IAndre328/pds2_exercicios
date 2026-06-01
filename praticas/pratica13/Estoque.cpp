#include "Estoque.h"
#include "EstoqueInsuficienteException.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <memory>

// Lembre de usar EstoqueInsuficienteException nos blocos try-catch

template <typename T>
bool verificarNomesDuplicados(const T& array_itens, const std::string& nome){
    auto it = std::find_if(array_itens.begin(), array_itens.end(), [&nome](Item i) {
        return (i.nome == nome);
    });
    return it != array_itens.end();
}

void Estoque::adicionar_item(const std::string& nome, int quantidade_inicial) {
    // Implemente seu codigo aqui.
    // Lembre-se do que fazer quando a quantidade inicial for invalida, ou quando o item for duplicado !
        if(quantidade_inicial < 1){
            throw std::invalid_argument("Erro: quantidade invalida");
        }
        
        else if (verificarNomesDuplicados(this->_itens, nome) == true){
            throw std::domain_error("Erro: item duplicado");
        }

        Item newItem(nome, quantidade_inicial);
        this->_itens.push_back(newItem);
        std::cout << "OK: item " << nome << " Cadastrado" << std::endl;
    

}

void Estoque::registrar_entrada(int indice, int quantidade) {
    // Implemente seu codigo aqui.
    // Lembre-se do que fazer quando o indice ou quantidade forem invalidos !


        if(quantidade < 1){
            throw std::invalid_argument("Erro: quantidade invalida");
        }

        else if(indice >= static_cast<int>(this->_itens.size()) || indice < 0){
            throw std::out_of_range("Erro: indice invalido");
        }

        this->_itens[indice].quantidade += quantidade;
        std::cout << "OK: entrada concluida" << std::endl;
    


}

void Estoque::registrar_saida(int indice, int quantidade) {
    // Implemente seu codigo aqui.
    // Lembre-se do que fazer quando o indice ou quantidade forem invalidos !

    if(quantidade <= 0){
        throw std::invalid_argument("Erro: quantidade invalida");
    }

    else if(indice >= static_cast<int>(this->_itens.size())){
        throw std::out_of_range("Erro: indice invalido");
    }

    else if(quantidade > this->_itens[indice].quantidade){
        std::string mensagem = "Erro: estoque insuficiente";
        EstoqueInsuficienteException EIE(
            mensagem, 
            this->_itens[indice].nome,
            this->_itens[indice].quantidade,
            quantidade
        );
        throw EIE;
    }

    std::cout << "OK: saida concluida" << std::endl;
    this->_itens[indice].quantidade -= quantidade;
}

void Estoque::consultar(int indice) const {
    // Implemente seu codigo aqui.
    // Lembre-se do que fazer quando o indice for invalido !

    if(indice >= static_cast<int>(this->_itens.size())){
        throw std::out_of_range("Erro: indice invalido");
    }

    std::cout << "Nome: " << this->_itens[indice].nome << std::endl;
    std::cout << "Quantidade " << this->_itens[indice].quantidade << std::endl;
}

void Estoque::listar() const {
    // Implemente seu codigo aqui.
    // Lembre-se do que fazer quando o estoque estiver vazio !
    if (this->_itens.size() == 0){
        std::cout << "Estoque vazio!" << std::endl;
        return;
    }

    int j = 0;
    for (auto i : this->_itens){
        std::cout << "[" << j << "] "
                << i.nome << " "
                << i.quantidade
                << std::endl;
        
        j++;
    }

}


EstoqueInsuficienteException::EstoqueInsuficienteException(std::string& mensagem, std::string nome_item, int _disponivel, int _pedido)
    : std::runtime_error{mensagem}, 
    _nome_item{nome_item}, 
    _qtd_disponivel{_disponivel}, 
    _qtd_pedido{_pedido} {
        this->_mensagem_completa = mensagem + '.';
    }

const char* EstoqueInsuficienteException::what() const noexcept{
        // Podemos usar o que já está guardado na classe base
        return this->_mensagem_completa.c_str();
        //return "TESTE DE UM CABA SENDO RETIRADO A MAIS!";
}

std::string EstoqueInsuficienteException::getNomeItem() const{ return this->_nome_item; }
int EstoqueInsuficienteException::getQtdDisponivel() const{ return this->_qtd_disponivel; }
int EstoqueInsuficienteException::getQtdPedido() const{ return this->_qtd_pedido; }