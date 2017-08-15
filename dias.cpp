#include "dias.h"
template<typename T>
dias<T>::dias()
{
    this->Eventos=nullptr;
    this.numd=0;
    this->fecha="";

}
template <typename T>
dias<T>::dias(int dia_ ,string fecha_ ,ListaSimple<T> eventos){
    this->Eventos = eventos;
    this->fecha=fecha_;
    this->numd=dia_;
}

