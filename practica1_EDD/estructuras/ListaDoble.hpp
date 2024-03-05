//
// Created by giovanic on 3/03/24.
//

#ifndef PRACTICA1_EDD_LISTADOBLE_HPP
#define PRACTICA1_EDD_LISTADOBLE_HPP

#include "NodoDoble.hpp"

class ListaDoble {
private:
    NodoDoble *inicio;
    NodoDoble *ultimo;
    int longitud;

    NodoDoble &buscarIndice(int indice);

    NodoDoble &buscarInicioAlUltimo(int indice);

    NodoDoble &buscarUltimoAlPrimero(int indice);

public:
    NodoDoble *getInicio() const;

    ListaDoble();   //constructor vacio

    virtual ~ListaDoble();  //desconstructor

    void eliminarPrimero();

    void eliminarUltimo();

    void eliminar(int indice);

    void addFinal(const Carta &carta);

    bool vacia() const;

    Carta &frente();

    Carta &fin();

    Carta &obtenerContenido(int indice);

    void addInicio(const Carta &carta);

    void mostrar();

    int size() const;
};

#endif //PRACTICA1_EDD_LISTADOBLE_HPP
