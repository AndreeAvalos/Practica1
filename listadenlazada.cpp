#include "listadenlazada.h"
template <typename T>
ListaDEnlazada<T>::ListaDEnlazada()
{
    this->first=nullptr;
}

template <typename T>
bool ListaDEnlazada<T>::empty(){
   if(first==nullptr){
        size=0;
       return true;//si la raiz es igual a nula, devuelve verdadero

   } else{
       return false;//si la raiz tiene objetos, devuelve falso
   }
}
template <typename T>
void ListaDEnlazada<T>::add(T val)
{
    Nodo<T> *nuevo = new Nodo<T>();
   if(this->empty()==true){
       first=nuevo;

   }else{
       int compare = val.compare(first->data);
   }
   size++;
}
