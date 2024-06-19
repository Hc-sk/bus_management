#ifndef STOP_MAN_H
#define STOP_MAN_H

#include <QWidget>
#include <addstop.h>
#include <deletestop.h>
#include <changestop.h>
#include <manager.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class stop_man;
}

class stop_man : public QWidget
{
    Q_OBJECT

public:
    explicit stop_man(QWidget *parent = nullptr);
    ~stop_man();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::stop_man *ui;
};

#endif // STOP_MAN_H
