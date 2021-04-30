#ifndef STUEVALUATE_H
#define STUEVALUATE_H

#include <QDialog>
namespace Ui {
class stuevaluate;
}

class stuevaluate : public QDialog
{
    Q_OBJECT

public:
    explicit stuevaluate(QWidget *parent = nullptr);
    ~stuevaluate();

private slots:
    void on_back_clicked();

    void on_submit_clicked();

private:
    Ui::stuevaluate *ui;
};

#endif // STUEVALUATE_H
