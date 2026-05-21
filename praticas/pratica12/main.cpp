#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#include "Grid.h"
#include "Capybara.h"
#include "Jaguar.h"

// g++ -g -std=c++11 -Wall -Wextra main.cpp Grid.cpp Jaguar.cpp Organismo.cpp Capybara.cpp -o main

int main() {
    int N, M, T;
    std::cin >> N >> M >> T;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Grid grid(N, M);

    std::string string_input;
    char charOrg;


    for (int i = 0; i < N; i++) {
        getline(std::cin, string_input);
        std::stringstream ss(string_input);
        
        int j = 0;
        while ((ss >> charOrg)) {
            if(
                charOrg != '<' &&
                charOrg != '>'
            ){
                if (charOrg == 'O'){
                    Jaguar* jag = new Jaguar(i, j);
                    grid.set(jag);
                    j++;
                }
                else if (charOrg == 'C'){
                    Capybara* cap = new Capybara(i, j);
                    grid.set(cap);
                    j++;
                }
                else {
                    grid.set(i, j, nullptr);
                    j++;
                }
            }
        } 

    }

    int turno = 0;
    while (turno < T){
        grid.resetMoved();
        grid.simulateRound('O');
        grid.simulateRound('C');

        turno++;
    }

    std::cout << grid;

    // Leitura do grid inicial
    // Para cada célula, instancie o organismo correto e insira no grid
    // OK

    // Loop de simulação — T turnos
    // A cada turno:
    //   1. resete a flag de movimento de todos os organismos
    //   2. todos os predadores agem primeiro
    //   3. todas as presas agem depois
    // OK

    // Imprima o estado final do grid
    // TODO

    return 0;
}

