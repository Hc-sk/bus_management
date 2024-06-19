#ifndef USER_H
#define USER_H

#include <QWidget>
#include <bus_road_in.h>
#include <road_select.h>
#include <road_inf.h>
#include <busstops.h>
#include <widget.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class user;
}

class user : public QWidget
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = nullptr);
    ~user();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::user *ui;
};

#endif // USER_H
