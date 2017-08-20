#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "nodo.h"

using namespace std;

template<class T>

class ListaSimple
{
public:
    ListaSimple();
    ListaSimple(T);
    void add(T);
    void imprimir();
    bool empty();

    Nodo<T> *root;
    int size;

    T getValor(int inde){
        Nodo<T> *temp = root;
        T valor;
        for(int i=0; i<inde;i++){
            temp=temp->Siguiente;
        }
        valor = temp->data;
    }

private:

};

#endif // LISTASIMPLE_H
