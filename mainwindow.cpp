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
#include "listaenlazadao.cpp"
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
    int year = ui->calendarWidget->selectedDate().year();//Obtenemos el ano
    int day=ui->calendarWidget->selectedDate().day();//obtenemos el dia
    int mounth=ui->calendarWidget->selectedDate().month() ;//obtenemos el mes
    dactual=day;
    mactual=mounth;
    yactual= year;

    ui->fecha->setText(ui->calendarWidget->selectedDate().toString("dd' de 'MMMM' del 'yyyy"));//Sirve para obtener la fecha del calendario
    ui->dia->setText(ui->calendarWidget->selectedDate().toString("dddd"));//Obtenemos el dia(ej.Lunes)
    ui->Eventos->clear();

    //metodo para traer los eventos
    if(lstdias->empty()==false){
        if(lstdias->buscar(day,mounth,year)==true){

            ListaenlazadaO<Evento> actual = lstdias->getEvento(day,mounth,year);
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
    Lugares nuevo(ui->Lnombre->text(), ui->Llatitud->text().toDouble(),ui->Llongitud->text().toDouble(),ui->Ldireccion->text());
    lstlugares->add(nuevo);
    ui->lstplaces->clear();
    Nodo<Lugares> *temp= lstlugares->root;
    while(temp!=nullptr){
        ui->lstplaces->addItem(temp->data.nombre);
        temp    = temp->Siguiente;
    }

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
    QJsonArray eventos1 = jObj["calendario"].toArray();//Obtenemos los valores de los eventos
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
    ui->lstplaces->clear();
    for(int i = 0 ; i < lugares.count();i++){
        ar1 = lugares.at(i).toObject();
        Lugares lugar (ar1["nombre"].toString(),ar1["latitud"].toDouble(),ar1["longitud"].toDouble(),ar1["direccion"].toString());
        lstlugares->add(lugar);
    }
    ui->lstplaces->clear();
    Nodo<Lugares> *temp= lstlugares->root;
    while(temp!=nullptr){
        ui->lstplaces->addItem(temp->data.nombre);
        temp    = temp->Siguiente;
    }
    ui->lstcontacts->clear();
    //imprimir contactos en listview
    for(int i = 0; i< lstContactos->size;i++){
        ui->lstcontacts->addItem(lstContactos->getValor(i).nickname);
    }

    vector<string> fecha;
    size_t found;

    string line,linea2;

    //cargar lista de eventos
    for(int i = 0 ; i<eventos1.count();i++){
        ar1 = eventos1.at(i).toObject();
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
        ListaenlazadaO<Evento> lsteventos;
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
    elegir=inde;
    Evento ev = eventoE.getValor(inde);
    ui->InfEvet->appendPlainText(ev.titulo);
    ui->InfEvet->appendPlainText(ev.descripcion);
    ui->InfEvet->appendPlainText(ev.hInicio);
    ui->InfEvet->appendPlainText(ev.lugar);
    ui->InfEvet->appendPlainText(ev.contactos);

}

void MainWindow::on_pushButton_9_clicked()
{

    Evento nuevo (ui->Etitulo->text(),ui->Edecripcion->toPlainText(),ui->Eduracion->text(),"",ui->Einicio->text(),lugar,invitados);
    ListaenlazadaO<Evento> lsteventos;
    int year = ui->calendarWidget->selectedDate().year();//Obtenemos el ano
    int day= ui->calendarWidget->selectedDate().day();//obtenemos el dia
    int mounth=ui->calendarWidget->selectedDate().month() ;//obtenemos el mes
    dactual=day;
    mactual=mounth;
    yactual= year;

    if(lstdias->empty()==false){

        if(lstdias->buscar(dactual,mactual,yactual)==false){
            lsteventos.add(nuevo);
            qInfo()<< dactual<<mactual<<yactual;
            Dias ndia (dactual,mactual,yactual,lsteventos);
            lstdias->add(ndia);

        }else{

            lsteventos;
            lsteventos = lstdias->getEvento(dactual,mactual,yactual);
            lsteventos.add(nuevo);
             qInfo()<< lsteventos.size;
            lstdias->setDia(dactual,mactual,yactual,lsteventos);
             qInfo()<< dactual<<mactual<<yactual;

        }
    }else{


            lsteventos;
            lsteventos.add(nuevo);
                         qInfo()<< dactual<<mactual<<yactual;
            Dias ndia (dactual,mactual,yactual,lsteventos);
            lstdias->add(ndia);
    }

 /*if(lstdias->empty()==false){
     ListaenlazadaO<Evento> lsteventos;
    if(lstdias->buscar(dactual,mactual,yactual)==false){
        lsteventos.add(nuevo);
        Dias ndia (dactual,mactual,yactual,lsteventos);
        lstdias->add(ndia);

    }else{
        ListaenlazadaO<Evento> lsteventos;
        lsteventos = lstdias->getEvento(dactual,mactual,yactual);
        lsteventos.add(nuevo);

        //lstdias->setDia(dactual,mactual,yactual,lsteventos);

    }
 }else{
 ListaenlazadaO<Evento> lsteventos;
     lsteventos.add(nuevo);
     Dias ndia (dactual,mactual,yactual,lsteventos);
     lstdias->add(ndia);

 }
 ListaenlazadaO<Evento> lsteventos =lstdias->getEvento(dactual,mactual,yactual);
*/
 QDate firstFriday(yactual,mactual,dactual);
 QTextCharFormat firstFridayFormat;
 if(lsteventos.size!=0 && lsteventos.size<3){
  firstFridayFormat.setBackground(Qt::lightGray);
 }else if(lsteventos.size>=3 && lsteventos.size<5){
     firstFridayFormat.setBackground(Qt::green);
 }else if(lsteventos.size>=5){
     firstFridayFormat.setBackground(Qt::darkGreen);
 }
 ui->calendarWidget->setDateTextFormat(firstFriday, firstFridayFormat);
    proceso=lstdias->first;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->Eventos->clear();

    if(proceso!=nullptr){
        Dias actual2 = proceso->data;

    ListaenlazadaO<Evento> actual =actual2.Eventos;
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

    ListaenlazadaO<Evento> actual =actual2.Eventos;
    eventoE=actual;
    for(int i=0; i< actual.size;i++){
        ui->Eventos->addItem(actual.getValor(i).titulo);
    }
    proceso=proceso->Anterior;
    }
}

void MainWindow::on_btnCguardar_clicked()
{
    QString nombre,apellido,nickname, telefono,correo;
    int edad;
    nombre = ui->Cname->text();
    apellido = ui->Capeliido->text();
    nickname = ui->Cnickname->text();
    telefono=ui->Ctelefono->text();
    correo=ui->Ccorreo->text();
    edad=atoi(ui->Cedad->text().toStdString().c_str());
    Contacto nuevo (nombre,apellido,nickname,correo, edad,telefono);

    ui->Cname->setEnabled(false);
    ui->Capeliido->setEnabled(false);
    ui->Cnickname->setEnabled(false);
    ui->Cedad->setEnabled(false);
    ui->Ctelefono->setEnabled(false);
    ui->Ccorreo->setEnabled(false);

    ui->Cname->clear();
    ui->Capeliido->clear();
    ui->Cnickname->clear();
    ui->Cedad->clear();
    ui->Ctelefono->clear();
    ui->Ccorreo->clear();


    lstContactos->add(nuevo);
    ui->lstcontacts->clear();
    for(int i = 0; i< lstContactos->size;i++){
        ui->lstcontacts->addItem(lstContactos->getValor(i).nickname);
    }

}

void MainWindow::on_btnagregar_clicked()
{
    ui->Cname->setEnabled(true);
    ui->Capeliido->setEnabled(true);
    ui->Cnickname->setEnabled(true);
    ui->Cedad->setEnabled(true);
    ui->Ctelefono->setEnabled(true);
    ui->Ccorreo->setEnabled(true);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    for(int i = 0; i<lstContactos->size;i++){
        ui->comboBox->addItem(lstContactos->getValor(i).nickname);
    }
    for(int i = 0; i <lstlugares->size;i++){
        ui->comboBox_2->addItem(lstlugares->getValor(i).nombre);
    }
}

void MainWindow::on_comboBox_activated(int index)
{
   invitados+=lstContactos->getValor(index).nickname;
   ui->comboBox->removeItem(index);
}

void MainWindow::on_comboBox_2_activated(int index)
{
    lugar=lstlugares->getValor(index).nombre;
}

void MainWindow::on_imprimir_clicked()
{
    this->lstlugares->imprimir();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->lstContactos->imprimir();
}

void MainWindow::on_pushButton_5_clicked()
{
    this->lstdias->imprimir();
}

void MainWindow::on_pushButton_14_clicked()
{
    //rre
}

void MainWindow::on_pushButton_10_clicked()
{
   lstdias->getEvento(dactual,mactual,yactual).eliminar(elegir);
}
