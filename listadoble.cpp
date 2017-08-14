#include "listadoble.h"
#include "nodo.cpp"
#include"iostream"
#include <QtDebug>
//Constructor por defecto
template <typename T>
ListaDoble<T>::ListaDoble()
{
    this->first = nullptr;//inicio de lista
    this->last = nullptr;//final de lista
    this->size =0;//tamano de lista
}
//Metodo para verificar la lista
template <typename T>
bool ListaDoble<T>::empty(){
    if(first == nullptr){//Si es nulla de vuelvo true, de lo contrario false
        return true;
    }else
        return false;
}

//Metodo que a tiene como parametro el objeto
template <typename T>
void ListaDoble<T>::add(T dato){
     Nodo<T> *nuevo = new Nodo<T>(dato);//creamos un nuevo nodo
    if(empty()==true){//verifica si esta vacia
        first=nuevo;//el primero toma el valor del nuevo nodo
        last=nuevo;//el ultimo toma el valor del nuevo nodo
        first->Siguiente=last;//enlazamos el primero con el ultimo
        last->Anterior= first;//enlazamos el ultimo con el primero
    }else{//Si no esta vacia la lista se procede a insertar al inicio
        nuevo->Siguiente=first;//el nuevo apunta hacia el primero
        first->Anterior=nuevo;//el primero apunta hacia el nuevo
        last->Siguiente=nuevo;//el ultimo apunta hacia el nuevo
        nuevo->Anterior=last;//el nuevo apunta hacia el ultimo
        first = nuevo;//cambiamos de primero por el nuevo
    }
    size++;
}
template <typename T>
void ListaDoble<T>::imprimir(){
    Nodo<T> *temp = first;
    while (temp->Siguiente!=first) {
        qInfo()<< temp->data;
        temp = temp->Siguiente;
    }
    qInfo()<<temp->data;

}


