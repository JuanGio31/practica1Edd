//
// Created by giovanic on 3/03/24.
//

#include "Pila.hpp"


void Pila::push(const Carta &carta) {
    Nodo *nuevo = new Nodo(carta);
    if (vacia()) {
        cima = nuevo;
        nuevo->setSiguiente(nullptr);
    } else {
        nuevo->setSiguiente(cima);
        cima = nuevo;
    }
}

Carta Pila::pop() {
    if (!vacia()) {
        Carta temp = cima->getDato();
        Nodo *del = cima;
        cima = cima->getSiguiente();
       // delete del;
        return temp;
    } else {
        throw "Error-> Pila vacia!";
    }
}

void Pila::mostrar() {
    if (vacia()) {
        cout << "Pila vacia!" << endl;
    } else {
        Nodo *curr = cima;
        cout << "Listado de todos los elementos de la pila." << endl;
        while (curr != nullptr) {
            cout << curr->mostrar() << " - ";
            curr = curr->getSiguiente();
        }
        cout << endl;
    }
}

Pila::Pila() { cima = nullptr; }

bool Pila::vacia() {
    if (cima == nullptr) {
        return true;
    }
    return false;
}

Pila::~Pila() { while (!vacia()) { pop(); }}

int Pila::contador() {
    if (vacia()) {
        cout << "La lista esta vacia";
    } else {
        int cont = 0;
        Nodo *curr = cima;
        while (curr != nullptr) {
            curr = curr->getSiguiente();
            cont++;
        }
        return cont;
    }
    return 0;
}

Nodo *Pila::getCima() { return cima; }
