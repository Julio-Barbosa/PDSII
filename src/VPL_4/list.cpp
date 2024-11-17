// src/list.cpp

#include "../include/list.hpp"

void List::Inverte() {
    Node* prev = nullptr;
    Node* current = this->head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->getNext();   // Armazena o próximo nó
        current->setNext(prev);      // Inverte o apontador do nó atual
        prev = current;              // Move 'prev' para o nó atual
        current = next;              // Avança para o próximo nó
    }
    this->head = prev;               // Atualiza o cabeçalho da lista
}
