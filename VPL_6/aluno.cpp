#include "aluno.hpp"

Aluno::Aluno() : matricula(0) {}

Aluno::Aluno(const std::string& nome, int matricula, const std::vector<int>& notas)
    : nome(nome), matricula(matricula), notas(notas) {}

std::string Aluno::getNome() const {
    return nome;
}

void Aluno::setNome(const std::string& nome) {
    this->nome = nome;
}

int Aluno::getMatricula() const {
    return matricula;
}

void Aluno::setMatricula(int matricula) {
    this->matricula = matricula;
}

std::vector<int> Aluno::getNotas() const {
    return notas;
}

void Aluno::setNotas(const std::vector<int>& notas) {
    this->notas = notas;
}

void Aluno::addNota(int nota) {
    notas.push_back(nota);
}

double Aluno::calcularMedia() const {
    if (notas.empty()) {
        return 0.0;
    }
    double soma = 0;
    for (int nota : notas) {
        soma += nota;
    }
    return soma / notas.size();
}

int Aluno::notaMaxima() const {
    if (notas.empty()) {
        return 0;
    }
    return *std::max_element(notas.begin(), notas.end());
}

int Aluno::notaMinima() const {
    if (notas.empty()) {
        return 0;
    }
    return *std::min_element(notas.begin(), notas.end());
}

bool Aluno::operator<(const Aluno& other) const {
    return nome < other.nome;
}
