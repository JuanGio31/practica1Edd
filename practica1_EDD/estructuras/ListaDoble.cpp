//
// Created by giovanic on 3/03/24.
//

#include "ListaDoble.hpp"

ListaDoble::ListaDoble() {
    this->longitud = 0;
    this->inicio = nullptr;
    this->ultimo = nullptr;
}

ListaDoble::~ListaDoble() {
    while (!vacia()) {
        eliminarPrimero();
    }
}

void ListaDoble::eliminarPrimero() {
    if (vacia()) {
        throw "La lista esta vacia";
    }
    if (longitud == 1) {
        inicio = nullptr;
        ultimo = nullptr;
    } else {
        NodoDoble *aux = inicio->getSiguiente();
        aux->setAnterior(nullptr);
        inicio = aux;
    }
    longitud--;
}

void ListaDoble::eliminarUltimo() {
    if (vacia()) {
        throw "Error-> La lista esta vacia!";
    }
    if (longitud == 1) {
        inicio = nullptr;
        ultimo = nullptr;
    } else {
        NodoDoble *aux = ultimo->getAnterior();
        aux->setSiguiente(nullptr);
        ultimo = aux;
    }
    longitud--;
}

void ListaDoble::addFinal(const Carta &carta) {
    if (vacia()) {
        auto *nuevo = new NodoDoble(carta);
        inicio = nuevo;
        ultimo = nuevo;
    } else {
        auto *nuevo = new NodoDoble(carta);
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
    longitud++;
}

bool ListaDoble::vacia() const {
    return this->longitud == 0;
}

Carta &ListaDoble::fin() {
    return const_cast<Carta &>(inicio->getDato());
}

Carta &ListaDoble::frente() {
    return const_cast<Carta &>(ultimo->getDato());
}

Carta &ListaDoble::obtenerContenido(int indice) {
    return const_cast<Carta &>(buscarIndice(indice).getDato());
}

NodoDoble &ListaDoble::buscarIndice(int indice) {    //indice es de 0-(tamLista-1)
    if (indice > longitud - 1 || indice < 0) {
        throw "Error> Indice fuera de rango";
    }
    int mitad = longitud / 2;
    if (indice <= mitad) {
        return buscarInicioAlUltimo(indice);
    } else {
        return buscarUltimoAlPrimero(indice);
    }
}

NodoDoble &ListaDoble::buscarUltimoAlPrimero(int indice) {
    NodoDoble *actual = ultimo;
    int cont = 0;
    while (cont < (longitud - indice - 1)) {
        NodoDoble *curr = actual->getAnterior();
        actual = curr;
        cont++;
    }
    return *actual;
}

NodoDoble &ListaDoble::buscarInicioAlUltimo(int indice) {
    NodoDoble *actual = inicio;
    int cont = 0;
    while (cont < indice) {
        NodoDoble *curr = actual->getSiguiente();
        actual = curr;
        cont++;
    }
    return *actual;
}

void ListaDoble::mostrar() {
    NodoDoble *curr = inicio;
    if (!vacia()) {
        while (curr) {
            cout << curr->mostrar() << " - ";
            curr = curr->getSiguiente();
        }
        cout << endl;
    }
    delete curr;
}

void ListaDoble::eliminar(int indice) {
    if (vacia()) {
        cout << "La lista esta vacia";
    } else {
        if (indice == 0) {
            eliminarPrimero();
        } else if (indice == (longitud - 1)) {
            eliminarUltimo();
        } else {
            NodoDoble *actual = &buscarIndice(indice);
            NodoDoble *sig = actual->getSiguiente();
            NodoDoble *ant = actual->getAnterior();
            sig->setAnterior(ant);
            ant->setSiguiente(sig);
            longitud--;
        }
    }
}

int ListaDoble::size() const {
    return this->longitud;
}

NodoDoble *ListaDoble::getInicio() const {
    return inicio;
}

void ListaDoble::addInicio(const Carta &carta) {
    auto *nuevo = new NodoDoble(carta);
    nuevo->setSiguiente(inicio);
    if (inicio != nullptr)
        inicio->setAnterior(nuevo);
    inicio = nuevo;
}
