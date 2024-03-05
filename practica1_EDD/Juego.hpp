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

    void llenarColTab(ListaDoble list, int columna);
};

#endif //PRACTICA1_EDD_JUEGO_HPP
