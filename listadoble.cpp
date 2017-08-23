#include "listadoble.h"
#include "iostream"
#include <QtDebug>
#include "nodo.h"
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
    if(first == nullptr){//Si es nula de vuelvo true, de lo contrario false
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
        first->Siguiente = first;//enlazamos el primero con el ultimo
        first->Anterior = first;//enlazamos el ultimo con el primero
        last=first;
    }else{//Si no esta vacia la lista se procede a insertar al inicio
        last->Siguiente=nuevo;
        nuevo->Siguiente=first;
        nuevo->Anterior=last;
        last=nuevo;
        first->Anterior=last;

    }
    size++;
}
template <typename T>
void ListaDoble<T>::imprimir(){
    ofstream ficheroSalida;
    ficheroSalida.open ("/home/andree/Escritorio/ListaDoble.txt");
    ficheroSalida << "digraph{";
    QString fecha;
    Nodo<T> *temp = first;//creamos un nodo temporal
    if(temp==first){
     fecha = '\"' +QString::number(temp->data.dia) + "-"+ QString::number(temp->data.mes)+"-"+QString::number(temp->data.year)+'\"' ;
     ficheroSalida << fecha.toStdString() ;
    }
    temp=temp->Siguiente;
    while (temp!=first) {//Recorremos mientras el temporal sea diferente del primero
        fecha = '\"' +QString::number(temp->data.dia) + "-"+ QString::number(temp->data.mes)+"-"+QString::number(temp->data.year)+'\"' ;
        ficheroSalida << "->" ;
         ficheroSalida << fecha.toStdString() ;
        // qInfo()<< fecha ;//imprimimos
        temp = temp->Siguiente;//el temporal es el siguiente
    }
    ficheroSalida << ";";
    temp = last;
    if(temp==last){
        fecha = '\"' +QString::number(temp->data.dia) + "-"+ QString::number(temp->data.mes)+"-"+QString::number(temp->data.year)+'\"' ;
        ficheroSalida << fecha.toStdString() ;

    }
    temp=temp->Anterior;
    while (temp!=last) {//Recorremos mientras el temporal sea diferente del primero
        fecha = '\"' +QString::number(temp->data.dia) + "-"+ QString::number(temp->data.mes)+"-"+QString::number(temp->data.year)+'\"' ;
        ficheroSalida << "->" ;
         ficheroSalida << fecha.toStdString() ;
        // qInfo()<< fecha ;//imprimimos
        temp = temp->Anterior;//el temporal es el siguiente
    }

    ficheroSalida << ";";
    temp = first;
    if(temp==first){
     fecha = '\"' +QString::number(temp->data.dia) + "-"+ QString::number(temp->data.mes)+"-"+QString::number(temp->data.year)+'\"' ;
     ficheroSalida << fecha.toStdString() ;
     ficheroSalida << "->" ;
     Nodo<Evento> *temp2=temp->data.Eventos.first;
     ficheroSalida << '\"' << temp2->data.titulo.toStdString() <<'\"';
     while(temp2!=nullptr){
         if(temp2!=temp->data.Eventos.first){
         ficheroSalida << "->" ;
         ficheroSalida << '\"' << temp2->data.titulo.toStdString() <<'\"';}


         temp2=temp2->Siguiente;}


    }

    temp=temp->Siguiente;

    while (temp!=first) {//Recorremos mientras el temporal sea diferente del primero
        fecha = '\"' +QString::number(temp->data.dia) + "-"+ QString::number(temp->data.mes)+"-"+QString::number(temp->data.year)+'\"' ;
        ficheroSalida << fecha.toStdString() ;
        ficheroSalida << "->" ;

         Nodo<Evento> *temp2=temp->data.Eventos.first;
         ficheroSalida << '\"' << temp2->data.titulo.toStdString() <<'\"';
         while(temp2!=nullptr){
             if(temp2!=temp->data.Eventos.first){
             ficheroSalida << "->" ;
             ficheroSalida << '\"' << temp2->data.titulo.toStdString() <<'\"';}


             temp2=temp2->Siguiente;}
         ficheroSalida << ";";
        // qInfo()<< fecha ;//imprimimos
        temp = temp->Siguiente;//el temporal es el siguiente
    }
    //qInfo()<<fecha;//imprimimos el ultimo elemento
    ficheroSalida <<"}";
     ficheroSalida.close();
     system("fdp -Tpng /home/andree/Escritorio/ListaDoble.txt -o /home/andree/Escritorio/ListaDoble.png");

}



