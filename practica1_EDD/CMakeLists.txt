cmake_minimum_required(VERSION 3.27)

project(practica1_EDD DESCRIPTION "Practica No.1 de estructura de datos, Solitario en c++")

set(CMAKE_CXX_STANDARD 17)

add_executable(practica1_EDD main.cpp
        Carta.hpp
        Carta.cpp
        estructuras/Pila.cpp
        estructuras/Pila.hpp
        estructuras/Nodo.cpp
        estructuras/Nodo.hpp
        estructuras/Cola.cpp
        estructuras/Cola.hpp
        estructuras/NodoDoble.cpp
        estructuras/NodoDoble.hpp
        estructuras/ListaDoble.cpp
        estructuras/ListaDoble.hpp
        Juego.cpp
        Juego.hpp
        Gestor.cpp
        Gestor.hpp
        estructuras/LD_Generica.hpp
)