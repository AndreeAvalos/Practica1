#ifndef NODO_H
#define NODO_H
#include <iostream>


using namespace std;
template <class T>
class Nodo
{
public:
    Nodo();//Constructor
    Nodo(T);//Constructor con parametros
    Nodo *Siguiente, *Anterior;//apuntadores
      T data;//Valor generico
private:



};

#endif // NODO_H
