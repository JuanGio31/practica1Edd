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
    pilas.addFinal(a1);
    pilas.addFinal(b1);
    pilas.addFinal(c1);
    pilas.addFinal(d1);
    pilas.addFinal(e1);
    pilas.addFinal(f1);
}

void Gestor::verPista(int indice) {
    pilas.obtenerContenido(indice).mostrar();
}

int Gestor::baseCompleta() {
    if (baseNo1.contador() == 13 && baseNo2.contador() == 13
        && baseNo3.contador() == 13 && baseNo4.contador() == 13) {
        return 1;
    }
    return 0;
}

/**
 * metodo que sirve para mover una carta del tablero hacia la base.
 * @param p1 representa la pila seleccionada.
 * @param base representa la base.
 */
void Gestor::trasladarCartaTabABase(Pila &p1, Pila &base) {
    if (!p1.vacia()) {
        int x = p1.getCima()->getDato().getValor();

        //Si la pila destino esta vacia, es posible insertar una carta
        // siempre y cuando sea una K (valor == 13)
        if (base.vacia()) {
            if (x == 1) {
                base.push(p1.pop());
                return;
            }
        }

        int y = base.getCima()->getDato().getValor();
        if (x == y + 1) {
            if (p1.getCima()->getDato().getTipo() == base.getCima()->getDato().getTipo()) {
                base.push(p1.pop());
            } else {
                cout << endl << "\tNo es posible realizar el movimiento."
                     << endl << "\tLos colores de las cartas(R y N) deben ser los mismos\n";
            }
        } else {
            cout << endl << "\tNo es posible realizar el movimiento." << endl;
        }
    } else {
        cout << endl << "\tPila vacia, no hay cartas a seleccionar." << endl;
    }
}

Pila &Gestor::obtenerBase(char a) {
    switch (a) {
        case 'D':
            return baseNo1;
        case 'E':
            return baseNo2;
        case 'F':
            return baseNo3;
        case 'G':
            return baseNo4;
    }
    throw "\tCaracter Invalido, intenta de nuevo";
}

/**
 * metodo que sirve para mover una carta de una Pila a Estructura.
 * @param p1 representa la pila seleccionada.
 * @param p2 representa la pila destino
 */
void Gestor::trasladar(Pila &p1, Pila &p2) {
    if (!p1.vacia()) {
        int x = p1.getCima()->getDato().getValor();

        //Si la pila destino esta vacia, es posible insertar una carta
        // siempre y cuando sea una K (valor == 13)
        if (p2.vacia()) {
            if (x == 13) {
                p2.push(p1.pop());
                return;
            }
        }

        int y = p2.getCima()->getDato().getValor();
        if (x == y - 1) {
            if (p1.getCima()->getDato().getColor() != p2.getCima()->getDato().getColor()) {
                p2.push(p1.pop());
            } else {
                cout << endl << "\tNo es posible realizar el movimiento."
                     << endl << "\tLos colores de las cartas(R y N) deben ir intercalados\n";
            }
        } else {
            cout << endl << "\tNo es posible realizar el movimiento." << endl;
        }
    } else {
        cout << endl << "\tPila vacia, no hay cartas a seleccionar." << endl;
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

Pila &Gestor::obtenerPilaEspecifica(char a) {
    switch (a) {
        case 'A':
            return this->getA1();
        case 'B':
            return this->getB1();
        case 'C':
            return this->getC1();
        case 'D':
            return this->getD1();
        case 'E':
            return this->getE1();
        case 'F':
            return this->getF1();
        case 'G':
            return this->getG1();
    }
    throw "\tCaracter invalido, intenta de nuevo";
}

Cola Gestor::getReserva() const { return reserva; }

Cola Gestor::getDescarte() { return descarte; }


Pila &Gestor::getA1() { return a1; }

Pila &Gestor::getB1() { return b1; }

Pila &Gestor::getC1() { return c1; }

Pila &Gestor::getD1() { return d1; }

Pila &Gestor::getE1() { return e1; }

Pila &Gestor::getF1() { return f1; }

Pila &Gestor::getG1() { return g1; }

Gestor::~Gestor() = default;
