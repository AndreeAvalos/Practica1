#include "listadenlazada.h"
#include "contacto.h"
#include <QString>
#include <QDebug>
#include <Qt>
#include <QJsonDocument>
#include "nodo.cpp"
template <typename T>
ListaDEnlazada<T>::ListaDEnlazada()
{
    this->first=nullptr;
    this->size=0;
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
/*
template <typename T>
void ListaDEnlazada<T>::add(T val)//Metodo para agregar registro
{
    Nodo<T> *nuevo = new Nodo<T>();//Creamos un nodo
   if(this->empty()==true){//Verificamos si el la lista esta vacia
       first=nuevo;//hacemos el nuevo como primero
       return;
   }
   if(first->Siguiente=nullptr){//Si solo hay un elemento
       int compare = val.compare(first->data);//Compara los valores
       if(compare>0){//Si el valor es mayor a 0 entonces directo al final
           first->Siguiente=nuevo;//el primero apunta hacia el nuevo
           nuevo->Anterior=first;//el nuevo apunta hacia el primero
           return  ;//salimos del metodo
       }
       if(compare<0){//Si el valor es menor a 0
           nuevo->Siguiente=first;//el nuevo apunta hacia el primero
           first->Anterior=nuevo;//el primero apunta hacia el nuevo
           first=nuevo;//el primero se vuelve el primero
           return;//salimos del metodo
       }
   }

   Nodo<T> *temp = first;
   Nodo<T> *ant = nullptr;

   while(temp->Siguiente!=nullptr){
       int compare = val.compare(temp->data);
       if(compare>0){
           ant= temp;
           temp = temp->Siguiente;
           continue;
       }
       if(compare<0){
           if(ant==nullptr){
              nuevo->Siguiente=first;
              first->Anterior=nuevo;
              first=nuevo;
           }else {
               ant->Siguiente=nuevo;
               nuevo->Anterior=ant;
               nuevo->Siguiente=temp;
               temp->Anterior=nuevo;
           }
           return;
       }
       return;
   }
   temp->Siguiente=nuevo;
   nuevo->Anterior=temp;
   size++;//aumentamos el tamano
}*/
template <typename T>
void ListaDEnlazada<T>::add(T val)//Metodo para agregar registro
{
    Nodo<T> *nuevo = new Nodo<T>(val);
            if(first==nullptr){
                qInfo() << "Primer elemento de la lista";
                first = nuevo;
                size++;
                return;
            }

            //Actualmente solo hay un elemento en la lista
            if(first->Siguiente == nullptr) {
                //Se compara el valor nuevo a insertar contra el unico valor que existe en la lista
                int comparison = val.compare(first->data);

                //Si el valor nuevo es mayor que el unico valor de la lista,
                //insertar despues del primero, en otras palabras INSERTAR AL FINAL
                if(comparison > 0) {
                    qInfo() << "Insertar directamente al final";
                    first->Siguiente = nuevo;
                    nuevo->Anterior=first;
                    size++;
                    return;
                }

                //Si el valor nuevo es menor que el unico valor de la lista,
                //insertar antes del primero, en otras palabras INSERTAR AL INICIO
                if(comparison < 0) {
                    qInfo() << "Insertar directamente al inicio";
                    nuevo->Siguiente = first;
                    first->Anterior=nuevo;
                    first = nuevo;
                    size++;
                    return;
                }

                //Si no es mayor, ni tampoco es menor, entonces los elementos son iguales...
                qInfo() << "Elemento repetido";
                return;
            }

            //Nodo auxiliar para recorrer la lista, se busca el punto de insercion correcto
            //Como la lista esta ordenada la nueva insercion tiene que ser justo antes del
            //primer elemento que sea "menor" que el valor nuevo.
            Nodo<T> *aux = first;
            Nodo<T> *ant = nullptr;
            while(aux->Siguiente != nullptr){
                int comparison = val.compare(aux->data);

                //Es necesario evaluar el siguiente elemento
                if(comparison > 0) {
                    ant = aux;
                    aux = aux->Siguiente;
                    continue;
                }

                //El nuevo elemento va entre el elemento apuntado por ANT y AUX
                if(comparison < 0) {
                    if(ant==nullptr) {
                        qInfo() << "Insertando al inicio, antes de: " << aux->data.toString();
                        nuevo->Siguiente = first;
                        first->Anterior=nuevo;
                        first = nuevo;
                    } else {
                        qInfo() <<nuevo->data.toString() << "Insertando entre: " << ant->data.toString() << " y " << aux->data.toString();
                        ant->Siguiente = nuevo;
                        nuevo->Anterior=ant;
                        nuevo->Siguiente = aux;
                        aux->Anterior=nuevo;
                    }
                    size++;
                    return;
                }

                qInfo() << "Elemento repetido";
                return;
            }

            qInfo() << "Insertado al final"<<nuevo->data.toString();
            aux->Siguiente = nuevo;
            nuevo->Anterior=aux;
            size++;

}
template <typename T>
void ListaDEnlazada<T>::ONombre(){
    Nodo<T> *temp = first;
    Nodo<T> *temp2 = nullptr;
    Nodo<T> *temp3 = first;
    Nodo<T> *aux = nullptr;
    Nodo<T> *aux2 = nullptr;
    Contacto conta,conta2;
    while(temp->Siguiente!=nullptr){
        aux = temp3->Anterior;
        temp2= temp->Siguiente;
        aux2=temp2->Siguiente;
        conta = temp3->data;
        conta2= temp2->data;
        int comparacion = conta.apellido.compare(conta2.apellido);
        if(comparacion>0){
            temp=temp->Siguiente;
            continue;
        }
        if(comparacion<0){
            Nodo<T> *temp4=temp2;
            temp2=temp3;
            temp3=temp4;
            aux->Siguiente=temp3;
            temp3->Anterior=aux;
            temp3->Siguiente=temp2;
            temp2->ante= temp4;
            temp2->Siguiente=aux2;
            aux->Anterior=temp2;

        }
    }

}
template <typename T>
void ListaDEnlazada<T>::imprimir(){
    Nodo<T> *temp = first;
    while(temp!=nullptr){
        qInfo()<< temp->data.toString();
        temp = temp->Siguiente;
    }
}
