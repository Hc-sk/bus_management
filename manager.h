#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include <widget.h>
#include <stop_man.h>
#include <raod_man.h>
#include <busroad_man.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class manager;
}

class manager : public QWidget
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = nullptr);
    ~manager();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::manager *ui;
};

#endif // MANAGER_H
