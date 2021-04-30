#include "book.h"
#include "ui_book.h"
#include"bookall.h"
#include"bookmanage.h"
#include"bookmod.h"
#include"teachermain.h"
book::book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::book)
{
    ui->setupUi(this);
}

book::~book()
{
    delete ui;
}

void book::on_pushButton_clicked()
{
    bookall *t = new bookall;
    this->hide();
    t->show();
}

void book::on_pushButton_2_clicked()
{
    bookmod *t = new bookmod;
    this->hide();
    t->show();
}

void book::on_pushButton_3_clicked()
{
    TeacherMain *t = new TeacherMain;
    this->hide();
    t->show();
}
