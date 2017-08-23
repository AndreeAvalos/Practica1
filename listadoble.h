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

    ListaenlazadaO<Evento> getEvento(int dia, int mes, int year){
        Nodo<T> *temp = first;

        ListaenlazadaO<Evento> valor;
        if(temp->data.dia==dia&&temp->data.mes==mes&&temp->data.year==year&& temp==first){
            return temp->data.Eventos;
        }
        temp = temp->Siguiente;
        while(temp!=first){

            if(temp->data.dia==dia&&temp->data.mes==mes&&temp->data.year==year){
                Dias actual=temp->data;
                valor = actual.Eventos;
            }
            temp =temp->Siguiente;
        }
        return valor;

    }

    bool buscar(int dia, int mes, int year){
         Nodo<T> *temp = first;

         if(temp->data.dia==dia&&temp->data.mes==mes&&temp->data.year==year&&temp==first){
             return true;
         }
          temp = temp->Siguiente;
        while(temp!=first){
            if(temp->data.dia==dia&&temp->data.mes==mes&&temp->data.year==year){
             return true;
            }
            temp =temp->Siguiente;
        }
        return false;
    }
    void setDia(int dia, int mes, int year, ListaenlazadaO<Evento> evt){
        Nodo<T> *temp = first;

        ListaenlazadaO<Evento> valor;
        if(temp->data.dia==dia&&temp->data.mes==mes&&temp->data.year==year&& temp==first){
            temp->data.Eventos=evt;
        }
        while(temp->Siguiente!=first){

            if(temp->data.dia==dia&&temp->data.mes==mes&&temp->data.year==year){
               temp->data.Eventos=evt;
            }
            temp =temp->Siguiente;
        }
        return;

    }

    Nodo<T> *first, *last;
    int size;
};

#endif // LISTADOBLE_H
