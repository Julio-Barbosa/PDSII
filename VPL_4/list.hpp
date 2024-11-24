
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.hpp"

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void insertNode(int data);
    void display();
    void inverte();
    void misterio();
};
#endif
