#ifndef EVENTO_H
#define EVENTO_H
#include "string.h"
#include"listasimple.h"


class evento
{
private:
     string titulo;
     string descripcion;
     string fecha;
     string hInicio;
     string duracion;
     ListaSimple<T> contactos;
public:
    evento();
};

#endif // EVENTO_H
