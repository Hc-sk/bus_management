#include "bus_road_in.h"
#include "ui_bus_road_in.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

bus_road_in::bus_road_in(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::bus_road_in)
{
    ui->setupUi(this);
}

bus_road_in::~bus_road_in()
{
    delete ui;
}


void bus_road_in::on_lineEdit_returnPressed()
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
    QString queryString = "SELECT * FROM BusRoutes WHERE RouteID = :road_id";
    query.prepare(queryString);
    query.bindValue(":road_id", road_id);
    if (!query.exec()) {
        qDebug() << "查询失败:";
        qDebug() << query.lastError().text();
    }
    QList<QStringList> resultList;
    while (query.next()) {
        QStringList row;
        row << "线路ID:"+query.value(0).toString() << "线路编号："+query.value(1).toString() <<"起点站ID:"+ query.value(2).toString()<<"终点站ID:"+query.value(3).toString()<<"途径站点顺序:"+query.value(4).toString();
        resultList.append(row);
    }
    QString textToShow;
    for (const QStringList& row : resultList) {
        QString rowText = row.join("\t");
        textToShow += rowText + "\n";
    }

    ui->printfEdit->setPlainText(textToShow);

}

void bus_road_in::on_pushButton_clicked()
{
    user *f = new user;
    this->close();
    f->show();
}


void bus_road_in::on_pushButton_2_clicked()
{
    on_lineEdit_returnPressed();
}

void bus_road_in::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
