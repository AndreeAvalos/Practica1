#include "nodo.h"

//Constructor por defecto para el nodo
template<typename T>
Nodo<T>::Nodo()
{
   this->Siguiente= nullptr;
   this->Anterior= nullptr;
}
//Constructor con parametros
template<typename T>
Nodo<T>::Nodo(T dato)
{
    this->data= dato;
    this->Siguiente= nullptr;
    this->Anterior= nullptr;
}
