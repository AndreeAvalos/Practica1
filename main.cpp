#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include <iostream>
#include "listadoble.h"
#include "listadoble.cpp"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();





   return a.exec();
}
