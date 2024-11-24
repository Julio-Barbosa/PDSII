#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

// Função para converter uma string para minúsculas
string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Função para processar o arquivo e contar as palavras
void countWords(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }

    map<string, int> wordCount;
    string line;

    // Processa o arquivo linha por linha
    while (getline(file, line)) {
        // Substitui todos os caracteres não alfanuméricos (exceto espaços) por espaços
        replace_if(line.begin(), line.end(), [](char c) { return !isalnum(c); }, ' ');

        // Converte a linha para minúsculas
        line = toLowerCase(line);

        // Usa um stream para separar as palavras
        stringstream ss(line);
        string word;
        while (ss >> word) {
            wordCount[word]++;
        }
    }

    file.close();

    // Exibe as palavras e suas contagens em ordem alfabética
    for (const auto& [key, value] : wordCount) {
        cout << key << " " << value << endl;
    }
}

int main() {
    string filename;

    cout << "Digite o nome do arquivo: ";
    cin >> filename;

    countWords(filename);

    return 0;
}
