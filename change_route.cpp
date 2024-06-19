#include "change_route.h"
#include "ui_change_route.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

change_route::change_route(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::change_route)
{
    ui->setupUi(this);
    groupbutton = new QButtonGroup(this);
    groupbutton->addButton(ui->numButton,1);
    groupbutton->addButton(ui->startButton,2);
    groupbutton->addButton(ui->endButton,3);
    groupbutton->addButton(ui->overButton,4);
}

change_route::~change_route()
{
    delete ui;
}

void change_route::on_pushButton_clicked()
{
    QString route_id = ui->lineEdit->text();
    QString change = ui->changeEdit->text();
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QODBC");
        QString dsn = QString::fromLocal8Bit("bus");
        db.setHostName("localhost");
        db.setDatabaseName(dsn);
        db.setUserName("sa");
        db.setPassword("gyhshaonian123");

        if (!db.open()) {
            qDebug() << "连接数据库失败";
            qDebug() << db.lastError().text();
        }
    }
    QSqlQuery query(db);
    QString queryString;
    switch(groupbutton->checkedId()){
    case 1:
        queryString = "UPDATE BusRoutes SET RouteNumber = :change  WHERE RouteID = :route_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":route_id", route_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    case 2:
        queryString = "UPDATE BusRoutes SET StartStationID = :change  WHERE RouteID = :route_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":route_id", route_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    case 3:
        queryString = "UPDATE BusRoutes SET EndStationID = :change  WHERE RouteID = :route_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":route_id", route_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    case 4:
        queryString = "UPDATE BusRoutes SET StopsOrder = :change  WHERE RouteID = :route_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":route_id", route_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    }
}


void change_route::on_pushButton_2_clicked()
{
    this->close();
    busroad_man *b = new busroad_man;
    b->show();
}
void change_route::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
