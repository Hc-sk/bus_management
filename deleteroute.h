#ifndef DELETEROUTE_H
#define DELETEROUTE_H

#include <QWidget>
#include <busroad_man.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class deleteroute;
}

class deleteroute : public QWidget
{
    Q_OBJECT

public:
    explicit deleteroute(QWidget *parent = nullptr);
    ~deleteroute();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::deleteroute *ui;
};

#endif // DELETEROUTE_H
