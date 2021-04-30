#ifndef TEASUBMITGRADE_H
#define TEASUBMITGRADE_H

#include <QDialog>

namespace Ui {
class teasubmitgrade;
}

class teasubmitgrade : public QDialog
{
    Q_OBJECT

public:
    explicit teasubmitgrade(QWidget *parent = nullptr);
    ~teasubmitgrade();

private slots:
    void on_back_clicked();

    void on_submit_clicked();

private:
    Ui::teasubmitgrade *ui;
};

#endif // TEASUBMITGRADE_H
