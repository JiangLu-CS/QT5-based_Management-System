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
selectcourse::selectcourse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectcourse)
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

        model->setQuery("select cid,cname,bname,tname,classhour,credit from course,book,teacher"
                        " where course.book=book.bid and course.teacher=teacher.tid" );
        model->setHeaderData(0, Qt::Horizontal, tr("id"));
        model->setHeaderData(1, Qt::Horizontal, tr("科目"));
        model->setHeaderData(2, Qt::Horizontal, tr("书号"));
        model->setHeaderData(3, Qt::Horizontal, tr("教师"));
        model->setHeaderData(4, Qt::Horizontal, tr("学时"));
        model->setHeaderData(5, Qt::Horizontal, tr("学分"));


        ui->tableView->setModel(model);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑


}

selectcourse::~selectcourse()
{
    delete ui;
}

void selectcourse::on_pushButton_clicked()
{
    this->hide();
    TeacherMain *m = new TeacherMain;
    m->show();
}

void selectcourse::on_search_clicked()
{
    QString course = ui->coursename->text();
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
     QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("select * from course where cname like '%"+course+"%'" );
         model->setHeaderData(0, Qt::Horizontal, tr("id"));
         model->setHeaderData(1, Qt::Horizontal, tr("科目"));
         model->setHeaderData(2, Qt::Horizontal, tr("书号"));
         model->setHeaderData(3, Qt::Horizontal, tr("教师"));
         model->setHeaderData(4, Qt::Horizontal, tr("学时"));
         model->setHeaderData(5, Qt::Horizontal, tr("学分"));


         ui->tableView->setModel(model);
         ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑

}
