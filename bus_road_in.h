#ifndef BUS_ROAD_IN_H
#define BUS_ROAD_IN_H

#include <QWidget>
#include <QSqlDatabase>
#include <user.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class bus_road_in;
}

class bus_road_in : public QWidget
{
    Q_OBJECT

public:
    explicit bus_road_in(QWidget *parent = nullptr);
    ~bus_road_in();
     void paintEvent(QPaintEvent *event);
private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::bus_road_in *ui;
};

#endif // BUS_ROAD_IN_H
