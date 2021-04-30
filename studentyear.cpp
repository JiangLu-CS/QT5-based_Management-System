#include "studentyear.h"
#include"studentmanage.h"
#include "ui_studentyear.h"
#include"teachermain.h"
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
studentyear::studentyear(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentyear)
{
    ui->setupUi(this);
}

studentyear::~studentyear()
{
    delete ui;
}

void studentyear::on_pushButton_3_clicked()
{
    TeacherMain *t = new TeacherMain;
    this->hide();
    t->show();
}

void studentyear::on_show_clicked()
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
        {qDebug() << "Failed to connect to root mysql admin";}
     else qDebug() << "open";}
    QString year = ui->year->text();

    QSqlQuery query(db);
    db.exec("SET NAMES 'GBK'");
    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("select * from student where stuid like '%"+year+"%'" );
        model->setHeaderData(0, Qt::Horizontal, tr("id"));
        model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
        model->setHeaderData(2, Qt::Horizontal, tr("性别"));
        model->setHeaderData(3, Qt::Horizontal, tr("年龄"));
        model->setHeaderData(4, Qt::Horizontal, tr("专业号"));
        model->setHeaderData(6, Qt::Horizontal, tr("宿舍号"));
        ui->tableView->setModel(model);
}

void studentyear::on_delete_2_clicked()
{
    QString no = ui->year->text();

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
    query.exec("delete from student where stuid like '%"+no+"%' ;" );
    query.exec("delete from score where stuid like '%"+no+"%' ;" );
    QMessageBox::information(this, "您好", "删除该学籍所有学生成功");
}

void studentyear::on_pushButton_clicked()
{
    TeacherMain *t = new TeacherMain;
    this->hide();
    t->show();
}
