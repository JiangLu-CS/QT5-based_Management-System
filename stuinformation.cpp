#include "stuinformation.h"
#include "ui_stuinformation.h"
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
stuinformation::stuinformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stuinformation)
{
    ui->setupUi(this);
}

stuinformation::~stuinformation()
{
    delete ui;
}

void stuinformation::on_pushButton_clicked()
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
     qDebug() << "Failed to connect to root mysql admin";
  else qDebug() << "open";}

  QSqlQuery query(db);
  db.exec("SET NAMES 'GBK'");
  QSqlQueryModel *model = new QSqlQueryModel(ui->basic);
  model->setQuery("select stuid,sname,ssex,age,smajor,mname,dormnum from student,major where student.smajor=major.mid and stuid="+usernamelogin);
  model->setHeaderData(0, Qt::Horizontal, tr("学号"));
  model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
  model->setHeaderData(2, Qt::Horizontal, tr("性别"));
  model->setHeaderData(3, Qt::Horizontal, tr("年龄"));
  model->setHeaderData(4, Qt::Horizontal, tr("专业号"));
  model->setHeaderData(5, Qt::Horizontal, tr("专业名"));
  model->setHeaderData(6, Qt::Horizontal, tr("宿舍号"));
  ui->basic->setModel(model);
  ui->basic->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置成不可编辑
  db.exec("SET NAMES 'GBK'");
  QSqlQueryModel *modela = new QSqlQueryModel(ui->dorm);
  modela->setQuery("select stuid,sname,did,remark,manager from student,dorm where student.dormnum=dorm.did and stuid="+usernamelogin);
  modela->setHeaderData(0, Qt::Horizontal, tr("学号"));
  modela->setHeaderData(1, Qt::Horizontal, tr("姓名"));
  modela->setHeaderData(2, Qt::Horizontal, tr("宿舍号"));
  modela->setHeaderData(3, Qt::Horizontal, tr("宿舍备注"));
  modela->setHeaderData(4, Qt::Horizontal, tr("宿管"));
  ui->dorm->setModel(modela);
  ui->dorm->setEditTriggers(QAbstractItemView::NoEditTriggers);
  db.exec("SET NAMES 'GBK'");
  QSqlQueryModel *modelb = new QSqlQueryModel(ui->course);
  modelb->setQuery("select score.stuid,sname,cname,classhour,credit,bname,price,tname from student,score,course,book,teacher where student.stuid=score.stuid and score.cid=course.cid and course.book=book.bid and course.teacher=teacher.tid and score.stuid="+usernamelogin);
  modelb->setHeaderData(0, Qt::Horizontal, tr("学号"));
  modelb->setHeaderData(1, Qt::Horizontal, tr("姓名"));
  modelb->setHeaderData(2, Qt::Horizontal, tr("课程名"));
  modelb->setHeaderData(3, Qt::Horizontal, tr("学时"));
  modelb->setHeaderData(4, Qt::Horizontal, tr("学分"));
  modelb->setHeaderData(5, Qt::Horizontal, tr("书名"));
  modelb->setHeaderData(6, Qt::Horizontal, tr("书价"));
  modelb->setHeaderData(7, Qt::Horizontal, tr("授课老师"));
  ui->course->setModel(modelb);
  ui->course->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void stuinformation::on_back_clicked()
{
    this->hide();
    studentmain *m = new studentmain;
    m->show();
}
