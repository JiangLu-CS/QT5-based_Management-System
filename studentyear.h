#ifndef STUDENTYEAR_H
#define STUDENTYEAR_H

#include <QWidget>

namespace Ui {
class studentyear;
}

class studentyear : public QWidget
{
    Q_OBJECT

public:
    explicit studentyear(QWidget *parent = nullptr);
    ~studentyear();

private slots:
    void on_pushButton_3_clicked();

    void on_show_clicked();

    void on_delete_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::studentyear *ui;
};

#endif // STUDENTYEAR_H
