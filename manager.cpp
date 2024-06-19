#include "manager.h"
#include "ui_manager.h"

manager::manager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::manager)
{
    ui->setupUi(this);
}

manager::~manager()
{
    delete ui;
}

void manager::on_pushButton_4_clicked()
{
    this->close();
    Widget *w =new Widget;
    w->show();
}


void manager::on_pushButton_clicked()
{
    this->close();
    stop_man *s =new stop_man;
    s->show();
}


void manager::on_pushButton_2_clicked()
{
    this->close();
    raod_man *r = new raod_man;
    r->show();
}


void manager::on_pushButton_3_clicked()
{
    this->close();
    busroad_man *b =new busroad_man;
    b->show();
}

void manager::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
