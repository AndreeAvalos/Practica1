#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "nodo.h"
#include "evento.h"
#include "dias.h"

using namespace std;

template<class T>
class ListaDoble
{
public:
    ListaDoble();//constructor
    void add(T);//metodo para agregar objeto
    bool empty();//verifica si esta vacia
    void imprimir();//metodo para imprimir lista

    ListaSimple<Evento> getEvento(int dia, int mes, int year){
        Nodo<T> *temp = first;
        ListaSimple<Evento> valor;

        while(temp!=nullptr){

            if(temp->data.dia==dia&&temp->data.mes==mes&&temp->data.year==year){
                Dias actual=temp->data;
                valor = actual.Eventos;
             return valor;
            }
            temp =temp->Siguiente;
        }
        return valor;

    }

    bool buscar(int dia, int mes, int year){
         Nodo<T> *temp = first;
         if(temp->data.dia==dia&&temp->data.mes==mes&&temp->data.year==year){
             return true;
         }
        while(temp->Siguiente!=first){
            if(temp->data.dia==dia&&temp->data.mes==mes&&temp->data.year==year){
             return true;
            }
            temp =temp->Siguiente;
        }
        return false;
    }

    Nodo<T> *first, *last;
    int size;
};

#endif // LISTADOBLE_H
