#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define TAM_MAX_PALAVRA 5

using namespace std;

// g++ wordle.cpp -o wordle && ./wordle

string escolher_palavra(string* banco_de_palavras, int tamanho){

    int indice_palavra_escolhida;
    //cout << "insira qual palavra quer jogar: " << endl;
    cin >> indice_palavra_escolhida;

    if (indice_palavra_escolhida > tamanho && indice_palavra_escolhida <= 0) escolher_palavra(banco_de_palavras, tamanho);

    return banco_de_palavras[indice_palavra_escolhida -1];
    
}



string extrair_arquivo(){

    string quantidade_palavras;
    int int_quantidade_palavras;

    ifstream arquivo("palavras.txt");
    
    getline(arquivo, quantidade_palavras);
    stringstream convertor(quantidade_palavras);
    convertor >> int_quantidade_palavras;

    string* palavras_todas = new string[int_quantidade_palavras];

    int arquivo_quantidade_palavras = 0;
    while (getline (arquivo, palavras_todas[arquivo_quantidade_palavras])){
        
        //cout << palavras_todas[arquivo_quantidade_palavras] << endl;
        arquivo_quantidade_palavras++;
    }

    if (arquivo_quantidade_palavras != int_quantidade_palavras){
        cout << arquivo_quantidade_palavras << " e " << int_quantidade_palavras << endl;

        cout << "erro" << endl;
        
        delete[] palavras_todas;

        return "1";
    }

    string palavra_escolhida = escolher_palavra(palavras_todas, arquivo_quantidade_palavras);


    delete[] palavras_todas;

    arquivo.close();
    return palavra_escolhida;
}

string extrair_palavra_atual(){

    string temp;
    
    //cout << "Insira sua jogada: " << endl;
    cin >> temp;

    if (temp.length() != TAM_MAX_PALAVRA)extrair_palavra_atual();
    return temp;
}

string comparar_string(string jogada, string gabarito, string* letras_erradas){

    string string_resultado = "*****";

    for (int i = 0; i < TAM_MAX_PALAVRA; i++){
        int index = gabarito.find(jogada[i]); 

        if (index == i){
            string_resultado[i] = jogada[i];
            // cout << string_resultado[i] << endl;
        } else if (index < TAM_MAX_PALAVRA  && index > -1){
            string_resultado[i] = (jogada[i] | 32);
            // cout << string_resultado[i] << endl;
        } else if (index == -1){

            cout << letras_erradas->find(jogada[i]);
            if (letras_erradas->find(jogada[i]) == -1)

                *letras_erradas += jogada[i];
            
            // cout << "jogada errada: " << letras_erradas[0] << endl;
        }
        // cout << "INDICE " << i << endl;
    
    }
    
    // for (int j = 0; j < TAM_MAX_PALAVRA; j++){
    //     cout << string_resultado[j];
    // }
    // cout << endl;

    return string_resultado;
}

int main(){

    string palavra_jogo = extrair_arquivo();
    string letras_erradas;
    bool jogo_ganho = false;
    int rodada_atual = 1;
    int max_rodadas = 5;

    if (palavra_jogo == "1") return 1;

    //cout << palavra_jogo << endl;

    while (jogo_ganho == false && rodada_atual <= max_rodadas){
        string palavra_atual;
        palavra_atual = extrair_palavra_atual();

        string resultado = comparar_string(palavra_atual, palavra_jogo, &letras_erradas);

        cout << resultado << " (" << letras_erradas << ")" << endl;
        
        if (palavra_atual == palavra_jogo) jogo_ganho = true;

        rodada_atual++;
    }
   
    if (jogo_ganho == true){
        cout << "GANHOU!"; 
    } else {
        cout << "PERDEU!" << palavra_jogo << endl;
    }

    return 0;
}
