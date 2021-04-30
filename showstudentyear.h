#ifndef SHOWSTUDENTYEAR_H
#define SHOWSTUDENTYEAR_H

#include <QWidget>

namespace Ui {
class showstudentyear;
}

class showstudentyear : public QWidget
{
    Q_OBJECT

public:
    explicit showstudentyear(QWidget *parent = nullptr);
    ~showstudentyear();

private slots:
    void on_pushButton_clicked();

private:
    Ui::showstudentyear *ui;
};

#endif // SHOWSTUDENTYEAR_H
