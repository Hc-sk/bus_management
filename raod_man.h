#ifndef RAOD_MAN_H
#define RAOD_MAN_H

#include <QWidget>
#include <manager.h>
#include <add_road.h>
#include <delete_road.h>
#include <change_road.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class raod_man;
}

class raod_man : public QWidget
{
    Q_OBJECT

public:
    explicit raod_man(QWidget *parent = nullptr);
    ~raod_man();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::raod_man *ui;
};

#endif // RAOD_MAN_H
