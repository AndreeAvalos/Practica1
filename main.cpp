#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include <iostream>
#include "listadoble.h"
#include "listadoble.cpp"
using namespace std;

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
   // MainWindow w;
    //w.show();
    ListaDoble<int> listar;
    listar.add(1);
    listar.add(2);
    listar.add(3);
    listar.add(4);
    listar.add(5);
    listar.imprimir();




   // return a.exec();
}
