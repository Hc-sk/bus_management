#include "change_road.h"
#include "ui_change_road.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

change_road::change_road(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::change_road)
{
    ui->setupUi(this);
    groupbutton = new QButtonGroup(this);
    groupbutton->addButton(ui->nameButton,1);
    groupbutton->addButton(ui->numButton,2);
    groupbutton->addButton(ui->startButton,3);
    groupbutton->addButton(ui->endButton,4);

}

change_road::~change_road()
{
    delete ui;
}

void change_road::on_pushButton_clicked()
{
    QString road_id = ui->idEdit->text();
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
        queryString = "UPDATE Roads SET RoadName = :change  WHERE RoadID = :road_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":road_id", road_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    case 2:
        queryString = "UPDATE Roads SET RoadNumber = :change  WHERE RoadID = :road_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":road_id", road_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    case 3:
        queryString = "UPDATE Roads SET StartStationID = :change  WHERE RoadID = :road_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":road_id", road_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    case 4:
        queryString = "UPDATE Roads SET EndStationID = :change  WHERE RoadID = :road_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":road_id", road_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    }
}


void change_road::on_pushButton_2_clicked()
{
    this->close();
    raod_man *r = new raod_man;
    r ->show();
}
void change_road::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
