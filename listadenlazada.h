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
    void ONickname();//Metodo para ordenar por nickname
    void ONombre();//Metodo para ordenar por Nombre
    void OApellido();//Metodo para ordenar por Apellido
//    void addFirst(T);//Metodo para agregar al principio de la lista
//    void addMiddle(T);//Metodo para agregar al medio de la lista
//    void addEnd(T);//Metodo para agregar al final de la lista

    T getValor(int inde){//Metodo par obtener el valor del nodo m
        Nodo<T> *temp = first;//hacemos un temporal que sea igual a la raiz
        T valor;//cremaos un valor T
        for(int i=0; i<inde;i++){//recorremos el temporal hasta el indice
            temp=temp->Siguiente;
        }
        valor = temp->data;//Hacemos el valor con el valor deseado
        return valor;
    }
    int size;
private:
    Nodo<T> *first;

};

#endif // LISTADENLAZADA_H
