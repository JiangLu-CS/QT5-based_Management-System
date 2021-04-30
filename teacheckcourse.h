#ifndef TEACHECKCOURSE_H
#define TEACHECKCOURSE_H

#include <QDialog>

namespace Ui {
class teacheckcourse;
}

class teacheckcourse : public QDialog
{
    Q_OBJECT

public:
    explicit teacheckcourse(QWidget *parent = nullptr);
    ~teacheckcourse();

private slots:
    void on_back_clicked();

    void on_pushButton_clicked();

private:
    Ui::teacheckcourse *ui;
};

#endif // TEACHECKCOURSE_H
