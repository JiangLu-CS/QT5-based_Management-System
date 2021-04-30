#include "bookall.h"
#include "ui_bookall.h"
#include"book.h"
#include "showstudent.h"
#include "ui_showstudent.h"
#include "selectcourse.h"
#include "ui_selectcourse.h"
#include "showallgrades.h"
#include "ui_showallgrades.h"
#include "teacherselectgrade.h"
#include "teachermain.h"
#include "teachermain.h"
#include "ui_teachermain.h"
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
#include<teachermain.h>
#include "teacherselectgrade.h"
bookall::bookall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookall)
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

        model->setQuery("select bid,bname,price from book " );
        model->setHeaderData(0, Qt::Horizontal, tr("id"));
        model->setHeaderData(1, Qt::Horizontal, tr("书名"));
        model->setHeaderData(2, Qt::Horizontal, tr("价格"));


        ui->tableView->setModel(model);
        //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑
}



bookall::~bookall()
{
    delete ui;
}

void bookall::on_pushButton_clicked()
{
    book *b = new book;
    this->hide();
    b->show();
}
