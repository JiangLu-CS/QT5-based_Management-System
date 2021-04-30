#include "teasubmitgrade.h"
#include "ui_teasubmitgrade.h"
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
teasubmitgrade::teasubmitgrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teasubmitgrade)
{
    ui->setupUi(this);
}

teasubmitgrade::~teasubmitgrade()
{
    delete ui;
}

void teasubmitgrade::on_back_clicked()
{teamain* f=new teamain;
    this->hide();
    f->show();
}

void teasubmitgrade::on_submit_clicked()
{QString stuid=ui->stuid->text();
QString course=ui->courseid->text();
QString grade=ui->grade->text();
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
QSqlQuery queryl;
query.exec("update score set grade="+grade+" where stuid="+stuid+" and cid='"+course+"'" );
QMessageBox::information(this, "您好", "成绩已上传成功");

}
