//
// Created by giovanic on 4/03/24.
//

#ifndef PRACTICA1_EDD_JUEGO_HPP
#define PRACTICA1_EDD_JUEGO_HPP

#include "Gestor.hpp"

class Juego {
private:
    Gestor gestor;
    string tablero[13][7];

    void llenarTab();


    void pintarTablero();


public:
    void verMenu();

    Juego();

    void llenarColTab(Pila list, int columna);

    void moverEntreTablero(char a, char b);

    void juegoGanado();

    void verPista(char a);

    void moverABase(char a, char b);

    void llenarBase(Pila pila, int columna);
};

#endif //PRACTICA1_EDD_JUEGO_HPP
