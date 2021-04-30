#include "dormall.h"
#include "ui_dormall.h"
#include"dormmanage.h"
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
dormall::dormall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dormall)
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
        model->setQuery("select * from dorm" );
        model->setHeaderData(0, Qt::Horizontal, tr("id"));
        model->setHeaderData(1, Qt::Horizontal, tr("评价历史"));
        model->setHeaderData(2, Qt::Horizontal, tr("房管"));
        ui->tableView->setModel(model);
}

dormall::~dormall()
{
    delete ui;
}

void dormall::on_pushButton_clicked()
{
    dormmanage *t = new dormmanage;
    this->hide();
    t->show();
}
