#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "nodo.h"

using namespace std;

template<class T>
class ListaDoble
{
public:
    ListaDoble();//constructor
    void add(T);//metodo para agregar objeto
    bool empty();//verifica si esta vacia
    void imprimir();//metodo para imprimir lista

    T getEvento(int dia, int mes, int year){
        Nodo<T> *temp = first;
        T valor =nullptr;

        while(temp!=nullptr){

            if(temp->data.dia==dia&&temp->data.mes==mes&&temp->data.year==year){
                valor = temp->data.Eventos;
             return valor;
            }
            temp =temp->Siguiente;
        }
        return valor;

    }

private:
    Nodo<T> *first, *last;
    int size;
};

#endif // LISTADOBLE_H
