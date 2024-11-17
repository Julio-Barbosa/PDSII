#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Abrir o arquivo e ler as palavras
    std::ifstream arquivo("palavras.txt");
    int n;
    arquivo >> n;
    std::vector<std::string> palavras(n);

    for (int i = 0; i < n; i++) {
        arquivo >> palavras[i];
    }
    arquivo.close();

    // Pedir ao usuário para escolher um número
    int escolha;
    std::cin >> escolha;

    std::string chave = palavras[escolha - 1]; // Palavra chave

    // Armazenar as letras não presentes
    std::vector<char> letras_nao_presentes;

    // Pedir ao usuário para acertar a palavra em 5 tentativas
    for (int tentativas = 0; tentativas < 5; tentativas++) {
        std::string tentativa;
        std::cin >> tentativa;

        // Verificar resultado
        std::string resultado;
        for (int i = 0; i < 5; i++) {
            if (tentativa[i] == chave[i]) {
                resultado += std::toupper(tentativa[i]);
            }
            else if (chave.find(tentativa[i]) != std::string::npos) {
                resultado += std::tolower(tentativa[i]);
            }
            else {
                resultado += '*';

                // Adicionar letra não presente se ainda não estiver na lista
                if (std::find(letras_nao_presentes.begin(), letras_nao_presentes.end(), tentativa[i]) == letras_nao_presentes.end()) {
                    letras_nao_presentes.push_back(tentativa[i]);
                }
            }
        }

        // Exibir resultado e letras não presentes
        std::cout << resultado << " (";
        for (char letra : letras_nao_presentes) {
            std::cout << letra;
        }
        std::cout << ")" << std::endl;

        // Se acertou a palavra...
        if (tentativa == chave) {
            std::cout << "GANHOU!" << std::endl; // Mostrar mensagem de vitória
            return 0;
        }
    }

    // Se não acertou...
    std::cout << "PERDEU! " << chave << std::endl; 

    return 0;
}


