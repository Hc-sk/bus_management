#ifndef ADDSTOP_H
#define ADDSTOP_H

#include <QWidget>
#include <QSqlDatabase>
#include <stop_man.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class addstop;
}

class addstop : public QWidget
{
    Q_OBJECT

public:
    explicit addstop(QWidget *parent = nullptr);
    ~addstop();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addstop *ui;
};

#endif // ADDSTOP_H
