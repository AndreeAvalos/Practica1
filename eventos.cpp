#include "eventos.h"
#include "listasimple.cpp";

Eventos::Eventos()
{
    this->titulo="";
    this->descripcion="";
    this->duracion="";
    this->fecha="";
    this->hInicio="";
}
Eventos::Eventos(QString titulo, QString descripcion, QString duracion, QString fecha, QString inicio, ListaSimple<Contacto> contactos){
    this->titulo=titulo;
    this->descripcion=descripcion;
    this->duracion=duracion;
    this->fecha=fecha;
    this->hInicio=inicio;
    this->contactos=contactos;

}
