#ifndef CONTACTO_H
#define CONTACTO_H
#include <QString>
#include <iostream>


class Contacto
{
public:
    Contacto();
    int compare(Contacto);
    Contacto(QString,QString,QString,QString,int,QString);
    QString correo,nombre,apellido,nickname,telefono;
    int edad;
    QString toString();

};

#endif // CONTACTO_H
