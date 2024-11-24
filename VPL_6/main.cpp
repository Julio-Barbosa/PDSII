#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "aluno.hpp"

int main() {
    std::vector<Aluno> alunos;

    while (true) {
        std::string nome;
        std::getline(std::cin, nome);
        if (nome == "END") {
            break;
        }
        if (nome.empty()) continue;

        // Lê a matrícula
        std::string matricula_str;
        std::getline(std::cin, matricula_str);
        int matricula = std::stoi(matricula_str);

        // Lê as notas
        std::string notas_line;
        std::getline(std::cin, notas_line);
        std::istringstream iss(notas_line);
        std::vector<int> notas;
        int nota;
        while (iss >> nota) {
            if (nota == -1) break;
            notas.push_back(nota);
        }

        Aluno aluno(nome, matricula, notas);
        alunos.push_back(aluno);
    }

    // Ordena os alunos por nome
    std::sort(alunos.begin(), alunos.end());

    // Imprime o relatório
    for (const Aluno& aluno : alunos) {
        std::cout << aluno.getMatricula() << " " << aluno.getNome() << " ";
        std::vector<int> notas = aluno.getNotas();
        for (int nota : notas) {
            std::cout << nota << " ";
        }
        std::cout << std::endl;

        double media = aluno.calcularMedia();
        int maxNota = aluno.notaMaxima();
        int minNota = aluno.notaMinima();

        std::cout << std::fixed << std::setprecision(2) << media << " " << maxNota << " " << minNota << std::endl;
    }

    return 0;
}
