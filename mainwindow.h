#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listadoble.h"
#include "listadenlazada.h"
#include "listasimple.h"
#include "lugares.h"
#include "contacto.h"
#include "evento.h"
#include "dias.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();


private slots:
    void on_Eventos_doubleClicked(const QModelIndex &index);

    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_3_clicked();

    void on_pushButton_12_clicked();

    void on_lstcontacts_clicked(const QModelIndex &index);

    void on_lstplaces_doubleClicked(const QModelIndex &index);

    void on_lstplaces_clicked(const QModelIndex &index);

    void on_lstcontacts_doubleClicked(const QModelIndex &index);

    void on_btneditar_clicked();

    void on_btnguardar_clicked();

    void on_Eventos_clicked(const QModelIndex &index);

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_btnCguardar_clicked();

    void on_btnagregar_clicked();

    void on_pushButton_11_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_imprimir_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
     ListaDEnlazada<Contacto> *lstContactos = new ListaDEnlazada<Contacto>();
     ListaSimple<Lugares> *lstlugares = new ListaSimple<Lugares>();
     ListaDoble<Dias> *lstdias = new ListaDoble<Dias>();
     ListaenlazadaO<Evento> eventoE;
     Nodo<Dias> *proceso;
     QString invitados="";
     QString lugar="";
     int dactual,mactual,yactual=0;
     int elegir;
};

#endif // MAINWINDOW_H
