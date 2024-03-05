//
// Created by giovanic on 3/03/24.
//

#ifndef PRACTICA1_EDD_NODODOBLE_HPP
#define PRACTICA1_EDD_NODODOBLE_HPP

#include "../Carta.hpp"

class NodoDoble {
private:
    Carta dato;
    NodoDoble *siguiente;
    NodoDoble *anterior;
public:
    explicit NodoDoble(const Carta &dato);  //constructor con args

    NodoDoble();    //constructor vacio
    virtual ~NodoDoble();   //destructor

    const Carta &getDato() const;

    void setDato(const Carta &dato);

    NodoDoble *getSiguiente() const;

    void setSiguiente(NodoDoble *siguiente);

    NodoDoble *getAnterior() const;

    void setAnterior(NodoDoble *anterior);
    string mostrar();
};

#endif //PRACTICA1_EDD_NODODOBLE_HPP
