#include "add_road.h"
#include "ui_add_road.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

add_road::add_road(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_road)
{
    ui->setupUi(this);
}

add_road::~add_road()
{
    delete ui;
}

void add_road::on_pushButton_2_clicked()
{
    this->close();
    raod_man *r = new raod_man;
    r->show();
}


void add_road::on_pushButton_clicked()
{
    QString road_id = ui->idEdit->text();
    QString road_name = ui->nameEdit->text();
    QString road_num = ui->numEdit->text();
    QString road_start = ui->startEdit->text();
    QString road_end = ui->endEdit->text();

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
    QString queryString = " SET IDENTITY_INSERT Roads ON;INSERT INTO Roads (RoadID, RoadName, RoadNumber, StartStationID, EndStationID) VALUES ('" + road_id + "', '" + road_name + "','"+ road_num+"', '" + road_start + "','"+ road_end +"'); SET IDENTITY_INSERT Roads OFF;";
    query.prepare(queryString);
    if (!query.exec()) {
        qDebug() << "插入失败:";
        QMessageBox::warning(this,tr("错误"),tr("插入重复"));
    }else{
        QMessageBox::information(this,tr("消息"),tr("插入成功"));
    }
}
void add_road::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
