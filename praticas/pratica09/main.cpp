#include "Defesa.hpp"
#include "Canhao.hpp"
#include "CanhaoOrbital.hpp"
#include "BaseMilitar.hpp"
#include "LancadorMissil.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

// g++ -std=c++11 -Wall main.cpp Defesa.cpp Canhao.cpp CanhaoOrbital.cpp LancadorMissil.cpp BaseMilitar.cpp -o main

int main(int argc, char const *argv[])
{
    std::cout << std::fixed << std::setprecision(2);

    BaseMilitar baseMilitar1;  
    std::vector<double> vidaInimigos;
    
    int id;
    double energia;
    double intensidade;
    double gravidade;
    int qtdMisseis;
    
    int done = false;
    while (done != true){

        std::string string_input;

        if (!std::getline(std::cin, string_input)) {
            break; 
        }

        std::stringstream stream_input(string_input);
        char comando;

        if (!(stream_input >> comando)) {
            continue;
        }

        //std::cout << comando << std::endl;

        switch (comando)
        {
            case 'c': {
                stream_input >> id;
                stream_input >> energia;
                stream_input >> intensidade;

                Canhao* canhao = new Canhao(id, energia, intensidade);
                baseMilitar1.adicionarDefesa(canhao);
                //std::cout << "Adicionei Canhão" << std::endl;
                break;
            }
            case 'o':{
                stream_input >> id;
                stream_input >> energia;
                stream_input >> intensidade;
                stream_input >> gravidade;


                CanhaoOrbital* canhaoorbital = new CanhaoOrbital(id, energia, intensidade, gravidade);
                baseMilitar1.adicionarDefesa(canhaoorbital);
                break;
            }
            case 'm':{
                stream_input >> id;
                stream_input >> energia;
                stream_input >> qtdMisseis;

                LancadorMissil* lancadormissil = new LancadorMissil(id, energia, qtdMisseis);
                baseMilitar1.adicionarDefesa(lancadormissil);
                break;

            }
            case 'd':{
                double vida;
                stream_input >> vida;
                vidaInimigos.push_back(vida);

                int i = 0;
                while (vidaInimigos[i] < 0) i++;

                baseMilitar1.defender(vidaInimigos[i]);
                break;
            }
            case 's':
                done = true;
                break;

            default:
                break;
        }

    }

    
    
    return 0;
}
