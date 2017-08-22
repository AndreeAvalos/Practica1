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

    T getValor(int inde){//Metodo par obtener el valor del nodo m
        Nodo<T> *temp = root;//hacemos un temporal que sea igual a la raiz
        T valor;//cremaos un valor T
        for(int i=0; i<inde;i++){//recorremos el temporal hasta el indice
            temp=temp->Siguiente;
        }
        valor = temp->data;//Hacemos el valor con el valor deseado
        return valor;
    }

private:

};

#endif // LISTASIMPLE_H
