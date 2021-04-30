#include "teaevaluate.h"
#include "ui_teaevaluate.h"
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
teaevaluate::teaevaluate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teaevaluate)
{
    ui->setupUi(this);
}

teaevaluate::~teaevaluate()
{
    delete ui;
}

void teaevaluate::on_pushButton_2_clicked()
{ teamain* f=new teamain;
    this->hide();
    f->show();
}


void teaevaluate::on_pushButton_clicked()
{QString teaid=ui->teaid->text();
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
    model->setQuery("select content from evaluation where tid="+teaid);
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑
    db.exec("SET NAMES 'GBK'");
}
