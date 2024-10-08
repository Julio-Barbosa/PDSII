// VLP 1 - WORDLE

#include <iostream>
#include <fstream>  
#include <string>  
#include <vector> 
#include <set>

int main() {

    // Iterar sobre o arquivo
    std::ifstream arquivo("palavras.txt");

    int n;
    arquivo >> n;
    std::vector<std::string> palavras(n);

    for (int i = 0; i < n;i++){
        arquivo >> palavras[i];
    }
    arquivo.close();

    // Pedir usuário para escolher um número

    int escolha;
    std::cout << "Escolha um número entre 1 e " << n << ": ";
    std::cin >> escolha;

    std::string chave = palavras[escolha - 1]; // Palavra chave

    // Armazenas as letras não presentes

    std::set<char> letras_nao_presentes;

    // Pedir o usuário para acertar a palavra dentro de 5 tentativas
    
    for (int tentativas = 0; tentativas < 5; tentativas++) {
        std::string tentativa;
        std::cout << "Tentativa " << (tentativas + 1) << "/5. Tente adivinhar a palavra (tem 5 letras): ";
        std::cin >> tentativa;

        // Se acertou...
        if (tentativa == chave) {
            std::cout << "GANHOU!" << std::endl;
            return 0;
        }

        // Se não...
        std::string resultado;
        for (int i=0; i < 5; i++) {
            if (tentativa[i] == chave[i]) {
                resultado += std::toupper(tentativa[i]);
            } 
            else if (chave.find(tentativa[i]) != std::string::npos) {
                resultado += std::tolower(tentativa[i]);
            } 
            else {
                resultado += '*';
                letras_nao_presentes.insert(tentativa[i]);
            }
        }

        // Exibir letras não presentes

        std::cout << resultado << " (";
        for (char letra : letras_nao_presentes) {
            std::cout << letra;
        }
        std::cout << ")" << std::endl;
    }
    
    std::cout << "PERDEU!"" " << chave << std::endl;
    return 0;

}