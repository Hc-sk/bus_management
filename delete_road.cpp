#include "delete_road.h"
#include "ui_delete_road.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

delete_road::delete_road(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::delete_road)
{
    ui->setupUi(this);
}

delete_road::~delete_road()
{
    delete ui;
}

void delete_road::on_pushButton_clicked()
{
    QString road_id = ui->lineEdit->text();
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
    QString selectString = "SELECT RoadID FROM Roads WHERE RoadID = :road_id;";
    query.prepare(selectString);
    query.bindValue(":road_id", road_id);
    if (!query.exec()) {
        qDebug() << "查询失败:";
        db.rollback();
        QMessageBox::warning(this,tr("错误"),tr("无法执行查询操作"));
    }
    if (!query.next()) {
        QMessageBox::warning(this,tr("错误"),tr("无该公交站点记录"));
    }
    QString deleteString = "DELETE FROM Roads WHERE RoadID = :road_id;";
    query.prepare(deleteString);
    query.bindValue(":road_id", road_id);
    if (!query.exec()) {
        qDebug() << "删除失败:";
        db.rollback();
        QMessageBox::warning(this,tr("错误"),tr("无法执行删除操作"));
    } else {
        db.commit();
        QMessageBox::information(this,tr("消息"),tr("删除成功"));
    }
}


void delete_road::on_pushButton_2_clicked()
{
    this->close();
    raod_man *r = new raod_man;
    r->show();
}
void delete_road::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
