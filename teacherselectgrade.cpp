#include "teacherselectgrade.h"
#include "ui_teacherselectgrade.h"
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
#include"showallgrades.h"
teacherselectgrade::teacherselectgrade(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teacherselectgrade)
{
    ui->setupUi(this);
}

teacherselectgrade::~teacherselectgrade()
{
    delete ui;
}

void teacherselectgrade::on_select_clicked()
{
     QString sstuno=ui->stuno->text();
     QString ssubject=ui->subject->text();
     qDebug()<<"学生学号："<<sstuno;
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
     query.exec("select stuid,cname,grade from score,course where stuid="+sstuno+"and cname='"+ssubject+"' and course.cid=score.cid" );



      if(query.next())
         {
          ui->stuno->setText(query.value(0).toString());
          ui->subject->setText(query.value(1).toString());
          ui->grade->setText(query.value(2).toString());
           }


}

void teacherselectgrade::on_update_clicked()
{
    QString sstuno=ui->stuno->text();
    QString ssubject=ui->subject->text();
    QString sscore=ui->grade->text();
    qDebug()<<"学生学号："<<sstuno;
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
    query.exec("update score set grade="+sscore+" where stuid="+sstuno+" and cid='"+ssubject+"'" );
    QMessageBox::information(this, "您好", "成绩已修改成功");
}

void teacherselectgrade::on_insert_clicked()
{
    QString sstuno=ui->stuno->text();
    QString ssubject=ui->subject->text();
    QString sscore=ui->grade->text();
    qDebug()<<"学生学号："<<sstuno;
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
    query.exec("INSERT INTO score VALUES ("+ssubject+",'"+sstuno+"',"+sscore+" );" );
    QMessageBox::information(this, "您好", "已新增该学生的成绩");
}

void teacherselectgrade::on_deletegrade_clicked()
{
    QString sstuno=ui->stuno->text();
    QString ssubject=ui->subject->text();
    qDebug()<<"学生学号："<<sstuno;
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
    query.exec("delete from score where stuid="+sstuno+" and cid='"+ssubject+"';" );
    QMessageBox::information(this, "您好", "已删除该学生该科目的成绩");
}

void teacherselectgrade::on_selectall_clicked()
{

      this->hide();
      showallgrades  *all=new showallgrades;
      all->show();

}

void teacherselectgrade::on_back1_clicked()
{
    this->hide();
    TeacherMain *all=new TeacherMain;
    all->show();
}
