#ifndef SHOWTEACHER_H
#define SHOWTEACHER_H

#include <QWidget>

namespace Ui {
class showteacher;
}

class showteacher : public QWidget
{
    Q_OBJECT

public:
    explicit showteacher(QWidget *parent = nullptr);
    ~showteacher();

private slots:
    void on_pushButton_clicked();

private:
    Ui::showteacher *ui;
};

#endif // SHOWTEACHER_H
