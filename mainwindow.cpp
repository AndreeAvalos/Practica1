#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <vector>

#include <QDebug>
#include <QFileDialog>
#include <fstream>
#include <QJsonObject>
#include <QJsonDocument>
#include "listadoble.cpp"
#include "listadenlazada.cpp"
#include "listasimple.cpp"
#include "evento.h"
#include <QJsonArray>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->fecha->setText(ui->calendarWidget->selectedDate().toString("dd' de 'MMMM' del 'yyyy"));//Sirve para obtener la fecha del calendario
    ui->dia->setText(ui->calendarWidget->selectedDate().toString("dddd"));//obtenemos el dia (ej. Lunes)
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Eventos_doubleClicked(const QModelIndex &index)
{
    int inde = index.column();

}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    int year = date.year();//Obtenemos el ano
    int day=date.day();//obtenemos el dia
    int mounth=date.month();//obtenemos el mes

    ui->fecha->setText(ui->calendarWidget->selectedDate().toString("dd' de 'MMMM' del 'yyyy"));//Sirve para obtener la fecha del calendario
    ui->dia->setText(ui->calendarWidget->selectedDate().toString("dddd"));//Obtenemos el dia(ej.Lunes)
    ui->Eventos->clear();

    //metodo para traer los eventos
    if(lstdias->empty()==false){
        if(lstdias->buscar(day,mounth,year)==true){

            ListaSimple<Evento> actual = lstdias->getEvento(day,mounth,year);
            eventoE=actual;
            for(int i=0; i< actual.size;i++){
                ui->Eventos->addItem(actual.getValor(i).titulo);
            }



        }else{

        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    //Lista de contactos

    //lstContactos = new ListaDEnlazada<Contacto>();


}

void MainWindow::on_pushButton_12_clicked()
{
    //Boton para la carga de archivos JSON
    try{
    QString fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("Json Files (*.json)"));//Cuadro de dialogo
    //para poder elegir la ubicacion del archivo

    QJsonDocument doc;//creamos el documento tipo JSON
    fstream ficheroEntrada;//para leer el archivo
    string linea;//
    QByteArray archivo;//
     ficheroEntrada.open(fileNames.toStdString(), ios::in);//abrimos el archivo con su ubicacion
     while (! ficheroEntrada.eof() ) {
         getline(ficheroEntrada,linea);//leemos linea por linea el archivo
         archivo.append(QString::fromStdString(linea));//lo adjuntamos al archivo
        ui->C_Json->appendPlainText(QString::fromStdString(linea));//lo imprimimos en el textArea
     }

    doc=QJsonDocument::fromJson(archivo);//
    QJsonObject jObj = doc.object();//hacemos objeto el JSON
    QJsonArray eventos = jObj["calendario"].toArray();//Obtenemos los valores de los eventos
    QJsonArray contactos = jObj["contactos"].toArray();//Obtenemos los valores de los contactos
    QJsonArray lugares = jObj["lugares"].toArray();//Obtenemos los valores de los lugares
    QJsonObject ar1;
    //cargar lista de contactos
    for(int i=0; i<contactos.count();i++){
       ar1 = contactos.at(i).toObject();
        Contacto contacto (ar1["nombres"].toString(),ar1["apellidos"].toString(),ar1["nickname"].toString(),ar1["correo"].toString(),ar1["edad"].toInt(),ar1["telefono"].toString());
        //qInfo()<<contacto.nickname;
        lstContactos->add(contacto);
       //ui->lstcontacts->addItem(ar1["nickname"].toString());

    }
    //cargar lista de lugares
    for(int i = 0 ; i < lugares.count();i++){
        ar1 = lugares.at(i).toObject();
        Lugares lugar (ar1["nombre"].toString(),ar1["latitud"].toDouble(),ar1["longitud"].toDouble(),ar1["direccion"].toString());
        lstlugares->add(lugar);
        ui->lstplaces->addItem(ar1["nombre"].toString());
    }
    //imprimir contactos en listview
    for(int i = 0; i< lstContactos->size;i++){
        ui->lstcontacts->addItem(lstContactos->getValor(i).nickname);
    }

    vector<string> fecha;
    size_t found;

    string line,linea2;

    //cargar lista de eventos
    for(int i = 0 ; i<eventos.count();i++){
        ar1 = eventos.at(i).toObject();
         QString linea=ar1["fecha"].toString();
        line = linea.toStdString();
        found = line.find("-");
        fecha.push_back(line.substr(0,found));
        fecha.push_back(line.substr(found+1,line.size()));

        linea2 = fecha[1];
        fecha.pop_back();
        found=linea2.find("-");
        fecha.push_back(linea2.substr(0,found));
        fecha.push_back(linea2.substr(found+1,linea2.size()));

        qInfo()<<QString::fromStdString(fecha[0])<<" "<<QString::fromStdString(fecha[1])<<QString::fromStdString(fecha[2])<<endl;
        QJsonArray eventos = ar1["eventos"].toArray();
        ListaSimple<Evento> lsteventos;
        Evento ev;
        if(!eventos.isEmpty()){
            for(int j = 0; j < eventos.count();j++){
                ar1 = eventos.at(j).toObject();
                ev.titulo=ar1["titulo"].toString();
                ev.descripcion=ar1["descripcion"].toString();
                ev.contactos=ar1["participantes"].toString();
                ev.fecha=ar1["fecha"].toString();
                ev.hInicio=ar1["hora"].toString();
                ev.lugar=ar1["lugar"].toString();
                ev.duracion=ar1["duracion"].toString();
                qInfo()<<ar1["titulo"].toString();
                lsteventos.add(ev);
            }
        }

        QDate firstFriday(atoi(fecha[0].c_str()),atoi(fecha[1].c_str()),atoi(fecha[2].c_str()));
        QTextCharFormat firstFridayFormat;
        if(lsteventos.size!=0 && lsteventos.size<3){
         firstFridayFormat.setBackground(Qt::lightGray);
        }else if(lsteventos.size>=3 && lsteventos.size<5){
            firstFridayFormat.setBackground(Qt::green);
        }else if(lsteventos.size>=5){
            firstFridayFormat.setBackground(Qt::darkGreen);
        }
        ui->calendarWidget->setDateTextFormat(firstFriday, firstFridayFormat);
        Dias actividad(atoi(fecha[2].c_str()),atoi(fecha[1].c_str()),atoi(fecha[0].c_str()),lsteventos);
        lstdias->add(actividad);


    }
    proceso=lstdias->first;
    }catch(exception e){

    }
}

