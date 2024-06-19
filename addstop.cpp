#include "addstop.h"
#include "ui_addstop.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

addstop::addstop(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addstop)
{
    ui->setupUi(this);
}

addstop::~addstop()
{
    delete ui;
}

void addstop::on_pushButton_clicked()
{
    QString stop_id = ui->idEdit->text();
    QString stop_name = ui->nameEdit->text();
    QString stop_num = ui->numEdit->text();
    QString stop_location = ui->locationEdit->text();

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
    QString queryString = " SET IDENTITY_INSERT BusStops ON;INSERT INTO BusStops (StationID, StationName, StationNumber, Location) VALUES ('" + stop_id + "', '" + stop_name + "','"+ stop_num+"', '" + stop_location + "'); SET IDENTITY_INSERT BusStops OFF;";
    query.prepare(queryString);
    if (!query.exec()) {
        qDebug() << "插入失败:";
        QMessageBox::warning(this,tr("错误"),tr("插入重复"));
    }else{
        QMessageBox::information(this,tr("消息"),tr("插入成功"));
    }
}



void addstop::on_pushButton_2_clicked()
{
    this->close();
    stop_man *s = new stop_man;
    s->show();
}
void addstop::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
