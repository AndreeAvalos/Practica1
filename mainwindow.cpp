#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <string>
#include <QDebug>
#include"listadoble.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->fecha->setText(ui->calendarWidget->selectedDate().toString("dd' de 'MMMM' del 'yyyy"));
    ui->dia->setText(ui->calendarWidget->selectedDate().toString("dddd"));
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
    int year = date.year();
    int day=date.day();
    int mounth=date.month();

    ui->fecha->setText(ui->calendarWidget->selectedDate().toString("dd' de 'MMMM' del 'yyyy"));
    ui->dia->setText(ui->calendarWidget->selectedDate().toString("dddd"));
}