void MainWindow::on_lstcontacts_clicked(const QModelIndex &index)
{
    int inde = index.row();
    Contacto actual = lstContactos->getValor(inde);
    ui->Cname->setText(actual.nombre);
    ui->Capeliido->setText(actual.apellido);
    ui->Cnickname->setText(actual.nickname);

    int i = actual.edad;
    QString s;
    std::stringstream out;
    out << i;
    s = QString::fromStdString(out.str());

    ui->Cedad->setText(s);
    ui->Ctelefono->setText(actual.telefono);
    ui->Ccorreo->setText(actual.correo);

}

void MainWindow::on_lstplaces_clicked(const QModelIndex &index)
{
    int inde =index.row();
    Lugares actual= lstlugares->getValor(inde);
    ui->Lnombre->setText(actual.nombre);

    double i = actual.latitud;
    QString s;
    std::stringstream out;
    out << i;
    s = QString::fromStdString(out.str());

    ui->Llatitud->setText(s);

    i = actual.longitud;
    std::stringstream out2;
    out2 << i;
    s = QString::fromStdString(out2.str());

    ui->Llongitud->setText(s);
    ui->Ldireccion->setText(actual.direccion);
}

void MainWindow::on_lstplaces_doubleClicked(const QModelIndex &index)
{
    ui->Lnombre->setEnabled(true);
    ui->Llatitud->setEnabled(true);
    ui->Llongitud->setEnabled(true);
    ui->Ldireccion->setEnabled(true);
    ui->btnguardar->setEnabled(true);
}

void MainWindow::on_lstcontacts_doubleClicked(const QModelIndex &index)
{
    ui->Cname->setEnabled(true);
    ui->Capeliido->setEnabled(true);
    ui->Cnickname->setEnabled(true);
    ui->Ccorreo->setEnabled(true);
    ui->Cedad->setEnabled(true);
    ui->Ctelefono->setEnabled(true);
    ui->btneditar->setEnabled(true);
}

void MainWindow::on_btneditar_clicked()
{
    ui->Cname->setEnabled(false);
    ui->Capeliido->setEnabled(false);
    ui->Cnickname->setEnabled(false);
    ui->Ccorreo->setEnabled(false);
    ui->Cedad->setEnabled(false);
    ui->Ctelefono->setEnabled(false);
    ui->btneditar->setEnabled(false);
}

void MainWindow::on_btnguardar_clicked()
{
    ui->Lnombre->setEnabled(false);
    ui->Llatitud->setEnabled(false);
    ui->Llongitud->setEnabled(false);
    ui->Ldireccion->setEnabled(false);
    ui->btnguardar->setEnabled(false);
}

void MainWindow::on_Eventos_clicked(const QModelIndex &index)
{
    ui->InfEvet->clear();
    int inde = index.row();
    Evento ev = eventoE.getValor(inde);
    ui->InfEvet->appendPlainText(ev.titulo);
    ui->InfEvet->appendPlainText(ev.descripcion);
    ui->InfEvet->appendPlainText(ev.hInicio);
    ui->InfEvet->appendPlainText(ev.lugar);
    ui->InfEvet->appendPlainText(ev.contactos);

}

void MainWindow::on_pushButton_9_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->Eventos->clear();

    if(proceso!=nullptr){
        Dias actual2 = proceso->data;

    ListaSimple<Evento> actual =actual2.Eventos;
    eventoE=actual;
    for(int i=0; i< actual.size;i++){
        ui->Eventos->addItem(actual.getValor(i).titulo);
    }
    proceso=proceso->Siguiente;
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->Eventos->clear();

    if(proceso!=nullptr){
        Dias actual2 = proceso->data;

    ListaSimple<Evento> actual =actual2.Eventos;
    eventoE=actual;
    for(int i=0; i< actual.size;i++){
        ui->Eventos->addItem(actual.getValor(i).titulo);
    }
    proceso=proceso->Anterior;
    }
}
