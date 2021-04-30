#include "dormmanage.h"
#include "ui_dormmanage.h"
#include"dormall.h"
#include"dormmod.h"
#include"teachermain.h"
dormmanage::dormmanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dormmanage)
{
    ui->setupUi(this);
}

dormmanage::~dormmanage()
{
    delete ui;
}

void dormmanage::on_pushButton_clicked()
{
    dormall *t = new dormall;
    this->hide();
    t->show();
}

void dormmanage::on_pushButton_2_clicked()
{
    dormmod *t = new dormmod;
    this->hide();
    t->show();
}

void dormmanage::on_pushButton_3_clicked()
{
    TeacherMain *t = new TeacherMain;
    this->hide();
    t->show();
}
