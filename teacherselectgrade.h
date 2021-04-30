#ifndef TEACHERSELECTGRADE_H
#define TEACHERSELECTGRADE_H

#include <QWidget>

namespace Ui {
class teacherselectgrade;
}

class teacherselectgrade : public QWidget
{
    Q_OBJECT

public:
    explicit teacherselectgrade(QWidget *parent = nullptr);
    ~teacherselectgrade();

private slots:
    void on_select_clicked();

    void on_update_clicked();

    void on_insert_clicked();

    void on_deletegrade_clicked();

    void on_selectall_clicked();

    void on_back1_clicked();

private:
    Ui::teacherselectgrade *ui;
};

#endif // TEACHERSELECTGRADE_H
