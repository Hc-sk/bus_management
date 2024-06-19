#include "peizhi.h"
#include "ui_peizhi.h"

peizhi::peizhi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::peizhi)
{
    ui->setupUi(this);
}

peizhi::~peizhi()
{
    delete ui;
}
