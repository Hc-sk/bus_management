#include "stop_man.h"
#include "ui_stop_man.h"

stop_man::stop_man(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::stop_man)
{
    ui->setupUi(this);
}

stop_man::~stop_man()
{
    delete ui;
}

void stop_man::on_pushButton_clicked()
{
    this->close();
    addstop *a = new addstop;
    a->show();
}


void stop_man::on_pushButton_2_clicked()
{
    this->close();
    deletestop *d =new deletestop;
    d->show();
}


void stop_man::on_pushButton_3_clicked()
{
    this->close();
    changestop *c = new changestop;
    c->show();
}


void stop_man::on_pushButton_4_clicked()
{
    this->close();
    manager *m = new manager;
    m->show();
}
void stop_man::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
