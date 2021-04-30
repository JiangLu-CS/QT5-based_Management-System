#include "showteacher.h"
#include "ui_showteacher.h"
#include "showstudentyear.h"
#include"allteacher.h"
#include "ui_showstudentyear.h"
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
showteacher::showteacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showteacher)
{
    ui->setupUi(this);
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      { db = QSqlDatabase::database("qt_sql_default_connection");
       qDebug() << "opening";}
    else{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("SQLTEST");
    db.setUserName(SQLuser);
    db.setPassword(SQLpassword);
    if (!db.open())
        {qDebug() << "Failed to connect to root mysql admin";}
     else qDebug() << "open";}

    QSqlQuery query(db);
    db.exec("SET NAMES 'GBK'");
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("select * from teacher" );
        model->setHeaderData(0, Qt::Horizontal, tr("id"));
        model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
        ui->tableView->setModel(model);
}

showteacher::~showteacher()
{
    delete ui;
}

void showteacher::on_pushButton_clicked()
{
    allteacher *a = new allteacher;
    this->hide();
    a->show();
}
