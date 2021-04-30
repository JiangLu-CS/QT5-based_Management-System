#ifndef DORMMANAGE_H
#define DORMMANAGE_H

#include <QWidget>

namespace Ui {
class dormmanage;
}

class dormmanage : public QWidget
{
    Q_OBJECT

public:
    explicit dormmanage(QWidget *parent = nullptr);
    ~dormmanage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::dormmanage *ui;
};

#endif // DORMMANAGE_H
