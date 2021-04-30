#ifndef STUINFORMATION_H
#define STUINFORMATION_H

#include <QDialog>

namespace Ui {
class stuinformation;
}

class stuinformation : public QDialog
{
    Q_OBJECT

public:
    explicit stuinformation(QWidget *parent = nullptr);
    ~stuinformation();

private slots:
    void on_pushButton_clicked();

    void on_back_clicked();

private:
    Ui::stuinformation *ui;
};

#endif // STUINFORMATION_H
