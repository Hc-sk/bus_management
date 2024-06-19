#include "deleteroute.h"
#include "ui_deleteroute.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

deleteroute::deleteroute(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deleteroute)
{
    ui->setupUi(this);
}

deleteroute::~deleteroute()
{
    delete ui;
}

void deleteroute::on_pushButton_2_clicked()
{
    this->close();
    busroad_man * b = new busroad_man;
    b->show();
}


void deleteroute::on_pushButton_clicked()
{
    QString route_id = ui->lineEdit->text();
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
    QString selectString = "SELECT RouteID FROM BusRoutes WHERE RouteID = :route_id;";
    query.prepare(selectString);
    query.bindValue(":route_id", route_id);
    if (!query.exec()) {
        qDebug() << "查询失败:";
        db.rollback();
        QMessageBox::warning(this,tr("错误"),tr("无法执行查询操作"));
    }
    if (!query.next()) {
        QMessageBox::warning(this,tr("错误"),tr("无该公交站点记录"));
    }
    QString deleteString = "DELETE FROM BusRoutes WHERE RouteID = :route_id;";
    query.prepare(deleteString);
    query.bindValue(":route_id", route_id);
    if (!query.exec()) {
        qDebug() << "删除失败:";
        db.rollback();
        QMessageBox::warning(this,tr("错误"),tr("无法执行删除操作"));
    } else {
        db.commit();
        QMessageBox::information(this,tr("消息"),tr("删除成功"));
    }
}

void deleteroute::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
