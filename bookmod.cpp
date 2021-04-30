#include "bookmod.h"
#include "ui_bookmod.h"
#include "dormmod.h"
#include"book.h"
#include "ui_dormmod.h"
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
bookmod::bookmod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookmod)
{
    ui->setupUi(this);
}

bookmod::~bookmod()
{
    delete ui;
}

void bookmod::on_pushButton_clicked()
{
    if( ui->find->isChecked()){
        QString no=ui->id->text();
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
           qDebug() << "Failed to connect to root mysql admin";
         else qDebug() << "open";}
        QSqlQuery query(db);
        db.exec("SET NAMES 'GBK'");
        query.exec("select bid,bname,price from book where bid="+no+"" );



         if(query.next())
            {
             ui->id->setText(query.value(0).toString());
             ui->name->setText(query.value(1).toString());
             ui->price->setText(query.value(2).toString());
         }
    }

    if( ui->add->isChecked()){
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
   qDebug() << "Failed to connect to root mysql admin";
    else qDebug() << "open";}
   QSqlQuery query(db);
   db.exec("SET NAMES 'GBK'");
   QString name = ui->name->text();
   QString price = ui->price->text();
   query.exec("insert into book VALUES ('"+name+"','"+price+"')");
   query.exec("select bid from book where bname ='"+name+"' " );
   while(query.next()){
       QString sno = query.value(0).toString();
       QMessageBox::information(this, "您好", "新增书成功,该书书号为："+sno+"");
   }
   QMessageBox::information(this, "您好", "新增书成功");

}
}


void bookmod::on_pushButton_2_clicked()
{
    book *b = new book;
    this->hide();
    b->show();
}
