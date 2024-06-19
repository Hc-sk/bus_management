#ifndef BUSSTOPS_H
#define BUSSTOPS_H

#include <QWidget>
#include <user.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class busstops;
}

class busstops : public QWidget
{
    Q_OBJECT

public:
    explicit busstops(QWidget *parent = nullptr);
    ~busstops();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::busstops *ui;
};

#endif // BUSSTOPS_H
