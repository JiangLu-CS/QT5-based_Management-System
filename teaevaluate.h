#ifndef TEAEVALUATE_H
#define TEAEVALUATE_H

#include <QDialog>

namespace Ui {
class teaevaluate;
}

class teaevaluate : public QDialog
{
    Q_OBJECT

public:
    explicit teaevaluate(QWidget *parent = nullptr);
    ~teaevaluate();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::teaevaluate *ui;
};

#endif // TEAEVALUATE_H
