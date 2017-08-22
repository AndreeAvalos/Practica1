#include "dias.h"
#include "listasimple.cpp"

Dias::Dias()
{
    this->dia=0;
    this->mes=0;
    this->year=0;

}

Dias::Dias(int dia_ ,int mes, int year ,ListaSimple<Evento> eventos){
    this->Eventos = eventos;
    this->dia=dia_;
    this->mes=mes;
    this->year=year;
}
