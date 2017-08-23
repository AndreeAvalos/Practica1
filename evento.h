#ifndef EVENTO_H
#define EVENTO_H
#include <QString>

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

    int compare(Evento val){
        int compare = this->hInicio.compare(val.hInicio);
        return compare;
    }
};

#endif // EVENTO_H
