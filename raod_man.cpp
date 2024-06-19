#include "raod_man.h"
#include "ui_raod_man.h"

raod_man::raod_man(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::raod_man)
{
    ui->setupUi(this);
}

raod_man::~raod_man()
{
    delete ui;
}

void raod_man::on_pushButton_4_clicked()
{
    this->close();
    manager *m = new manager;
    m->show();
}


void raod_man::on_pushButton_clicked()
{
    this->close();
    add_road *a = new add_road;
    a->show();
}


void raod_man::on_pushButton_2_clicked()
{
    this->close();
    delete_road *d = new delete_road;
    d->show();
}


void raod_man::on_pushButton_3_clicked()
{
    this->close();
    change_road *c = new change_road;
    c->show();
}


void raod_man::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
