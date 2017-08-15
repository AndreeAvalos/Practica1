#ifndef DIAS_H
#define DIAS_H
#include <iostream>
#include "listasimple.h"


template<class T>
class dias
{
private:
    int numd;
    string fecha;
    ListaSimple<T> Eventos;

public:
    dias();
    dias(int,string,ListaSimple<T>);
    int getDias(){
        return this->numd;
    }
    string getFecha(){
        return this->fecha;
    }
    ListaSimple<T> getEventos(){
        return  this->Eventos;
    }
    void setDia(int dia_){
        this->numd=dia_;
    }
    void setFecha(string fecha_){
        this->fecha=fecha_;
    }
    void setEventos(ListaSimple<T> evt){
        this->Eventos=evt;
    }
};

#endif // DIAS_H
