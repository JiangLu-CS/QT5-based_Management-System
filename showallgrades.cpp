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
showallgrades::showallgrades(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showallgrades)
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
    query.exec("select * from score");

    while(query.next())
               {
                   QStringList q;
                   q.clear();
                   QString sid = query.value(0).toString();
                   QString ssubject = query.value(1).toString();
                   QString sterm = query.value(2).toString();
                   q<<sid<<ssubject<<sterm;
                   list_all_student.append(q);




              }


}


showallgrades::~showallgrades()
{
    delete ui;
}

void showallgrades::on_ordergrade_clicked()
{
    QString ssubject=ui->searchsubject->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    if( ui->showname->isChecked()){

        model->setQuery("select score.stuid,cname,grade,student.sname from score,"
                        "student,course where score.stuid=student.stuid and course.cid=score.cid and cname = '"+ssubject+"' order by grade desc" );
        model->setHeaderData(0, Qt::Horizontal, tr("id"));
        model->setHeaderData(1, Qt::Horizontal, tr("科目"));
        model->setHeaderData(2, Qt::Horizontal, tr("成绩"));
        model->setHeaderData(3, Qt::Horizontal, tr("名字"));


        ui->tableView->setModel(model);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑

    }
    else{
    model->setQuery("select stuid,cname,grade from score,course where cname = '"+ssubject+"' and score.cid=course.cid order by grade desc" );
    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("科目"));
    model->setHeaderData(2, Qt::Horizontal, tr("成绩"));


    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑
    }
}

void showallgrades::on_fail_clicked()
{
    QString ssubject=ui->searchsubject->text();
    if( ui->showname->isChecked()){
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("select score.cid,cname,grade,student.sname from score,"
                        "student,course where score.stuid=student.stuid and course.cid=score.cid and cname = '"+ssubject+"' and grade<60" );
        model->setHeaderData(0, Qt::Horizontal, tr("id"));
        model->setHeaderData(1, Qt::Horizontal, tr("科目"));
        model->setHeaderData(2, Qt::Horizontal, tr("成绩"));
        model->setHeaderData(3, Qt::Horizontal, tr("名字"));


        ui->tableView->setModel(model);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑

    }
    else{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select stuid,cname,grade from score,course where score.cid=course.cid and cname = '"+ssubject+"' and grade<60" );
    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("科目"));
    model->setHeaderData(2, Qt::Horizontal, tr("成绩"));


    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑
    }
}

void showallgrades::on_average_clicked()
{
    QString ssubject=ui->searchsubject->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select cname,avg(grade) from score,course where course.cid=score.cid group by cname having cname = '"+ssubject+"'" );
    model->setHeaderData(0, Qt::Horizontal, tr("科目"));
    model->setHeaderData(1, Qt::Horizontal, tr("成绩"));


    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑
}

void showallgrades::on_pushButton_clicked()
{
    teacherselectgrade *t = new teacherselectgrade;
    this->hide();
    t->show();

}
