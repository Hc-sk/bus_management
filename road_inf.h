#ifndef ROAD_INF_H
#define ROAD_INF_H

#include <QWidget>
#include <QSqlDatabase>
#include <user.h>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class road_inf;
}

class road_inf : public QWidget
{
    Q_OBJECT

public:
    explicit road_inf(QWidget *parent = nullptr);
    ~road_inf();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::road_inf *ui;
};

#endif // ROAD_INF_H
