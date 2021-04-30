#ifndef DORMMOD_H
#define DORMMOD_H

#include <QWidget>

namespace Ui {
class dormmod;
}

class dormmod : public QWidget
{
    Q_OBJECT

public:
    explicit dormmod(QWidget *parent = nullptr);
    ~dormmod();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::dormmod *ui;
};

#endif // DORMMOD_H
