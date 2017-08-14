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
private:

};

#endif // LISTASIMPLE_H
