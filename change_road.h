#ifndef CHANGE_ROAD_H
#define CHANGE_ROAD_H

#include <QWidget>
#include <QSqlDatabase>
#include <QButtonGroup>
#include <raod_man.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class change_road;
}

class change_road : public QWidget
{
    Q_OBJECT

public:
    explicit change_road(QWidget *parent = nullptr);
    ~change_road();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::change_road *ui;
    QButtonGroup *groupbutton;
};

#endif // CHANGE_ROAD_H
