//
// Created by giovanic on 4/03/24.
//

#include "Juego.hpp"


void Juego::llenarTab() {
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 7; ++j) {
            if ((i == 0 && j != 2) || i == 1) { //asignar val -> reserva, descarte y bases.
                if (i == 0 && j == 0) {
                    string tmp = "[" + gestor.getReserva().pintarPrimero() + "]";
//                    string tmp = "[ ZZZ ]";
                    tablero[i][j] = tmp;
                } else if (i == 0 && j == 1) {
                    if (!gestor.getDescarte().vacia()) {
                        string tmp = "[" + gestor.getDescarte().pintarPrimero() + "]";
                        tablero[i][j] = tmp;
                    } else {
                        tablero[i][j] = "[     ]";
                    }
                } else {
                    tablero[i][j] = "[     ]";
                }
            } else {    //asignar espacios en blanco
                tablero[i][j] = "       ";
            }
        }
    }

//    llenarColTab(gestor.getA1(), 0);
//    llenarColTab(gestor.getB1(), 1);
//    llenarColTab(gestor.getC1(), 2);
//    llenarColTab(gestor.getD1(), 3);
//    llenarColTab(gestor.getE1(), 4);
//    llenarColTab(gestor.getF1(), 5);
//    llenarColTab(gestor.getG1(), 6);

}

void Juego::llenarColTab(ListaDoble list, int columna) {
    if (list.vacia()) {
        tablero[1][columna] = "[     ]";
    } else {
        int cont = 1;
        NodoDoble *ac = list.getInicio();
        while (ac) {
            if (cont == 1) {
                list.frente().cambiarVisibilidad(1);
            }
            tablero[cont][columna] = "[" + ac->mostrar() + "]";
            ac = ac->getSiguiente();
            cont++;
        }
        delete ac;
    }
}

void Juego::pintarTablero() {
    cout << endl;
    llenarTab();
    cout << "\t\t  Corazones-> <3 ; Diamantes-> <> ; Treboles-> EB ; Espadas-> ¡!" << endl << endl;
    cout << "\t\t\t   ";
    for (int i = 0; i < 7; ++i) {
        char a = i + 65;
        cout << a << "       ";
    }
    cout << endl;
    for (int i = 0; i < 31; ++i) {
        cout << ((i == 0) ? "\t    + " : " ");
        cout << "-";
    }
    cout << " +" << endl;

    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (i == 0 && j == 2) {
                cout << "        ";
            } else if (j == 0) {
                if (i <= 8) {
                    cout << "\t" << i + 1 << "  |\t";
                } else {
                    cout << "\t" << i + 1 << " |\t";
                }
                cout << tablero[i][j] << "\t";
            } else {
                cout << tablero[i][j] << "\t";
                if (j == 6 && i == 0) {
                    cout << "\t|" << endl << "\t   |";
                }
            }
        }
        if (i == 0) {
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
        } else {
            cout << "\t|" << endl;
        }
    }

    for (int i = 0; i < 31; ++i) {
        cout << ((i == 0) ? "\t    + " : " ");
        cout << "-";
    }
    cout << " +" << endl;
}

void Juego::verMenu() {
    string menuOp = "\n\t 1. Mover Carta en Tablero.\n"
                    "\t 2. Ver Reserva.\n"
                    "\t 3. Mover Carta a Base.\n"
                    "\t 4. Mover descarte a Tablero.\n\n"
                    "\tSelecciona una opcion o ingresa 9 para Salir > ";
    int op = -1;
    while (op != 9) {
        pintarTablero();
        cout << menuOp;
        cin >> op;

        switch (op) {
            case 1:
                char seleccion, destino;
                cout << "\n\tSelecciona una columna [A-G] > ";
                cin >> seleccion;
                cout << "\n\tSelecciona la columa destino [A-G]" << " exceptuando " << seleccion << " > ";
                cin >> destino;
                //gestor.traslado(const_cast<ListaDoble &>(gestor.getB1()), const_cast<ListaDoble &>(gestor.getA1()));
                break;
            case 2:
                gestor.rotarColas();
                break;
            case 3:
                cout << "op 3";
                break;
            case 4:
                cout << "op 4";
                break;
            case 9:
                cout << "\nFin del Juego...";
                break;
            default:
                cout << "\tOpcion no valida!; intenta de nuevo." << endl;
                break;
        }
        cout << endl;
    }
}

Juego::Juego() {

}
