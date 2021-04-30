#ifndef BOOKMOD_H
#define BOOKMOD_H

#include <QWidget>

namespace Ui {
class bookmod;
}

class bookmod : public QWidget
{
    Q_OBJECT

public:
    explicit bookmod(QWidget *parent = nullptr);
    ~bookmod();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::bookmod *ui;
};

#endif // BOOKMOD_H
