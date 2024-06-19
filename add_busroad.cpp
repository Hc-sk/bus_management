#include "add_busroad.h"
#include "ui_add_busroad.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

add_busroad::add_busroad(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_busroad)
{
    ui->setupUi(this);
}

add_busroad::~add_busroad()
{
    delete ui;
}

void add_busroad::on_pushButton_2_clicked()
{
    this->close();
    busroad_man *b = new busroad_man;
    b->show();
}


void add_busroad::on_pushButton_clicked()
{
    QString route_id = ui->idEdit->text();
    QString route_num = ui->numEdit->text();
    QString route_start = ui->startEdit->text();
    QString route_end = ui->endEdit->text();
    QString route_over = ui->overEdit->text();

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
    QString queryString = " SET IDENTITY_INSERT BusRoutes ON;INSERT INTO BusRoutes (RouteID, RouteNumber, StartStationID, EndStationID, StopsOrder) VALUES ('" + route_id + "', '" + route_num + "','"+ route_start+"', '" + route_end + "','"+ route_over +"'); SET IDENTITY_INSERT BusRoutes OFF;";
    query.prepare(queryString);
    if (!query.exec()) {
        qDebug() << "插入失败:";
        QMessageBox::warning(this,tr("错误"),tr("插入重复"));
    }else{
        QMessageBox::information(this,tr("消息"),tr("插入成功"));
    }
}
void add_busroad::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

