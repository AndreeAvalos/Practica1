#include "evento.h"
#include"listasimple.cpp";
Evento::Evento()
{
    this->titulo="";
        this->descripcion="";
        this->duracion="";
        this->fecha="";
        this->hInicio="";
}
Evento::Evento(QString titulo, QString descripcion, QString duracion, QString fecha, QString inicio,QString lugar,  QString contactos){
    this->titulo=titulo;
    this->descripcion=descripcion;
    this->duracion=duracion;
    this->fecha=fecha;
    this->hInicio=inicio;
    this->contactos=contactos;
    this->lugar=lugar;
}
