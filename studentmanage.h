#ifndef STUDENTMANAGE_H
#define STUDENTMANAGE_H

#include <QWidget>

namespace Ui {
class studentmanage;
}

class studentmanage : public QWidget
{
    Q_OBJECT

public:
    explicit studentmanage(QWidget *parent = nullptr);
    ~studentmanage();

private slots:
    void on_pushButton_clicked();

    void on_allstu_clicked();

    void on_modstu_clicked();

private:
    Ui::studentmanage *ui;
};

#endif // STUDENTMANAGE_H
