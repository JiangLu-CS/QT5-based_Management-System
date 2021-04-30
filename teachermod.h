#ifndef TEACHERMOD_H
#define TEACHERMOD_H

#include <QWidget>

namespace Ui {
class teachermod;
}

class teachermod : public QWidget
{
    Q_OBJECT

public:
    explicit teachermod(QWidget *parent = nullptr);
    ~teachermod();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::teachermod *ui;
};

#endif // TEACHERMOD_H
