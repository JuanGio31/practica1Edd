//
// Created by giovanic on 4/03/24.
//

#include "Gestor.hpp"
#include "unistd.h"

void Gestor::agregar() {
    for (int i = 1; i < 14; ++i) { cartas->addFinal(Carta(i, 'C')); }
    for (int i = 1; i < 14; ++i) { cartas->addFinal(Carta(i, 'E')); }
    for (int i = 1; i < 14; ++i) { cartas->addFinal(Carta(i, 'D')); }
    for (int i = 1; i < 14; ++i) { cartas->addFinal(Carta(i, 'T')); }
}

void Gestor::repartir() {
    agregar();
    srand(getpid());
    int contador = 0;
    while (contador < 24) {
        int _random = rand() % (cartas->size() / 2) + 1;
        reserva.push(cartas->obtenerContenido(_random));
        cartas->eliminar(_random);
        contador++;
    }


    Pila tmp;
    int cont = 0;
    while (cont < 27) {
        tmp.push(cartas->obtenerContenido(1));
        cartas->eliminar(1);
        cont++;
    }
    tmp.push(cartas->frente());
    cartas->eliminarPrimero();

    tmp.mostrar();
    cout << tmp.contador() << endl;
//    for (int i = 0; i < 2; ++i) {
//        b1.addFinal(tmp->pop());
//    }
//
//    for (int i = 0; i < 3; ++i) {
//        c1.addFinal(tmp->pop());
//    }
//    for (int i = 0; i < 4; ++i) {
//        d1.addFinal(tmp->pop());
//    }
//    for (int i = 0; i < 5; ++i) {
//        e1.addFinal(tmp->pop());
//    }
//    for (int i = 0; i < 6; ++i) {
//        f1.addFinal(tmp->pop());
//    }
//    for (int i = 0; i < 7; ++i) {
//        g1.addFinal(tmp->pop());
//    }

    cout << "Cartas -> " << cartas->size() << endl;
}

void Gestor::verCartas() {
    int contador = 0;
    for (int i = 0; i < cartas->size(); ++i) {
        cout << cartas->obtenerContenido(i).representar();
        if (contador == 12) {
            cout << endl;
            contador = 0;
        } else {
            cout << " -> ";
            contador++;
        }
    }
}

//constructor
Gestor::Gestor() {
    cartas = new ListaDoble();
    repartir();

    reserva.mostrar();
//    a1.mostrar();
//    b1.mostrar();
//    c1.mostrar();
//    d1.mostrar();
//    e1.mostrar();
//    f1.mostrar();
//    g1.mostrar();


    delete cartas;
}

//seleccion, destino
void Gestor::traslado(ListaDoble &l1, ListaDoble &l2) {
    l1.addInicio(l2.frente());
    l2.eliminarPrimero();
}

void Gestor::rotarColas() {
    if (descarte.vacia()) {
        reserva.frente().cambiarVisibilidad(0);
        descarte.push(reserva.pop());
    } else {
        descarte.frente().cambiarVisibilidad(0);
        reserva.push(descarte.pop());
        reserva.frente().cambiarVisibilidad(0);
        descarte.push(reserva.pop());
    }
}

const Cola &Gestor::getReserva() const {
    return reserva;
}

Cola Gestor::getDescarte() {
    return descarte;
}



const Pila &Gestor::getA1() const {
    return a1;
}

const Pila &Gestor::getB1() const {
    return b1;
}

const Pila &Gestor::getC1() const {
    return c1;
}

const Pila &Gestor::getD1() const {
    return d1;
}

const Pila &Gestor::getE1() const {
    return e1;
}

const Pila &Gestor::getF1() const {
    return f1;
}

const Pila &Gestor::getG1() const {
    return g1;
}

Gestor::~Gestor() = default;
