#ifndef DELETE_ROAD_H
#define DELETE_ROAD_H

#include <QWidget>
#include <QSqlDatabase>
#include <raod_man.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class delete_road;
}

class delete_road : public QWidget
{
    Q_OBJECT

public:
    explicit delete_road(QWidget *parent = nullptr);
    ~delete_road();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::delete_road *ui;
};

#endif // DELETE_ROAD_H
