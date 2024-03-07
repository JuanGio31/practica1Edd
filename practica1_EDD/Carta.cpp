//
// Created by giovanic on 3/03/24.
//

#include "Carta.hpp"

Carta::~Carta() {}

Carta::Carta(int valor, char tipo) : valor(valor), tipo(tipo) {
    this->visibilidad = false;
    asignarSimbolo(valor);
    asignarColor(tipo);
}

void Carta::asignarSimbolo(int _v) {
    if (_v == 1) { this->simbolo = 'A'; }
    else if (_v == 11) { this->simbolo = 'J'; }
    else if (_v == 12) { this->simbolo = 'Q'; }
    else if (_v == 13) { this->simbolo = 'K'; }
    else { this->simbolo = _v + '0'; }
}

string Carta::representar() {
    if (isVisibilidad()) {
        string tmp;
        switch (this->tipo) {
            case 'C':   //Carta de Corazones
                tmp += "<3";
                break;
            case 'D':   //Carta de Diamantes
                tmp += "<>";
                break;
            case 'E':   //Carta de Espadas
                tmp += "¡!";
                break;
            case 'T':   //Carta de Treboles
                tmp += "EB";
                break;
        }
        tmp += color;
        return ((valor == 10) ? "10" + tmp : simbolo + tmp + " ");
    }
    return "#####";
}

bool Carta::isVisibilidad() const {
    return visibilidad;
}

void Carta::cambiarVisibilidad(int op) {
    if (op == 0) {
        this->visibilidad = !this->visibilidad;
    } else {
        this->visibilidad = true;
    }
}

void Carta::asignarColor(char tipoCarta) {
    if (tipoCarta == 'C' || tipoCarta == 'D') {
        this->color = 'R';
    } else {
        this->color = 'N';
    }
}

Carta::Carta() {}

int Carta::getValor() {
    return this->valor;
}

