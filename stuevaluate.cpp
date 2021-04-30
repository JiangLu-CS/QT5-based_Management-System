#include "stuevaluate.h"
#include "ui_stuevaluate.h"
#include "mainwindow.h"
#include  <QtDebug>
#include <QWidget>
#include<QDialog>
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSql>
#include <QSqlQueryModel>
#include<QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QSqlRecord>
#include"setting.h"
#include"studentmain.h"
stuevaluate::stuevaluate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stuevaluate)
{
    ui->setupUi(this);
}

stuevaluate::~stuevaluate()
{
    delete ui;
}

void stuevaluate::on_back_clicked()
{
    this->hide();
    studentmain *m = new studentmain;
    m->show();
}

void stuevaluate::on_submit_clicked()
{
    QString tname = ui->tname->text();
    QString content=ui->content->toPlainText();
    //QString stuid=ui->stuid->text();
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
     QSqlQuery queryl;
     query.exec("select tid from teacher where tname ='"+tname+"' " );
     while(query.next()){
         QString tid = query.value(0).toString();
         //QMessageBox::information(this, "您好", "新增学生成功,学生学号为："+sno+"");
     queryl.prepare("INSERT INTO evaluation (stuid,tid,content) VALUES (:stuid, :tid,:content)"); //准备执行SQL查询
     queryl.bindValue(":stuid", usernamelogin);   //在这定占位符上确定绑定的值
     queryl.bindValue(":tid", tid);
     queryl.bindValue(":content", content);
     queryl.exec();
     qDebug() << "插入成功"<<endl;
     QMessageBox::information(this, "您好", "评教成功");
     }
}
