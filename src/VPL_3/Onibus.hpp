#ifndef ONIBUS_HPP
#define ONIBUS_HPP

#include <string>

class Onibus {
private:
    std::string placa;
    int capacidade_maxima;
    int lotacao_atual;

public:
    // Construtor
    Onibus(const std::string& placa, int capacidade_maxima);

    // Métodos
    bool subir_passageiros(int num_pessoas);
    bool descer_passageiros(int num_pessoas);
    bool transfere_passageiros(Onibus* outro_onibus, int num_pessoas);
    void imprimir_estado() const;

    // Métodos de acesso
    const std::string& getPlaca() const;
    int getLotacaoAtual() const;
    int getCapacidadeMaxima() const;
};

#endif // ONIBUS_HPP
