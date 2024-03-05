//
// Created by giovanic on 3/03/24.
//

#include "Cola.hpp"

Cola::Cola() {
    inicio = nullptr;
    final = nullptr;
}

bool Cola::vacia() {
    if (inicio == nullptr && final == nullptr) {
        return true;
    }
    return false;
}

Cola::~Cola() {
    while (!vacia()) {
        //eliminar cada elemento de la cola
        pop();
    }
}

Carta Cola::pop() {
    if (!vacia()) {
        ///hacer algo
        Carta carta = inicio->getDato();
        Nodo *temp = inicio;

        if (inicio == final) {
            inicio = nullptr;
            final = nullptr;
        } else {
            inicio = inicio->getSiguiente();
        }

        //delete temp;
        return carta;
    } else {
        throw "Error-> Cola vacia!";
    }
}

Carta &Cola::frente()  {
    return const_cast<Carta &>(inicio->getDato());
}

Carta Cola::cabezal() const{
    return inicio->getDato();
}

string Cola::pintarPrimero() const {
    return this->inicio->mostrar();
}

Carta &Cola::ultimo() {
    return const_cast<Carta &>(final->getDato());
}

void Cola::push(const Carta &carta) {
    Nodo *nuevo = new Nodo(carta);
    nuevo->setSiguiente(nullptr);

    if (final != nullptr) {
        final->setSiguiente(nuevo);
    }
    final = nuevo;

    if (inicio == nullptr) {
        inicio = nuevo;
    }
}

void Cola::mostrar() {
    if (vacia()) {
        cout << "Cola vacia!" << endl;
    } else {
        Nodo *curr = inicio;
        cout << "Listado de todos los elementos de la cola." << endl;
        int c = 1;  //verdadero valor inicial -> 0
        while (curr != nullptr) {
            cout << c << "- " << curr->mostrar() << endl;
            curr = curr->getSiguiente();
            c++;
        }
        cout << endl;
    }
}