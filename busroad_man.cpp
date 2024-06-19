#include "busroad_man.h"
#include "ui_busroad_man.h"

busroad_man::busroad_man(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::busroad_man)
{
    ui->setupUi(this);
}

busroad_man::~busroad_man()
{
    delete ui;
}

void busroad_man::on_pushButton_4_clicked()
{
    this->close();
    manager *m = new manager;
    m->show();
}


void busroad_man::on_pushButton_clicked()
{
    this->close();
    add_busroad *a = new add_busroad;
    a->show();
}


void busroad_man::on_pushButton_2_clicked()
{
    this->close();
    deleteroute *d = new deleteroute;
    d->show();
}


void busroad_man::on_pushButton_3_clicked()
{
    this->close();
    change_route *c = new change_route;
    c->show();
}

void busroad_man::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
