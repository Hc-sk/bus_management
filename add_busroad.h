#ifndef ADD_BUSROAD_H
#define ADD_BUSROAD_H

#include <QWidget>
#include <busroad_man.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class add_busroad;
}

class add_busroad : public QWidget
{
    Q_OBJECT

public:
    explicit add_busroad(QWidget *parent = nullptr);
    ~add_busroad();
     void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::add_busroad *ui;
};

#endif // ADD_BUSROAD_H
