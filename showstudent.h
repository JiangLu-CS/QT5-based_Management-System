#ifndef SHOWSTUDENT_H
#define SHOWSTUDENT_H

#include <QWidget>

namespace Ui {
class showstudent;
}

class showstudent : public QWidget
{
    Q_OBJECT

public:
    explicit showstudent(QWidget *parent = nullptr);
    ~showstudent();

private slots:
    void on_pushButton_clicked();

private:
    Ui::showstudent *ui;
};

#endif // SHOWSTUDENT_H
