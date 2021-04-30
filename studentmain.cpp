#include "studentmain.h"
#include "ui_studentmain.h"
#include "mainwindow.h"
#include"setting.h"
#include  <QtDebug>
#include <QWidget>
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<studentmain.h>
#include "stuevaluate.h"
#include "stuselectcourse.h"
#include"stuinformation.h"
#include"stusearchgrade.h"
studentmain::studentmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentmain)
{
    ui->setupUi(this);
}

studentmain::~studentmain()
{
    delete ui;
}
void studentmain::on_evaluation_clicked()
{stuevaluate* f=new stuevaluate;
    this->hide();
    f->show();
}
void studentmain::on_searchgrade_clicked()
{stusearchgrade *h=new stusearchgrade;
this->hide();
h->show();}

void studentmain::on_selectcourse_clicked()
{stuselectcouse *g=new stuselectcouse;
this->hide();
g->show();}
void studentmain::on_back_clicked()
{this->hide();
    MainWindow *h=new MainWindow;
    h->show();}


void studentmain::on_information_clicked()
{
    this->hide();
    stuinformation *k=new stuinformation;
    k->show();
}
