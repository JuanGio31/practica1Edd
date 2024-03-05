//
// Created by giovanic on 4/03/24.
//

#ifndef PRACTICA1_EDD_GESTOR_HPP
#define PRACTICA1_EDD_GESTOR_HPP

#include "estructuras/ListaDoble.hpp"
#include "estructuras/Cola.hpp"
#include "estructuras/Pila.hpp"

class Gestor {
private:
    ListaDoble *cartas;
    Cola reserva;
    Cola descarte;
    Pila baseNo1;
    Pila baseNo2;
    Pila baseNo3;
    Pila baseNo4;
    Pila a1;  //Columna 1
    Pila b1;  //columna 2
    Pila c1;  //columna 3
    Pila d1;  //columna 4
    Pila e1;  //columna 5
    Pila f1;  //columna 6
    Pila g1;  //columna 7

    void agregar();

    void repartir();

public:
    const Cola &getReserva() const;

    Cola getDescarte();

    void verCartas();

    Gestor();

    virtual ~Gestor();

    void rotarColas();

    const Pila &getA1() const;

    const Pila &getB1() const;

    const Pila &getC1() const;

    const Pila &getD1() const;

    const Pila &getE1() const;

    const Pila &getF1() const;

    const Pila &getG1() const;

    void traslado(ListaDoble &l1, ListaDoble &l2);
};

#endif //PRACTICA1_EDD_GESTOR_HPP