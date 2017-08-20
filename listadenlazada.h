#ifndef LISTADENLAZADA_H
#define LISTADENLAZADA_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "nodo.h"

template<class T>
class ListaDEnlazada
{
public:

    ListaDEnlazada();
    void add(T);//metodo para agregar objeto
    bool empty();//verifica si esta vacia
    void imprimir();//metodo para imprimir lista
//    void addFirst(T);//Metodo para agregar al principio de la lista
//    void addMiddle(T);//Metodo para agregar al medio de la lista
//    void addEnd(T);//Metodo para agregar al final de la lista

private:
    Nodo<T> *first;
    int size;
};

#endif // LISTADENLAZADA_H
