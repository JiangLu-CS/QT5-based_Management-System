#include "teachermod.h"
#include"allteacher.h"
#include "ui_teachermod.h"
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
#include "selectcourse.h"
#include"showstudent.h"
#include"studentmanage.h"
#include"dormmanage.h"
teachermod::teachermod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teachermod)
{
    ui->setupUi(this);
}

teachermod::~teachermod()
{
    delete ui;
}

void teachermod::on_pushButton_clicked()
{
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
    query.exec("insert into teacher VALUES ('"+name+"','123456','0')");
    query.exec("select tid from teacher where tname ='"+name+"' " );
    while(query.next()){
        QString sno = query.value(0).toString();
        QMessageBox::information(this, "您好", "新增老师成功,老师账号为："+sno+"。初始密码为：123456");
    }
    //QMessageBox::information(this, "您好", "新增老师成功");
}

void teachermod::on_pushButton_2_clicked()
{
    QString no = ui->name->text();
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
    query.exec("delete from teacher where tname='"+no+"' ;" );
    QMessageBox::information(this, "您好", "删除老师成功");
}

void teachermod::on_pushButton_3_clicked()
{
    allteacher *t = new allteacher;
    this->hide();
    t->show();
}
