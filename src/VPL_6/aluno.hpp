#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include <vector>
#include <algorithm>

class Aluno {
private:
    std::string nome;
    int matricula;
    std::vector<int> notas;

public:
    // Construtores
    Aluno();
    Aluno(const std::string& nome, int matricula, const std::vector<int>& notas);

    // Métodos de acesso
    std::string getNome() const;
    void setNome(const std::string& nome);

    int getMatricula() const;
    void setMatricula(int matricula);

    std::vector<int> getNotas() const;
    void setNotas(const std::vector<int>& notas);
    void addNota(int nota);

    // Métodos para cálculos
    double calcularMedia() const;
    int notaMaxima() const;
    int notaMinima() const;

    // Operador para ordenação
    bool operator<(const Aluno& other) const;
};

#endif // ALUNO_HPP
