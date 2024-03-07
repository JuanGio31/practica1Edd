//
// Created by giovanic on 3/03/24.
//

#ifndef PRACTICA1_EDD_CARTA_HPP
#define PRACTICA1_EDD_CARTA_HPP

#include "iostream"

using namespace std;

class Carta {
private:
    int valor;
    char simbolo;
    bool visibilidad;
    char color;
    char tipo;
public:

    int getValor();

    void asignarColor(char tipoCarta);

    void asignarSimbolo(int _v);

    bool isVisibilidad() const;

    string representar();

    Carta();

    Carta(int valor, char tipo); //constructor con args

    virtual ~Carta();  //destructor

    void cambiarVisibilidad(int op);
};

#endif //PRACTICA1_EDD_CARTA_HPP
