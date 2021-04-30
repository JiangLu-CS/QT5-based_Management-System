#include "teacheckcourse.h"
#include "ui_teacheckcourse.h"
#include"teamain.h"
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
teacheckcourse::teacheckcourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacheckcourse)
{
    ui->setupUi(this);
}

teacheckcourse::~teacheckcourse()
{
    delete ui;
}

void teacheckcourse::on_back_clicked()
{teamain* f=new teamain;
    this->hide();
    f->show();
}

void teacheckcourse::on_pushButton_clicked()
{
    QString tid=ui->tid->text();
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
    model->setQuery("select cid,cname,book,classhour,credit from course where teacher="+tid);
    model->setHeaderData(0, Qt::Horizontal, tr("课程号"));
    model->setHeaderData(1, Qt::Horizontal, tr("课程名"));
    model->setHeaderData(2, Qt::Horizontal, tr("书名"));
    model->setHeaderData(3, Qt::Horizontal, tr("学时"));
    model->setHeaderData(4, Qt::Horizontal, tr("学分"));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑
    db.exec("SET NAMES 'GBK'");
}
