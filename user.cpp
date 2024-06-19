#include "user.h"
#include "ui_user.h"

user::user(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::user)
{
    ui->setupUi(this);
}

user::~user()
{
    delete ui;
}

void user::on_pushButton_clicked()
{
    this->close();
    bus_road_in *b = new bus_road_in;
    b->show();
}


void user::on_pushButton_2_clicked()
{
    this->close();
    road_select *s = new road_select;
    s->show();
}


void user::on_pushButton_3_clicked()
{
    this->close();
    road_inf *i = new road_inf;
    i->show();
}


void user::on_pushButton_4_clicked()
{
    this->close();
    busstops *b =new busstops;
    b->show();
}


void user::on_pushButton_5_clicked()
{
    this->close();
    Widget *w = new Widget;
    w->show();
}


void user::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

