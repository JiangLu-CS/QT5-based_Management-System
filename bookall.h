#ifndef BOOKALL_H
#define BOOKALL_H

#include <QWidget>

namespace Ui {
class bookall;
}

class bookall : public QWidget
{
    Q_OBJECT

public:
    explicit bookall(QWidget *parent = nullptr);
    ~bookall();

private slots:
    void on_pushButton_clicked();

private:
    Ui::bookall *ui;
};

#endif // BOOKALL_H
