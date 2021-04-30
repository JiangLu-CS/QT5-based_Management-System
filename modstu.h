#ifndef MODSTU_H
#define MODSTU_H

#include <QWidget>

namespace Ui {
class modstu;
}

class modstu : public QWidget
{
    Q_OBJECT

public:
    explicit modstu(QWidget *parent = nullptr);
    ~modstu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::modstu *ui;
};

#endif // MODSTU_H
