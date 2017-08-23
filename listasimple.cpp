#include "listasimple.h"
#include "iostream"
#include <QtDebug>
#include "lugares.h"
#include "nodo.h"

using namespace std;

//Constructor por defecto
template <typename T>
ListaSimple<T>::ListaSimple()
{
    root=nullptr;
    size=0;
}
//funcion para verificar si existe nodo en la lista o esta vacia
template <typename T>
bool ListaSimple<T>::empty(){
   if(root==nullptr){
        size=0;
       return true;//si la raiz es igual a nula, devuelve verdadero

   } else{
       return false;//si la raiz tiene objetos, devuelve falso
   }
}
//Metodo para agregar a la lista que recibe como parametro un objeto
template <typename T>
void ListaSimple<T>::add(T dato){
    Nodo<T> *nuevo = new Nodo<T>(dato);//creamos un nuevo nodo
    if (this->empty()==true){//verificamos si esta vacia la lista
        this->root = nuevo;//si esta vacia la raiz obtiene el valor del nodo nuevo
    }else{
        nuevo->Siguiente=this->root;//de lo contrario el nodo apunta hacia la raiz
        this->root= nuevo;//el nuevo pasa a ser la raiz

    }
    size++; //aumentamos el tamano de la lista

}
//metodo para imprimir
template<typename T>
void ListaSimple<T>::imprimir(){
    ofstream ficheroSalida;
    ficheroSalida.open ("/home/andree/Escritorio/listasimple.txt");
ficheroSalida << "digraph{";

    Nodo<T> *temp = root;//creamos un temporal para poder recorrecorlo
    ficheroSalida <<'\"'<< temp->data.nombre.toStdString()<<'\"';
    while(temp!= nullptr){//miramos si el valor es el ultimo nodo
        //qInfo() << temp->data.titulo;//imprimimos el valor en consola
        if(temp!=root){
        ficheroSalida << "->";
        ficheroSalida << '\"'<<temp->data.nombre.toStdString()<<'\"';}
        temp = temp->Siguiente;//cambiamos de nodo
    }
    ficheroSalida << "}";
     ficheroSalida.close();
     system("dot -Tpng /home/andree/Escritorio/listasimple.txt -o /home/andree/Escritorio/listasimple.png");

}
