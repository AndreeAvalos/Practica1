#ifndef DIAS_H
#define DIAS_H
#include "listaenlazadao.h"
#include "evento.h"

class Dias
{
public:
    Dias();
    int dia,mes,year;
    ListaenlazadaO<Evento> Eventos;
    Dias(int,int,int,ListaenlazadaO<Evento>);

    void setEventos(ListaenlazadaO<Evento> evt){
        this->Eventos=evt;
    }
};

#endif // DIAS_H
