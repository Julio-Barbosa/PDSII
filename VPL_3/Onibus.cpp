#include "Onibus.hpp"
#include <iostream>

Onibus::Onibus(const std::string& placa, int capacidade_maxima) 
    : placa(placa), capacidade_maxima(capacidade_maxima), lotacao_atual(0) {}

bool Onibus::subir_passageiros(int num_pessoas) {
    if (lotacao_atual + num_pessoas > capacidade_maxima) {
        return false; // Excede a capacidade máxima
    }
    lotacao_atual += num_pessoas;
    return true;
}

bool Onibus::descer_passageiros(int num_pessoas) {
    if (lotacao_atual - num_pessoas < 0) {
        return false; // Faltam passageiros
    }
    lotacao_atual -= num_pessoas;
    return true;
}

bool Onibus::transfere_passageiros(Onibus* outro_onibus, int num_pessoas) {
    if (lotacao_atual < num_pessoas || outro_onibus->lotacao_atual + num_pessoas > outro_onibus->capacidade_maxima) {
        return false; // Transferência inválida
    }
    lotacao_atual -= num_pessoas;
    outro_onibus->lotacao_atual += num_pessoas;
    return true;
}

void Onibus::imprimir_estado() const {
    std::cout << placa << " (" << lotacao_atual << "/" << capacidade_maxima << ")\n";
}

const std::string& Onibus::getPlaca() const { return placa; }
int Onibus::getLotacaoAtual() const { return lotacao_atual; }
int Onibus::getCapacidadeMaxima() const { return capacidade_maxima; }
