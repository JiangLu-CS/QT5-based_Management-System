#include "bookmanage.h"
#include "ui_bookmanage.h"

bookmanage::bookmanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookmanage)
{
    ui->setupUi(this);
}

bookmanage::~bookmanage()
{
    delete ui;
}
