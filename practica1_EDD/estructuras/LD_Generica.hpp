//
// Created by giovanic on 5/03/24.
//

#ifndef PRACTICA1_EDD_LD_GENERICA_HPP
#define PRACTICA1_EDD_LD_GENERICA_HPP

#include <iostream>

template<class T>
class LD_Generica;

template<class T>
class ND_Generico {
protected:
    T contenido;
    ND_Generico<T> *siguiente;
    ND_Generico<T> *anterior;
public:
    virtual ~ND_Generico() {}

    explicit ND_Generico(T _contenido) : contenido(_contenido) {}

    ND_Generico<T> *getSiguiente() const { return siguiente; }

    void setSiguiente(ND_Generico<T> *_siguiente) { ND_Generico::siguiente = _siguiente; }

    ND_Generico<T> *getAnterior() const { return anterior; }

    void setAnterior(ND_Generico<T> *_anterior) { ND_Generico::anterior = _anterior; }

    T getContenido() const { return contenido; }

    void setContenido(T _contenido) { ND_Generico::contenido = _contenido; }

    friend class LD_Generica<T>;
};

template<class T>
class LD_Generica {
protected:
    ND_Generico<T> *inicio;
    ND_Generico<T> *ultimo;
    int longitud{};

    ND_Generico<T> &buscarIndice(int indice);

    ND_Generico<T> &buscarInicioAlUltimo(int indice);

    ND_Generico<T> &buscarUltimoAlPrimero(int indice);

public:

    LD_Generica();

//    virtual ~LD_Generica() {
//        while (!vacia()) {
//            eliminarPrimero();
//        }
//    }

    void eliminarPrimero();

    void eliminarUltimo();

    void eliminar(int indice);

    void addFinal(const T &contenido);

    bool vacia() const;

    T &frente();

    T &fin();

    T &obtenerContenido(int indice);

    void addInicio(const T &contenido);

    int size() const;
};


template<class T>
LD_Generica<T>::LD_Generica() {
    this->longitud = 0;
    this->inicio = nullptr;
    this->ultimo = nullptr;
}

template<class T>
ND_Generico<T> &LD_Generica<T>::buscarUltimoAlPrimero(int indice) {
    ND_Generico<T> *actual = ultimo;
    int cont = 0;
    while (cont < (longitud - indice - 1)) {
        ND_Generico<T> *curr = actual->getAnterior();
        actual = curr;
        cont++;
    }
    return *actual;
}

template<class T>
int LD_Generica<T>::size() const {
    return this->longitud;
}

template<class T>
void LD_Generica<T>::addInicio(const T &contenido) {
    auto *nuevo = new ND_Generico<T>(contenido);
    nuevo->setSiguiente(inicio);
    if (inicio != nullptr)
        inicio->setAnterior(nuevo);
    inicio = nuevo;
}

template<class T>
T &LD_Generica<T>::obtenerContenido(int indice) {
    return buscarIndice(indice).contenido;
}

template<class T>
T &LD_Generica<T>::fin() {
    return const_cast<T &>(inicio->getDato());
}

template<class T>
T &LD_Generica<T>::frente() {
    return const_cast<T &>(ultimo->getDato());
}

template<class T>
bool LD_Generica<T>::vacia() const {
    return this->longitud == 0;
}

template<class T>
void LD_Generica<T>::addFinal(const T &contenido) {
    if (vacia()) {
        auto *nuevo = new ND_Generico<T>(contenido);
        inicio = nuevo;
        ultimo = nuevo;
    } else {
        auto *nuevo = new ND_Generico<T>(contenido);
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
    longitud++;
}

template<class T>
void LD_Generica<T>::eliminar(int indice) {
    if (vacia()) {
        std::cout << "La lista esta vacia";
    } else {
        if (indice == 0) {
            eliminarPrimero();
        } else if (indice == (longitud - 1)) {
            eliminarUltimo();
        } else {
            ND_Generico<T> *actual = &buscarIndice(indice);
            ND_Generico<T> *sig = actual->getSiguiente();
            ND_Generico<T> *ant = actual->getAnterior();
            sig->setAnterior(ant);
            ant->setSiguiente(sig);
            longitud--;
        }
    }
}

template<class T>
void LD_Generica<T>::eliminarUltimo() {
    if (vacia()) {
        throw "Error-> La lista esta vacia!";
    }
    if (longitud == 1) {
        inicio = nullptr;
        ultimo = nullptr;
    } else {
        ND_Generico<T> *aux = ultimo->getAnterior();
        aux->setSiguiente(nullptr);
        ultimo = aux;
    }
    longitud--;
}

template<class T>
void LD_Generica<T>::eliminarPrimero() {
    if (vacia()) {
        throw "La lista esta vacia";
    }
    if (longitud == 1) {
        inicio = nullptr;
        ultimo = nullptr;
    } else {
        ND_Generico<T> *aux = inicio->getSiguiente();
        aux->setAnterior(nullptr);
        inicio = aux;
    }
    longitud--;
}

template<class T>
ND_Generico<T> &LD_Generica<T>::buscarInicioAlUltimo(int indice) {
    ND_Generico<T> *actual = inicio;
    int cont = 0;
    while (cont < indice) {
        ND_Generico<T> *curr = actual->getSiguiente();
        actual = curr;
        cont++;
    }
    return *actual;
}

template<class T>
ND_Generico<T> &LD_Generica<T>::buscarIndice(int indice) {
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


#endif //PRACTICA1_EDD_LD_GENERICA_HPP
