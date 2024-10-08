#include <iostream>
#include <algorithm>
#include <string>

bool Palindromo(const std::string& text){
    std::string clear;

    for (char x : text) {
        if (x != ' ') {
            clear += std::tolower(x);
        }
    }

    std::string reverso = clear;
    std::reverse(reverso.begin(), reverso.end());

    return clear == reverso;
}

int main() {
    std::string entrada;

    std::getline(std::cin, entrada);

    if (Palindromo(entrada)) {
        std::cout << "SIM" << std::endl;
    } else  {
        std::cout << "NÃO" << std::endl;
    }
}