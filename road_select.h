#ifndef ROAD_SELECT_H
#define ROAD_SELECT_H

#include <QWidget>
#include <QSqlDatabase>
#include <user.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class road_select;
}

class road_select : public QWidget
{
    Q_OBJECT

public:
    explicit road_select(QWidget *parent = nullptr);
    ~road_select();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::road_select *ui;
};

#endif // ROAD_SELECT_H
