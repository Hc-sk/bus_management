#include "deletestop.h"
#include "ui_deletestop.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

deletestop::deletestop(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deletestop)
{
    ui->setupUi(this);
}

deletestop::~deletestop()
{
    delete ui;
}

void deletestop::on_pushButton_clicked()
{
    QString stop_id = ui->lineEdit->text();
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
    QString selectString = "SELECT StationID FROM BusStops WHERE StationID = :stationID;";
    query.prepare(selectString);
    query.bindValue(":stationID", stop_id);
    if (!query.exec()) {
        qDebug() << "查询失败:";
        db.rollback();
        QMessageBox::warning(this,tr("错误"),tr("无法执行查询操作"));
    }
    if (!query.next()) {
        QMessageBox::warning(this,tr("错误"),tr("无该公交站点记录"));
    }
    QString deleteString = "DELETE FROM BusStops WHERE StationID = :stationID;";
    query.prepare(deleteString);
    query.bindValue(":stationID", stop_id);
    if (!query.exec()) {
        qDebug() << "删除失败:";
        db.rollback();
        QMessageBox::warning(this,tr("错误"),tr("无法执行删除操作"));
    } else {
        db.commit();
        QMessageBox::information(this,tr("消息"),tr("删除成功"));
    }
}


void deletestop::on_pushButton_2_clicked()
{
    this->close();
    stop_man *s = new stop_man;
    s->show();
}
void deletestop::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
