#ifndef STUSELECTCOUSE_H
#define STUSELECTCOUSE_H

#include <QDialog>

namespace Ui {
class stuselectcouse;
}

class stuselectcouse : public QDialog
{
    Q_OBJECT

public:
    explicit stuselectcouse(QWidget *parent = nullptr);
    ~stuselectcouse();

private slots:
    void on_back_clicked();

    void on_query_clicked();

    void on_insert_clicked();

    void on_delete_2_clicked();

private:
    Ui::stuselectcouse *ui;
};

#endif // STUSELECTCOUSE_H
