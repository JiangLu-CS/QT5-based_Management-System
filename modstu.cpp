#include "modstu.h"
#include "ui_modstu.h"
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
#include"studentmanage.h"
modstu::modstu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modstu)
{
    ui->setupUi(this);
}

modstu::~modstu()
{
    delete ui;
}

void modstu::on_pushButton_clicked()
{
    if( ui->find->isChecked()){
        QString sstuno=ui->no->text();
        qDebug()<<"学生学号："<<sstuno;
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
        query.exec("select stuid,sname,ssex,age,smajor,dormnum from student where stuid="+sstuno+"" );



         if(query.next())
            {
             ui->no->setText(query.value(0).toString());
             ui->name->setText(query.value(1).toString());
             ui->sex->setText(query.value(2).toString());
             ui->age->setText(query.value(3).toString());
             ui->major->setText(query.value(4).toString());
             ui->dorm->setText(query.value(5).toString());
         }

    }
     if( ui->add->isChecked()){
    QString name = ui->name->text();
    QString password = "123456";
    QString sex = ui->sex->text();
    QString dorm = ui->dorm->text();
    QString age = ui->age->text();
    QString major = ui->major->text();
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
    query.exec("insert into student VALUES ('"+name+"','"+sex+"',"+age+",'"+major+"' ,'"+password+"','"+dorm+"');" );
    query.exec("select stuid from student where sname ='"+name+"' " );
    while(query.next()){
        QString sno = query.value(0).toString();
        QMessageBox::information(this, "您好", "新增学生成功,学生学号为："+sno+"");
    }

}
     if( ui->del->isChecked()){
    QString no = ui->no->text();

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
    query.exec("delete from student where stuid="+no+" ;" );
    QMessageBox::information(this, "您好", "删除学生学生成功");
}
     if( ui->mod->isChecked()){
    QString no = ui->no->text();
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
    if(!ui->name->text().isEmpty()){
        query.exec("update student set sname='"+ui->name->text()+"' where stuid="+no+"" );
    }
    if(!ui->age->text().isEmpty()){
        query.exec("update student set sage="+ui->age->text()+" where stuid="+no+"" );
    }
    if(!ui->sex->text().isEmpty()){
        query.exec("update student set ssex='"+ui->sex->text()+"' where stuid="+no+"" );
    }
    if(!ui->major->text().isEmpty()){
        query.exec("update student set smajor="+ui->major->text()+" where stuid="+no+"" );
    }
    if(!ui->dorm->text().isEmpty()){
        query.exec("update student set dormnum="+ui->dorm->text()+" where stuid="+no+"" );
    }
    QMessageBox::information(this, "您好", "修改学生学生成功");
}
     }


void modstu::on_pushButton_2_clicked()
{
    studentmanage *t = new studentmanage;
    this->hide();
    t->show();
}
