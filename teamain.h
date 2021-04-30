#ifndef TEAMAIN_H
#define TEAMAIN_H

#include <QDialog>

namespace Ui {
class teamain;
}

class teamain : public QDialog
{
    Q_OBJECT

public:
    explicit teamain(QWidget *parent = nullptr);
    ~teamain();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::teamain *ui;
};

#endif // TEAMAIN_H
