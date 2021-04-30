#ifndef SHOWALLGRADES_H
#define SHOWALLGRADES_H

#include <QWidget>

namespace Ui {
class showallgrades;
}

class showallgrades : public QWidget
{
    Q_OBJECT

public:
    explicit showallgrades(QWidget *parent = nullptr);
    ~showallgrades();

private slots:
    void on_ordergrade_clicked();

    void on_fail_clicked();

    void on_average_clicked();

    void on_pushButton_clicked();

private:
    Ui::showallgrades *ui;
};

#endif // SHOWALLGRADES_H
