#ifndef EVENTOS_H
#define EVENTOS_H
#include "listasimple.h"
#include <QString>
#include "contacto.h"


class Eventos
{
public:
    Eventos();
    QString titulo;
    QString descripcion;
    QString fecha;
    QString hInicio;
    QString duracion;
    ListaSimple<Contacto> contactos;
    Eventos(QString,QString,QString,QString,QString,ListaSimple<Contacto>);
};

#endif // EVENTOS_H
