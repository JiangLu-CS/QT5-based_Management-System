#ifndef BOOKMANAGE_H
#define BOOKMANAGE_H

#include <QWidget>

namespace Ui {
class bookmanage;
}

class bookmanage : public QWidget
{
    Q_OBJECT

public:
    explicit bookmanage(QWidget *parent = nullptr);
    ~bookmanage();

private:
    Ui::bookmanage *ui;
};

#endif // BOOKMANAGE_H
