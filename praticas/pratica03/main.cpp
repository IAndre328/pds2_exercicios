#include <iostream>


using namespace std;

// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por referência 
//    - A segunda deve ser passada "por referência" usando apontadores (passgem "por referência" disponível em C)
//    - A terceira deve ser passada por valor
//   A função deverá incrementar em 1 o valor das 3 variáveis e retornar.


void somar3parametros(int &n1, int* n2, int n3){
    n1++;
    (*n2)++;
    n3++;
}

int main(){
    

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int ex1 = 0;
    cin >> ex1;
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int* ex2 = NULL;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int tam_ex3 = 0;
    cin >> tam_ex3;
    
    int ex3[tam_ex3];
    for (int i = 0; i < tam_ex3; i++){
        cin >> ex3[i];
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &ex1 << endl;
    

    // 5) Imprima o VALOR da variável declarada em (1)
    int ex5 = ex1;
    cout << ex5 << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &ex2 << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << ex2 << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &ex3 << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &(ex3[0]) << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << ex3[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    ex2 = &ex1;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << ex2 << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << (*ex2) << endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    (*ex2) = 5;

    // 15) Imprima o VALOR da variável declarada em (1)
    cout << ex1 << endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    ex2 = ex3;

    // 17) Imprima o VALOR da variável declarada em (2)
    cout << ex2 << endl;

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ex2 << endl;

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    ex2 = &(ex3[0]);

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    cout << (ex2 == ex3 ? 'S' : 'N') << endl;

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << ex2 << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ex2 << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < tam_ex3; i++){
        ex2[i] *= 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for (int i = 0; i < tam_ex3; i++){
        cout << ex3[i] << " ";
    }
    cout << endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for (int i = 0; i < tam_ex3; i++){
        cout << (*(ex3 + i)) << " ";
    }
    cout << endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    for (int i = 0; i < tam_ex3; i++){
        cout << (*(ex2 + i)) << " ";
    }
    cout << endl;

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    ex2 = &(ex3[tam_ex3 -1]);

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << ex2 << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ex2 << endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int** ex30 = & ex2;

    // 31) Imprima o VALOR da variável declarada em (30)
    cout << ex30 << endl;

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << &ex30 << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << *ex30 << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << **ex30 << endl;

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int ex35_1, ex35_2, ex35_3;
    cin >> ex35_1;
    cin >> ex35_2;
    cin >> ex35_3;

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    somar3parametros(ex35_1, &ex35_2, ex35_3);
    
    // 37) Imprima o valor das 3 variáveis criadas em 35, uma por linha
    cout << ex35_1 << endl;
    cout << ex35_2 << endl;
    cout << ex35_3;
    
    return 0;
}