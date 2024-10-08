#include <iostream> 
#include <vector>
#include <cmath>

double calcula_media(const std::vector<double>& numeros){
    double soma = 0; 
    for (double num : numeros) {
        soma += num;
    }
    return soma/numeros.size();
}

double calcula_desvio_padrao(const std::vector<double>& numeros, double media) {
    double soma2 = 0;
    for (double num : numeros) {
        soma2 += (num - media)*(num - media);
    }
    return std::sqrt(soma2/numeros.size());
}

int main() {
    int n;

    std::cout << "Digite a quantidade de números: ";
    std::cin >> n;
    std::vector<double> numeros(n);

    std::cout << "Digite os números separados por espaço: ";
    for (int i = 0; i < n; i++) {
        std::cin >> numeros[i];
    }

    double media = calcula_media(numeros);
    double desvio_padrao = calcula_desvio_padrao(numeros, media);
    
    std::cout.precision(4);
    std::cout << std::fixed;
    std::cout << media << std::endl; // Exibe a média
    std::cout << desvio_padrao << std::endl; // Exibe o desvio padrão

}