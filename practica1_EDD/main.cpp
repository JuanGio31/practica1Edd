#include<iostream>
#include "Carta.hpp"
#include "estructuras/Pila.hpp"
#include "estructuras/Cola.hpp"
#include "estructuras/LD_Generica.hpp"
#include "Juego.hpp"

void verEjemplosPilas_Colas() {
    Pila tmp;
    Cola tmp1;
    tmp.push(Carta(2, 'T'));
    tmp.push(Carta(3, 'E'));
    tmp.push(Carta(4, 'C'));
    tmp.push(Carta(5, 'D'));
    tmp.push(Carta(6, 'T'));
    tmp.push(Carta(7, 'C'));
//
//    tmp1.push(Carta(2, 'T'));
//    tmp1.push(Carta(3, 'E'));
//    tmp1.push(Carta(4, 'C'));
//    tmp1.push(Carta(5, 'D'));
//    tmp1.push(Carta(6, 'T'));
//    tmp1.push(Carta(7, 'C'));
//
//    tmp.mostrar();
//    tmp1.mostrar();
//
//    cout << endl << endl;
//    cout << tmp1.ultimo().isVisibilidad() << endl;
//    tmp1.ultimo().cambiarVisibilidad();
//    cout << tmp1.ultimo().isVisibilidad() << endl;
//    tmp1.ultimo().cambiarVisibilidad();
//    cout << tmp1.ultimo().isVisibilidad() << endl;

//    try {
//        cout << tmp.pop().representar() << endl;
//        cout << tmp.pop().representar() << endl;
//        cout << tmp.pop().representar() << endl;
//        cout << tmp.pop().representar() << endl;
//        cout << tmp.pop().representar() << endl;
//        cout << tmp.pop().representar() << endl;
//        cout << tmp.pop().representar() << endl;
//        cout << tmp.pop().representar() << endl;
//        cout << tmp.pop().representar() << endl;
//    } catch (const char *e) {
//        cout << e << endl;
//    }
}

//void verListaDoble() {
//    ListaDoble tmp;
//    tmp.addFinal(Carta(2, 'T'));    //0
//    tmp.addFinal(Carta(3, 'E'));    //1
//    tmp.addFinal(Carta(4, 'C'));    //2
//    tmp.addFinal(Carta(5, 'D'));    //3
//    tmp.addFinal(Carta(6, 'T'));    //4
//    tmp.addFinal(Carta(7, 'C'));    //5
//
//
//    tmp.mostrar();
//
//    cout << tmp.obtenerContenido(4).representar() << endl;
//    tmp.eliminar(4);
//    tmp.mostrar();
//    tmp.eliminar(1);
//    tmp.mostrar();
//    tmp.eliminar(1);
//    tmp.mostrar();
//}

void ListaGen() {
    auto *tmp = new LD_Generica<Carta>();
    tmp->addFinal(Carta(2, 'T'));    //0
    tmp->addFinal(Carta(3, 'E'));    //1
    tmp->addFinal(Carta(4, 'C'));    //2
    tmp->addFinal(Carta(5, 'D'));    //3
    tmp->addFinal(Carta(6, 'T'));    //4
    tmp->addFinal(Carta(7, 'C'));    //5


    cout << tmp->obtenerContenido(4).representar() << endl;
}

int main() {
//    Gestor gt;

    Juego jg;
    jg.verMenu();

//    verEjemplosPilas_Colas();
    //verListaDoble();
    return 0;
}
