#ifndef CHANGE_ROUTE_H
#define CHANGE_ROUTE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QButtonGroup>
#include <busroad_man.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class change_route;
}

class change_route : public QWidget
{
    Q_OBJECT

public:
    explicit change_route(QWidget *parent = nullptr);
    ~change_route();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::change_route *ui;
    QButtonGroup *groupbutton;
};

#endif // CHANGE_ROUTE_H
