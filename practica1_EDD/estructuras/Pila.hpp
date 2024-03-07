//
// Created by giovanic on 3/03/24.
//

#ifndef PRACTICA1_EDD_PILA_HPP
#define PRACTICA1_EDD_PILA_HPP

#include "Nodo.hpp"

class Pila {
private:
    Nodo *cima;
public:

    int contador();
    void push(const Carta& carta);
    Carta pop();

    Pila();

    Nodo *getCima();

    void mostrar();
    bool vacia();

    virtual ~Pila();
};

#endif //PRACTICA1_EDD_PILA_HPP
