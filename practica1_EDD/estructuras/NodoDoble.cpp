//
// Created by giovanic on 3/03/24.
//

#include "NodoDoble.hpp"

NodoDoble::NodoDoble() {}

NodoDoble::NodoDoble(const Carta &dato) : dato(dato) {}

NodoDoble::~NodoDoble() {}

const Carta &NodoDoble::getDato() const { return dato; }

void NodoDoble::setDato(const Carta &dato) { NodoDoble::dato = dato; }

NodoDoble *NodoDoble::getSiguiente() const { return siguiente; }

void NodoDoble::setSiguiente(NodoDoble *siguiente) { NodoDoble::siguiente = siguiente; }

NodoDoble *NodoDoble::getAnterior() const { return anterior; }

void NodoDoble::setAnterior(NodoDoble *anterior) { NodoDoble::anterior = anterior; }

string NodoDoble::mostrar() {
    return this->dato.representar();
}
