#ifndef BOOK_H
#define BOOK_H

#include <QWidget>

namespace Ui {
class book;
}

class book : public QWidget
{
    Q_OBJECT

public:
    explicit book(QWidget *parent = nullptr);
    ~book();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::book *ui;
};

#endif // BOOK_H
