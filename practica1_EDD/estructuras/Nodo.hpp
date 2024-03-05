//
// Created by giovanic on 3/03/24.
//

#ifndef PRACTICA1_EDD_NODO_HPP
#define PRACTICA1_EDD_NODO_HPP

#include "../Carta.hpp"

class Nodo {
private:
    Carta dato;
    Nodo *siguiente;
public:
    explicit Nodo(const Carta &dato);

    const Carta &getDato() const;

    void setDato(const Carta &dato);

    Nodo *getSiguiente() const;

    void setSiguiente(Nodo *siguiente);
    string mostrar();
};

#endif //PRACTICA1_EDD_NODO_HPP
