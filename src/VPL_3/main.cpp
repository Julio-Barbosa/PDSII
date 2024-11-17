#include "Onibus.hpp"
#include "Empresa.hpp"
#include <iostream>
#include <string>

int main() {
    Empresa empresa;
    std::string comando;

    while (std::cin >> comando) {
        if (comando == "C") {
            std::string placa;
            int capacidade;
            std::cin >> placa >> capacidade;
            if (empresa.adicionar_onibus(placa, capacidade)) {
                std::cout << "novo onibus cadastrado\n";
            } else {
                std::cout << "ERRO : onibus repetido\n";
            }
        } else if (comando == "S") {
            std::string placa;
            int num_pessoas;
            std::cin >> placa >> num_pessoas;
            Onibus* onibus = empresa.busca_onibus(placa);
            if (onibus) {
                if (onibus->subir_passageiros(num_pessoas)) {
                    std::cout << "passageiros subiram com sucesso\n";
                } else {
                    std::cout << "ERRO : onibus lotado\n";
                }
            } else {
                std::cout << "ERRO : onibus inexistente\n";
            }
        } else if (comando == "D") {
            std::string placa;
            int num_pessoas;
            std::cin >> placa >> num_pessoas;
            Onibus* onibus = empresa.busca_onibus(placa);
            if (onibus) {
                if (onibus->descer_passageiros(num_pessoas)) {
                    std::cout << "passageiros desceram com sucesso\n";
                } else {
                    std::cout << "ERRO : faltam passageiros\n";
                }
            } else {
                std::cout << "ERRO : onibus inexistente\n";
            }
        } else if (comando == "T") {
            std::string placa1, placa2;
            int num_pessoas;
            std::cin >> placa1 >> placa2 >> num_pessoas;
            Onibus* onibus1 = empresa.busca_onibus(placa1);
            Onibus* onibus2 = empresa.busca_onibus(placa2);
            if (onibus1 && onibus2) {
                if (onibus1->transfere_passageiros(onibus2, num_pessoas)) {
                    std::cout << "transferencia de passageiros efetuada\n";
                } else {
                    std::cout << "ERRO : transferencia cancelada\n";
                }
            } else {
                std::cout << "ERRO : onibus inexistente\n";
            }
        } else if (comando == "I") {
            empresa.imprimir_estado();
        } else if (comando == "F") {
            break;
        }
    }

    return 0;
}
