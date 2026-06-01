#pragma once
// Inclua as bibliotecas necessárias
#include <string>
#include <stdexcept>

// Implemente a classe EstoqueInsuficienteException.
// Como garantir que ela seja um 'runtime_error'?
class EstoqueInsuficienteException : public std::runtime_error{
private:
    // Defina os atributos _nome_item (string) e _disponivel e _pedido (inteiros)
    std::string _nome_item;
    int _qtd_disponivel;
    int _qtd_pedido;
    std::string _mensagem_completa;
public:
    EstoqueInsuficienteException(std::string& mensagem, std::string nome_item, int _disponivel, int _pedido);
    // Implemente o construtor de EstoqueInsuficienteException()
    // Garanta que os atributos sejam corretamente inicializados, incluindo
    // o construtor de runtime_error()

    // Implemente o método what()
    const char* what() const noexcept override;

    // Implemente os metodos nome_item(), disponivel(), pedido()
    std::string getNomeItem() const;
    int getQtdDisponivel() const;
    int getQtdPedido() const;

};
