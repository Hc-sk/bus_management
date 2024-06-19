#ifndef ADD_ROAD_H
#define ADD_ROAD_H

#include <QWidget>
#include <raod_man.h>
#include <QSqlDatabase>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class add_road;
}

class add_road : public QWidget
{
    Q_OBJECT

public:
    explicit add_road(QWidget *parent = nullptr);
    ~add_road();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::add_road *ui;
};

#endif // ADD_ROAD_H
