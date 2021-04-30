#ifndef SELECTCOURSE_H
#define SELECTCOURSE_H

#include <QWidget>

namespace Ui {
class selectcourse;
}

class selectcourse : public QWidget
{
    Q_OBJECT

public:
    explicit selectcourse(QWidget *parent = nullptr);
    ~selectcourse();

private slots:
    void on_pushButton_clicked();

    void on_search_clicked();

private:
    Ui::selectcourse *ui;
};

#endif // SELECTCOURSE_H
