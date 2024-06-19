#ifndef BUSROAD_MAN_H
#define BUSROAD_MAN_H

#include <QWidget>
#include <manager.h>
#include <add_busroad.h>
#include <deleteroute.h>
#include <change_route.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class busroad_man;
}

class busroad_man : public QWidget
{
    Q_OBJECT

public:
    explicit busroad_man(QWidget *parent = nullptr);
    ~busroad_man();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::busroad_man *ui;
};

#endif // BUSROAD_MAN_H
