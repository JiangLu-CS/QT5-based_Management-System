#ifndef ALLTEACHER_H
#define ALLTEACHER_H

#include <QWidget>

namespace Ui {
class allteacher;
}

class allteacher : public QWidget
{
    Q_OBJECT

public:
    explicit allteacher(QWidget *parent = nullptr);
    ~allteacher();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::allteacher *ui;
};

#endif // ALLTEACHER_H
