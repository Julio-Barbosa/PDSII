#include "Empresa.hpp"
#include <iostream>

Empresa::Empresa() : num_onibus(0) {
    for (int i = 0; i < 20; ++i) {
        onibus[i] = nullptr;
    }
}

Onibus* Empresa::adicionar_onibus(const std::string& placa, int capacidade_maxima) {
    if (num_onibus >= 20) return nullptr;

    for (int i = 0; i < num_onibus; ++i) {
        if (onibus[i]->getPlaca() == placa) {
            return nullptr;
        }
    }

    onibus[num_onibus] = new Onibus(placa, capacidade_maxima);
    return onibus[num_onibus++];
}

Onibus* Empresa::busca_onibus(const std::string& placa) {
    for (int i = 0; i < num_onibus; ++i) {
        if (onibus[i]->getPlaca() == placa) {
            return onibus[i];
        }
    }
    return nullptr;
}

void Empresa::imprimir_estado() const {
    for (int i = 0; i < num_onibus; ++i) {
        onibus[i]->imprimir_estado();
    }
}
