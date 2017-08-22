#include "lugares.h"

Lugares::Lugares()
{

}
Lugares::Lugares(QString nombre, double latitud, double longitud, QString direccion){
    this->direccion=direccion;
    this->nombre=nombre;
    this->latitud=latitud;
    this->longitud=longitud;

}
QString Lugares::toString(){
   return this->nombre;
}
