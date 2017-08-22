#include "contacto.h"
#include <iostream>

Contacto::Contacto()
{
    this->apellido="";
    this->nombre="";
    this->correo="";
    this->nickname="";
    this->edad=0;
    this->telefono="";

}
Contacto::Contacto(QString nombre,QString apellido,QString nickname,QString correo,int edad, QString tel){

    this->nombre=nombre;
    this->apellido=apellido;
    this->nickname=nickname;
    this->edad=edad;
    this->telefono=tel;
    this->correo=correo;
}
int Contacto::compare(Contacto contacto){
    int comparacion = this->nickname.compare(contacto.nickname);
    return comparacion;

}
QString Contacto::toString(){
    return this->nickname;
}
