#include "teamain.h"
#include "ui_teamain.h"
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
#include "teaevaluate.h"
#include"mainwindow.h"
#include "teacheckcourse.h"
#include"teasubmitgrade.h"
teamain::teamain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teamain)
{
    ui->setupUi(this);
}

teamain::~teamain()
{
    delete ui;
}



void teamain::on_pushButton_clicked()
{teaevaluate* f=new teaevaluate;
    QString name = usernamelogin;
    this->hide();
    f->show();
}

void teamain::on_pushButton_2_clicked()
{teasubmitgrade* f=new teasubmitgrade;
    this->hide();
    f->show();
}

void teamain::on_pushButton_3_clicked()
{teacheckcourse* f=new teacheckcourse;
    this->hide();
    f->show();
}

void teamain::on_pushButton_4_clicked()
{       this->hide();
        MainWindow *h=new MainWindow;
        h->show();
}
