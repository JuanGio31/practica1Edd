//
// Created by giovanic on 4/03/24.
//

#include <limits>
#include "Juego.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Juego::llenarTab() {
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 7; ++j) {
            if ((i == 0 && j != 2) || i == 1) { //asignar val -> reserva, descarte y bases.
                if (i == 0 && j == 0) {
                    if (!gestor.getReserva().vacia()) {
                        string tmp = "[" + gestor.getReserva().frente().representar() + "]";
                        tablero[i][j] = tmp;
                    } else {
                        tablero[i][j] = "[     ]";
                    }
                } else if (i == 0 && j == 1) {
                    if (!gestor.getDescarte().vacia()) {
                        string tmp = "[" + gestor.getDescarte().ultimo().representar() + "]";
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


    llenarColTab(gestor.getA1(), 0);
    llenarColTab(gestor.getB1(), 1);
    llenarColTab(gestor.getC1(), 2);
    llenarColTab(gestor.getD1(), 3);
    llenarColTab(gestor.getE1(), 4);
    llenarColTab(gestor.getF1(), 5);
    llenarColTab(gestor.getG1(), 6);

//    llenarColTab(gestor.obtenerBase('D'), 3);
//    llenarColTab(gestor.obtenerBase('E'), 4);
//    llenarColTab(gestor.obtenerBase('F'), 5);
//    llenarColTab(gestor.obtenerBase('G'), 6);

}

void Juego::llenarBase(Pila pila, int columna) {
    if (pila.vacia()) {
        tablero[0][columna] = "[     ]";
    } else {
        tablero[0][columna] = "[" + pila.getCima()->mostrar() + "]";
    }
}

void Juego::llenarColTab(Pila pila, int columna) {
    if (pila.vacia()) {
        tablero[1][columna] = "[     ]";
    } else {
        int cont = pila.contador();
        pila.getCima()->getDato().cambiarVisibilidad(1);
        Pila tmp = pila;
        while (!tmp.vacia()) {
            tablero[cont][columna] = "[" + tmp.pop().representar() + "]";
            cont--;
        }
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
                    "\t 4. Mover descarte a Tablero.\n"
                    "\t 5. Mover descarte a Base\n"
                    "\t 6. Pista\n\n"
                    "\tSelecciona una opcion o ingresa 9 para Salir > ";
    int op = -1;
    while (op != 9) {
        pintarTablero();
        cout << menuOp;
        cin >> op;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            op = -1;
        }
        switch (op) {
            case 1:
                char seleccion, destino;
                cout << "\n\tSelecciona una columna [A-G] > ";
                cin >> seleccion;
                cout << "\n\tSelecciona la columa destino [A-G]" << " exceptuando " << seleccion << " > ";
                cin >> destino;
                moverEntreTablero(seleccion, destino);
                break;
            case 2:
                gestor.rotarColas();
                break;
            case 3:
                char columna, base;
                cout << "\n\tSelecciona una columna [A-G] > ";
                cin >> columna;
                cout << "\n\tSelecciona la Base destino [D-G]" << " > ";
                cin >> base;
                // moverABase(columna, base);
                break;
            case 4:
                cout << "op 4";
                break;
                break;
            case 5:

            case 6:
                char tmp;
                cout << "\n\tSelecciona una columna [A-G] > ";
                cin >> tmp;
                verPista(tmp);
                break;
            case 9:
                cout << "\nFin del Juego...";
                break;
            default:
                cout << "\tOpcion no valida!; intenta de nuevo." << endl;
                break;
        }
        cout << endl;
        cin.clear();
        limpiarPantalla();
    }
}

void Juego::moverEntreTablero(char a, char b) {
    if (a != b) {
        try {
            gestor.trasladar(
                    gestor.obtenerPilaEspecifica(a),
                    gestor.obtenerPilaEspecifica(b));
        } catch (const char *e) {
            cout << e << endl;
        }
    } else {
        cout << endl << "\tNo es posible realizar el movimiento, "
             << " por que " << a << " y " << b << " son iguales."
             << endl;
    }
}

void Juego::moverABase(char a, char b) {
    try {
        gestor.trasladarCartaTabABase(
                gestor.obtenerPilaEspecifica(a),
                gestor.obtenerBase(b));
    } catch (const char *e) {
        cout << e << endl;
    }
}

void Juego::juegoGanado() {
    if (gestor.baseCompleta() == 1) {
        cout << endl << "\n\tJUEGO COMPLETADO!!!" << endl;
        exit(EXIT_SUCCESS);
    }
}

void Juego::verPista(char a) {
    switch (a) {
        case 'A':
            cout << endl << "\tFuera de Limite";
            break;
        case 'B':
            gestor.verPista(0);
            break;
        case 'C':
            gestor.verPista(1);
            break;
        case 'D':
            gestor.verPista(2);
            break;
        case 'E':
            gestor.verPista(3);
            break;
        case 'F':
            gestor.verPista(4);
            break;
        case 'G':
            gestor.verPista(5);
            break;
        default:
            cout << endl << "\tOpcion no valida";
            break;
    }
}

Juego::Juego() {}