#include "connect_sql.h"
#include "ui_connect_sql.h"

connect_sql::connect_sql(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::connect_sql)
{
    ui->setupUi(this);
}

connect_sql::~connect_sql()
{
    delete ui;
}
