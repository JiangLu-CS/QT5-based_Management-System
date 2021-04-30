#include "allteacher.h"
#include "ui_allteacher.h"
#include"showteacher.h"
#include"teachermod.h"
#include"teachermain.h"
allteacher::allteacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::allteacher)
{
    ui->setupUi(this);
}

allteacher::~allteacher()
{
    delete ui;
}

void allteacher::on_pushButton_clicked()
{
    showteacher *t = new showteacher;
    this->hide();
    t->show();
}

void allteacher::on_pushButton_2_clicked()
{
    teachermod *t = new teachermod;
    this->hide();
    t->show();
}

void allteacher::on_pushButton_3_clicked()
{
    TeacherMain *t = new TeacherMain();
    this->hide();
    t->show();
}
