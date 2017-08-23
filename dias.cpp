#include "dias.h"


Dias::Dias()
{
    this->dia=0;
    this->mes=0;
    this->year=0;

}

Dias::Dias(int dia_ ,int mes, int year ,ListaenlazadaO<Evento> eventos){
    this->Eventos = eventos;
    this->dia=dia_;
    this->mes=mes;
    this->year=year;
}
