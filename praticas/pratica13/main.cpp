#include <iostream>
#include <string>
#include <stdexcept>

#include <ios>
#include <limits>

#include "Estoque.h"
#include "EstoqueInsuficienteException.h"

void limparBuffer(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Estoque estoque;
    std::string cmd;

    while (std::cin >> cmd && cmd != "quit") {
         // Implemente seu codigo aqui
        if (cmd == "add"){
            std::string nome;
            int qtd_inicial;
            std::cin >> nome;
            std::cin >> qtd_inicial;

            try
            {
                estoque.adicionar_item(nome, qtd_inicial);
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }
            catch(const std::domain_error& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }

            limparBuffer();

        }

        else if (cmd == "entrada"){
            int indice;
            int qtd;
            std::cin >> indice;
            std::cin >> qtd;

            try
            {
                estoque.registrar_entrada(indice, qtd);
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }
            catch(const std::out_of_range& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }

            limparBuffer();
        }

        else if (cmd == "saida"){
            int indice;
            int qtd;
            std::cin >> indice;
            std::cin >> qtd;

            try
            {
                estoque.registrar_saida(indice, qtd);
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }
            catch(const std::domain_error& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }
            catch(const EstoqueInsuficienteException& e)
            {
                std::cout << e.what() << '\n';
                std::cout << "Item: " << e.getNomeItem() << std::endl;
                std::cout << "Disponivel: " << e.getQtdDisponivel() << std::endl;
                std::cout << "Pedido: " << e.getQtdPedido() << std::endl;
                std::cin.clear();
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }

            limparBuffer();
        }

        else if (cmd == "consulta"){
            int indice;
            std::cin >> indice;

            try
            {
                estoque.consultar(indice);
            }
            catch(const std::out_of_range& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
                std::cin.clear();
            }

            limparBuffer();
        }

        else if (cmd == "list"){
            estoque.listar();
            //limparBuffer();
        }

    }



    return 0;
}
