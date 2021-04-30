#include "studentmanage.h"
#include "ui_studentmanage.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"setting.h"
#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<teachermain.h>
#include<showstudent.h>
#include<modstu.h>
studentmanage::studentmanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentmanage)
{
    ui->setupUi(this);
}

studentmanage::~studentmanage()
{
    delete ui;
}


void studentmanage::on_allstu_clicked()
{
    showstudent *h;
    this->hide();
    h=new showstudent  ;
    h->show();
}

void studentmanage::on_pushButton_clicked()
{
    TeacherMain *t = new TeacherMain;
    this->hide();
    t->show();
}

void studentmanage::on_modstu_clicked()
{
    modstu *t = new modstu;
    this->hide();
    t->show();
}
