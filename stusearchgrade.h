#ifndef STUSEARCHGRADE_H
#define STUSEARCHGRADE_H

#include <QDialog>

namespace Ui {
class stusearchgrade;
}

class stusearchgrade : public QDialog
{
    Q_OBJECT

public:
    explicit stusearchgrade(QWidget *parent = nullptr);
    ~stusearchgrade();

private slots:
    void on_back_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::stusearchgrade *ui;
};

#endif // STUSEARCHGRADE_H
