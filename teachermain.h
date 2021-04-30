#ifndef TEACHERMAIN_H
#define TEACHERMAIN_H

#include <QWidget>

namespace Ui {
class TeacherMain;
}

class TeacherMain : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherMain(QWidget *parent = nullptr);
    ~TeacherMain();

private slots:




    void on_grademanage_clicked();

    void on_coursemanage_clicked();

    void on_back_clicked();
    void on_informationmanage_clicked();


    void on_bookmanage_clicked();

    void on_dormmanage_clicked();

    void on_teachermanage_clicked();

    void on_majormanage_clicked();

private:
    Ui::TeacherMain *ui;
};

#endif // TEACHERMAIN_H
