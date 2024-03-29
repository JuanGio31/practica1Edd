//
// Created by giovanic on 3/03/24.
//

#include "Nodo.hpp"

Carta &Nodo::getDato() {
    return dato;
}

void Nodo::setDato(const Carta &dato) {
    Nodo::dato = dato;
}

Nodo *Nodo::getSiguiente() const {
    return siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente) {
    Nodo::siguiente = siguiente;
}

Nodo::Nodo(const Carta &dato) : dato(dato) {}

string Nodo::mostrar() {
    return this->dato.representar();
}

string Nodo::ver() {
    return this->dato.ver();
}