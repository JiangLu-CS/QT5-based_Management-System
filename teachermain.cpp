#include "teachermain.h"
#include "ui_teachermain.h"
#include "mainwindow.h"
#include"setting.h"
#include  <QtDebug>
#include <QWidget>
#include <QApplication>
#include"dormmanage.h"
#include"studentmanage.h"
#include"studentyear.h"
#include"book.h"
#include"allteacher.h"
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
#include "selectcourse.h"
#include"showstudent.h"
#include"studentmanage.h"
#include"dormmanage.h"
TeacherMain::TeacherMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherMain)
{
    ui->setupUi(this);
    QLabel* lab = ui->teacherlabel;
    lab->setText("欢迎"+usernamelogin+"管理员");


}

TeacherMain::~TeacherMain()
{
    delete ui;
}





void TeacherMain::on_grademanage_clicked()
{
    teacherselectgrade *h;
    this->hide();
    h=new teacherselectgrade  ;

    h->show();
}

void TeacherMain::on_coursemanage_clicked()
{
    selectcourse *h = new selectcourse;
    this->hide();
    h->show();
}

void TeacherMain::on_back_clicked()
{
    this->hide();
    MainWindow *h=new MainWindow;
    h->show();
}

void TeacherMain::on_informationmanage_clicked()
{
    this->hide();
    studentmanage *h=new studentmanage;
    h->show();
}

void TeacherMain::on_bookmanage_clicked()
{
    book *b = new book;
    this->hide();
    b->show();
}

void TeacherMain::on_dormmanage_clicked()
{
    dormmanage *h = new dormmanage;
    this->hide();
    h->show();
}

void TeacherMain::on_teachermanage_clicked()
{
    allteacher *t = new allteacher;
    this->hide();
    t->show();
}

void TeacherMain::on_majormanage_clicked()
{
    studentyear *s = new studentyear;
    this->hide();
    s->show();
}
