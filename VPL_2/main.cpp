#include <iostream>
#include <vector>

// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por valor
//    - A segunda deve ser passada por referência 
//    - A terceira deve ser passada "por referência" usando apontadores (passagem "por referência" disponível em C)
//    A função deverá somar 1 ao valor de cada uma das 3 variáveis e retornar.
void acrescentar(int a, int& b, int* c){
    a += 1;
    b += 1;
    (*c) += 1;
}

int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int valor;
    std::cout << "";
    std::cin >> valor;
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int* ptr = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int tamanho;
    std::cout << "";
    std::cin >> tamanho;

    std::vector<int> vetor(tamanho);

    
    for (int i=0; i < tamanho; i++) {
        std::cout << "";
        std::cin >> vetor[i];
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    std::cout << &valor << std::endl;
    
    // 5) Imprima o VALOR da variável declarada em (1)
    std::cout << valor << std::endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    std::cout << &ptr << std::endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    std::cout << ptr << std::endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    std::cout << &vetor << std::endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    std::cout << &vetor[0] << std::endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    std::cout << vetor[0] << std::endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    ptr = &valor;

    // 12) Imprima o VALOR da variável declarada em (2)
    std::cout << ptr << std::endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *ptr << std::endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *ptr = 5;

    // 15) Imprima o VALOR da variável declarada em (1)
    std::cout << valor << std::endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    ptr = &vetor[0];

    // 17) Imprima o VALOR da variável declarada em (2)
    std::cout << ptr << std::endl;

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *ptr << std::endl;

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    ptr = &vetor[0];

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    if (ptr == &vetor[0]) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }

    // 21) Imprima o VALOR da variável declarada em (2)
    std::cout << ptr << std::endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *ptr << std::endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < tamanho; i++) {
        *(ptr + i) *= 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    std::cout << "";
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    std::cout << "";
    for (int i = 0; i < tamanho; i++) {
        std::cout << *(vetor.data() + i) << " ";
    }
    std::cout << std::endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    std::cout << "";
    for (int i = 0; i < tamanho; i++) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    ptr = &vetor[tamanho - 1];

    // 28) Imprima o VALOR da variável declarada em (2)
    std::cout << ptr << std::endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *ptr << std::endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int** pptr = &ptr;

    // 31) Imprima o VALOR da variável declarada em (30)
    std::cout << pptr << std::endl;

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    std::cout << &pptr << std::endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    std::cout << *pptr << std::endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    std::cout << **pptr << std::endl;

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int var1, var2, var3;
    std::cout << "";
    std::cin >> var1 >> var2 >> var3;

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    acrescentar(var1, var2, &var3);
    
    // 37) Imprima o valor das 3 variáveis criadas em (35)
    std::cout << var1 << " " << var2 << " " << var3 << " " << std::endl;
    
    return 0;
}