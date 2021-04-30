#include "stusearchgrade.h"
#include "ui_stusearchgrade.h"
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
#include "setting.h"
#include"studentmain.h"

stusearchgrade::stusearchgrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stusearchgrade)
{
    ui->setupUi(this);
}

stusearchgrade::~stusearchgrade()
{
    delete ui;
}

void stusearchgrade::on_back_clicked()
{
    this->hide();
    studentmain *m = new studentmain;
    m->show();
}

void stusearchgrade::on_pushButton_clicked()
{
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
    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    model->setQuery("select stuid,score.cid,cname,grade from score,course where score.cid=course.cid and stuid="+usernamelogin);
    model->setHeaderData(0, Qt::Horizontal, tr("学号"));
    model->setHeaderData(1, Qt::Horizontal, tr("课程号"));
    model->setHeaderData(2, Qt::Horizontal, tr("课程名"));
    model->setHeaderData(3, Qt::Horizontal, tr("成绩"));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void stusearchgrade::on_pushButton_2_clicked()
{   QString subject=ui->subject->text();
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
    QSqlQueryModel *modela = new QSqlQueryModel(ui->tableView);
    modela->setQuery("select stuid,score.cid,cname,grade from score,course where score.cid=course.cid and stuid="+usernamelogin+"and cname='"+subject+"'");

    modela->setHeaderData(0, Qt::Horizontal, tr("学号"));
    modela->setHeaderData(1, Qt::Horizontal, tr("课程号"));
    modela->setHeaderData(2, Qt::Horizontal, tr("课程名"));
    modela->setHeaderData(3, Qt::Horizontal, tr("成绩"));
    ui->tableView->setModel(modela);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
