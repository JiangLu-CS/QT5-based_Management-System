#ifndef STUDENTMAIN_H
#define STUDENTMAIN_H
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
#include "selectcourse.h"
#include"showstudent.h"
#include <QDialog>

namespace Ui {
class studentmain;
}

class studentmain : public QDialog
{
    Q_OBJECT

public:
    explicit studentmain(QWidget *parent = nullptr);
    ~studentmain();
private slots:
    void on_evaluation_clicked();

    void on_selectcourse_clicked();



    void on_searchgrade_clicked();

    void on_back_clicked();

    void on_information_clicked();

private:
    Ui::studentmain *ui;
};

#endif // STUDENTMAIN_H
