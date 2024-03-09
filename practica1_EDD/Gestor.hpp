//
// Created by giovanic on 4/03/24.
//

#ifndef PRACTICA1_EDD_GESTOR_HPP
#define PRACTICA1_EDD_GESTOR_HPP

#include "estructuras/ListaDoble.hpp"
#include "estructuras/Cola.hpp"
#include "estructuras/Pila.hpp"
#include "estructuras/LD_Generica.hpp"

class Gestor {
private:
    LD_Generica<Pila> pilas;
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
    Cola getReserva() const;

    Cola getDescarte();

    void verCartas();

    Gestor();

    virtual ~Gestor();

    void rotarColas();

    Pila &getA1();

    Pila &getB1();

    Pila &getC1();

    Pila &getD1();

    Pila &getE1();

    Pila &getF1();

    Pila &getG1();

    void trasladar(Pila &p1, Pila &p2);

    Pila &obtenerPilaEspecifica(char a);

    void trasladarCartaTabABase(Pila &p1, Pila &base);

    int baseCompleta();

    Pila &obtenerBase(char a);

    void verPista(int op);
};

#endif //PRACTICA1_EDD_GESTOR_HPP
