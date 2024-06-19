#ifndef CHANGESTOP_H
#define CHANGESTOP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QButtonGroup>
#include <stop_man.h>
#include <QStyleOption>
#include <QPainter>


namespace Ui {
class changestop;
}

class changestop : public QWidget
{
    Q_OBJECT

public:
    explicit changestop(QWidget *parent = nullptr);
    ~changestop();
     void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::changestop *ui;
    QButtonGroup *groupbutton;
};

#endif // CHANGESTOP_H
