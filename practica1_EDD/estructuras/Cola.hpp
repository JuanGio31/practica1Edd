//
// Created by giovanic on 3/03/24.
//

#ifndef PRACTICA1_EDD_COLA_HPP
#define PRACTICA1_EDD_COLA_HPP

#include "Nodo.hpp"

class Cola {
private:
    Nodo *inicio;
    Nodo *final;
public:
    Cola();

    virtual ~Cola();

    bool vacia();

    void push(const Carta &carta);

    Carta pop();

    Carta &frente() ;

    Carta &ultimo();

    void mostrar();

    string pintarPrimero() const;

    Carta cabezal() const;
};

#endif //PRACTICA1_EDD_COLA_HPP
