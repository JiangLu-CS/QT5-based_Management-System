#ifndef DORMALL_H
#define DORMALL_H

#include <QWidget>

namespace Ui {
class dormall;
}

class dormall : public QWidget
{
    Q_OBJECT

public:
    explicit dormall(QWidget *parent = nullptr);
    ~dormall();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dormall *ui;
};

#endif // DORMALL_H
