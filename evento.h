#ifndef EVENTO_H
#define EVENTO_H
#include <QString>
#include "listasimple.h"

class Evento
{
public:
    Evento();
    QString titulo;
    QString descripcion;
    QString fecha;
    QString hInicio;
    QString duracion;
    QString lugar;
    QString contactos;
    Evento(QString,QString,QString,QString,QString,QString,QString);
};

#endif // EVENTO_H
