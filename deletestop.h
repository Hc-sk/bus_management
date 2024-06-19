#ifndef DELETESTOP_H
#define DELETESTOP_H

#include <QWidget>
#include <QSqlDatabase>
#include <stop_man.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class deletestop;
}

class deletestop : public QWidget
{
    Q_OBJECT

public:
    explicit deletestop(QWidget *parent = nullptr);
    ~deletestop();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::deletestop *ui;
};

#endif // DELETESTOP_H
