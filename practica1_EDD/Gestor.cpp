//
// Created by giovanic on 4/03/24.
//

#include "Gestor.hpp"
#include "unistd.h"

/**
 * metodo que sirve para crear y llenar una lista con 52 cartas divididas en cartas
 * de corazones, treboles, espadas y diamantes.
 */
void Gestor::agregar() {
    for (int i = 1; i < 14; ++i) { cartas->addFinal(Carta(i, 'C')); }
    for (int i = 1; i < 14; ++i) { cartas->addFinal(Carta(i, 'E')); }
    for (int i = 1; i < 14; ++i) { cartas->addFinal(Carta(i, 'D')); }
    for (int i = 1; i < 14; ++i) { cartas->addFinal(Carta(i, 'T')); }
}

/**
 * metodo que sirve para repartir aleatoriamente las 52 cartas a partir de una
 * lista partiendo primero de llenar una cola con 24 cartas, y luego las pilas
 * del tablero con las cartas restantes
 */
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
    // crear un pila temporal que servira para repartir las cartas restantes
    Pila tmp;
    int cont = 0;
    while (cont < 27) {
        tmp.push(cartas->obtenerContenido(1));
        cartas->eliminar(1);
        cont++;
    }
    tmp.push(cartas->frente());
    cartas->eliminarPrimero();

    a1.push(tmp.pop()); //llenar la primera columna (pila)
    for (int i = 0; i < 2; ++i) { b1.push(tmp.pop()); }
    for (int i = 0; i < 3; ++i) { c1.push(tmp.pop()); }
    for (int i = 0; i < 4; ++i) { d1.push(tmp.pop()); }
    for (int i = 0; i < 5; ++i) { e1.push(tmp.pop()); }
    for (int i = 0; i < 6; ++i) { f1.push(tmp.pop()); }
    for (int i = 0; i < 7; ++i) { g1.push(tmp.pop()); }
}

/**
 * metodo que sirve para mostrar las cartas creadas inicialmente,
 * sin barajear.
 */
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

/**
 * metodo constructor, llama a un metodo para repartir las cartas
 */
Gestor::Gestor() {
    cartas = new ListaDoble();
    repartir();
}


/**
 * metodo que sirve para mover una carta de una Pila a Estructura.
 * @param p1 representa la pila seleccionada.
 * @param p2 representa la pila destino
 */
void Gestor::trasladar(Pila &p1, Pila &p2) {
    int x = p1.getCima()->getDato().getValor();
    int y = p2.getCima()->getDato().getValor();
    if (x < y) {
        p2.push(p1.pop());
    } else {
        cout << endl << "\n No es posible realizar el movimiento." << endl;
    }

}

/**
 * metodo que sirve para mover obtener un elemento de una cola y moverlo
 * a otra; si una cola queda vacia, todos los elementos pasaran a la otra
 */
void Gestor::rotarColas() {
    if (!reserva.vacia()) {
        reserva.frente().cambiarVisibilidad(0);
        descarte.push(reserva.pop());
    } else {
        while (!descarte.vacia()) {
            descarte.frente().cambiarVisibilidad(0);
            reserva.push(descarte.pop());
        }
    }
}

Cola Gestor::getReserva() const { return reserva; }

Cola Gestor::getDescarte() { return descarte; }


 Pila &Gestor::getA1()  { return a1; }

const Pila &Gestor::getB1() const { return b1; }

const Pila &Gestor::getC1() const { return c1; }

const Pila &Gestor::getD1() const { return d1; }

const Pila &Gestor::getE1() const { return e1; }

const Pila &Gestor::getF1() const { return f1; }

const Pila &Gestor::getG1() const { return g1; }

Gestor::~Gestor() = default;
