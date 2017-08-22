#ifndef LUGARES_H
#define LUGARES_H
#include <QString>

class Lugares
{
public:
    Lugares();
    Lugares(QString,double,double,QString);
    QString toString();
    double longitud,latitud;
    QString nombre,direccion;

};

#endif // LUGARES_H
