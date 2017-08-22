#ifndef DIAS_H
#define DIAS_H
#include "listasimple.h"
#include "evento.h"

class Dias
{
public:
    Dias();
    int dia,mes,year;
    ListaSimple<Evento> Eventos;
    Dias(int,int,int,ListaSimple<Evento>);
    void setEventos(ListaSimple<Evento> evt){
        this->Eventos=evt;
    }
};

#endif // DIAS_H
