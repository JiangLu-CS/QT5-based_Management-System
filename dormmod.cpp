#include "dormmod.h"
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

dormmod::dormmod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dormmod)
{
    ui->setupUi(this);
}

dormmod::~dormmod()
{
    delete ui;
}

void dormmod::on_pushButton_clicked()
{
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

   QString manager = ui->manager->text();
   query.exec("insert into dorm VALUES ('NULL','"+manager+"')");

   QMessageBox::information(this, "您好", "新增宿舍成功");


}
    if( ui->del->isChecked()){
   QString no = ui->id->text();

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
   query.exec("delete from dorm where did="+no+" ;" );
   QMessageBox::information(this, "您好", "删除宿舍成功");
}
    if( ui->mod->isChecked()){
   QString no = ui->id->text();
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
   if(!ui->remark->text().isEmpty()){
       query.exec("update dorm set remark='"+ui->remark->text()+"' where did="+no+"" );
   }
   if(!ui->manager->text().isEmpty()){
       query.exec("update dorm set manager='"+ui->manager->text()+"' where did="+no+"" );
   }
   query.exec("select did from dorm where remark ='"+ui->remark->text()+"' " );
   while(query.next()){
       QString sno = query.value(0).toString();
       QMessageBox::information(this, "您好", "新增宿舍成功,宿舍号为："+sno+"");
   }
   QMessageBox::information(this, "您好", "修改宿舍信息成功");
}

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
        query.exec("select did,remark,manager from dorm where did="+no+"" );



         if(query.next())
            {
             ui->id->setText(query.value(0).toString());
             ui->remark->setText(query.value(1).toString());
             ui->manager->setText(query.value(2).toString());
         }
}
}

void dormmod::on_pushButton_2_clicked()
{
    dormmanage *t = new dormmanage;
    this->hide();
    t->show();
}
