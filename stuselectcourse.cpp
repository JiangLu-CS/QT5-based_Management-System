#include "stuselectcourse.h"
#include "ui_stuselectcourse.h"
#include "mainwindow.h"
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
#include"setting.h"
#include"studentmain.h"
stuselectcouse::stuselectcouse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stuselectcouse)
{
    ui->setupUi(this);
}

stuselectcouse::~stuselectcouse()
{
    delete ui;
}


void stuselectcouse::on_back_clicked()
{   this->hide();
    studentmain *m = new studentmain;
    m->show();
}

void stuselectcouse::on_query_clicked()
{
    QString subject=ui->course->text();
        //QString sid=ui->stuid->text();
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
        QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
        model->setQuery("select cid,cname,classhour,credit,book,bname,price,tname from book,course,teacher where course.book=book.bid and course.teacher=teacher.tid and cname='"+subject+"'");
        model->setHeaderData(0, Qt::Horizontal, tr("课程号"));
        model->setHeaderData(1, Qt::Horizontal, tr("课程名"));
        model->setHeaderData(2, Qt::Horizontal, tr("学时"));
        model->setHeaderData(3, Qt::Horizontal, tr("学分"));
        model->setHeaderData(4, Qt::Horizontal, tr("书号"));
        model->setHeaderData(5, Qt::Horizontal, tr("书名"));
        model->setHeaderData(6, Qt::Horizontal, tr("书价"));
        model->setHeaderData(7, Qt::Horizontal, tr("老师"));
        ui->tableView->setModel(model);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void stuselectcouse::on_insert_clicked()
{
    //QString sid=ui->stuid->text();

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      { db = QSqlDatabase::database("qt_sql_default_connection");
       qDebug() << "opening";}
    else{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("DESKTOP-M50HCP8");                        //选择本地主机，127.0.1.1
    QString dsn="DRIVER={SQL SERVER};SERVER=127.0.0.1;DATABASE=master;UID=sa;PWD=123456;";
    db.setDatabaseName(dsn);
    db.setUserName("sa");                               //登录用户
    db.setPassword("123456");
    if (!db.open())
       qDebug() << "Failed to connect to root mysql admin";
    else qDebug() << "open";}
    QSqlQuery query(db);
    db.exec("SET NAMES 'GBK'");
     QSqlQuery queryl;
    queryl.prepare("select cid from course where cname=?");
        QString cname=ui->course->text();
        queryl.addBindValue(cname);
            queryl.exec();
            queryl.next();
            QString cid=queryl.value(0).toString();
            queryl.prepare("INSERT INTO score(cid,stuid,grade) VALUES (:cid, :stuid,:grade)"); //准备执行SQL查询
                queryl.bindValue(":stuid", usernamelogin);   //在这定占位符上确定绑定的值
                queryl.bindValue(":cid", cid);
                queryl.bindValue(":grade", 0);
                queryl.exec();
                QMessageBox::information(this, "您好", "选课成功");

}

void stuselectcouse::on_delete_2_clicked()
{
    //QString sid=ui->stuid->text();
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      { db = QSqlDatabase::database("qt_sql_default_connection");
       qDebug() << "opening";}
    else{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("DESKTOP-M50HCP8");                        //选择本地主机，127.0.1.1
    QString dsn="DRIVER={SQL SERVER};SERVER=127.0.0.1;DATABASE=master;UID=sa;PWD=123456;";
    db.setDatabaseName(dsn);
    db.setUserName("sa");                               //登录用户
    db.setPassword("123456");
    if (!db.open())
       qDebug() << "Failed to connect to root mysql admin";
    else qDebug() << "open";}
    QSqlQuery query(db);
    db.exec("SET NAMES 'GBK'");
    QSqlQuery queryl;
   queryl.prepare("select cid from course where cname=?");
       QString cname=ui->course->text();
       queryl.addBindValue(cname);
           queryl.exec();
           queryl.next();
           QString cid=queryl.value(0).toString();
           queryl.prepare(QString("DELETE FROM score WHERE cid=? and stuid=?"));
           queryl.addBindValue(cid);
           queryl.addBindValue(usernamelogin);
           queryl.exec();
          QMessageBox::information(this, "您好", "退课成功");
}
