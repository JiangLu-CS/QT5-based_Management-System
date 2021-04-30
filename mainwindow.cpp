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
#include "teamain.h"
#include "stuinformation.h"
#include "studentmain.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("SQLTEST");
    db.setUserName("jianglu");
    db.setPassword("123");
    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";
    else qDebug() << "open";
    //输出可用数据库
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
     qDebug()<<"用户名："<<username;
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
     if( ui->admin->isChecked()){
         qDebug()<<"欢迎您";
     QSqlQuery query(db);
     db.exec("SET NAMES 'GBK'");
     query.exec("select username,upassword from admin");
     bool T=false;
     while(query.next())
                {
         qDebug()<<"coming";
                   QString user = query.value(0).toString();
                    QString pass = query.value(1).toString();
                    qDebug() << query.value(0).toString();
                   if(username.compare(user)==0 && password.compare(pass)==0){
                        usernamelogin=username;
                        T=true;
                        this->hide();
                        TeacherMain* f=new TeacherMain;
                       // emit sendData(username);
                         //emit sendData(username+"&"+password);
                        f->show();
                    }

                }
     if(T==false)
      {QMessageBox::information(this, "警告", "用户名或密码错误");}
     }
     else if( ui->student->isChecked()){
         qDebug()<<"欢迎您学生";
     QSqlQuery query(db);
     db.exec("SET NAMES 'GBK'");
     query.exec("select stuid,spassword from student");
     bool T=false;
     while(query.next())
                {
         qDebug()<<"coming";
                   QString user = query.value(0).toString();
                    QString pass = query.value(1).toString();
                    qDebug() << query.value(0).toString();
                   if(username.compare(user)==0 && password.compare(pass)==0){
                        usernamelogin=username;
                        T=true;
                        this->hide();
                        studentmain* f=new studentmain;
                       // emit sendData(username);
                         //emit sendData(username+"&"+password);
                        f->show();
                    }
     }
                   if(T==false)
                    {QMessageBox::information(this, "警告", "用户名或密码错误");}

     }
     else if( ui->teacher->isChecked()){
         qDebug()<<"欢迎您老师";
     QSqlQuery query(db);
     db.exec("SET NAMES 'GBK'");
     query.exec("select tid,tpassword from teacher");
     bool T=false;
     while(query.next())
                {
         qDebug()<<"coming";
                   QString user = query.value(0).toString();
                    QString pass = query.value(1).toString();
                    qDebug() << query.value(0).toString();
                   if(username.compare(user)==0 && password.compare(pass)==0){
                        usernamelogin=username;
                        T=true;
                        this->hide();
                        teamain* f=new teamain;
                       // emit sendData(username);
                         //emit sendData(username+"&"+password);
                        f->show();
                    }
                }

     if(T==false)
     { QMessageBox::information(this, "警告", "用户名或密码错误");}
     }

}



