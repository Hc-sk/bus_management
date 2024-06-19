#include "busstops.h"
#include "ui_busstops.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

busstops::busstops(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::busstops)
{
    ui->setupUi(this);
}

busstops::~busstops()
{
    delete ui;
}

void busstops::on_lineEdit_returnPressed()
{
    QString bus_id = ui->lineEdit->text();
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
    bool found = false;
    QSqlQuery query(db);
    QString queryString = "SELECT * FROM BusStops WHERE StationID = :bus_id";
    query.prepare(queryString);
    query.bindValue(":bus_id", bus_id);
    if (!query.exec()) {
        qDebug() << "查询失败:";
        qDebug() << query.lastError().text();
    }
    QList<QStringList> resultList;
    while (query.next()) {
        QStringList row;
        row<< "站点名称："+query.value(1).toString() <<"站点编号:"+ query.value(2).toString()<<"站点位置:"+query.value(3).toString();
        resultList.append(row);
        found = true;
    }
    if(!found){
        ui->textEdit->setPlainText("未找到相应的站点信息");
    }else{
        QString textToShow;
        for (const QStringList& row : resultList) {
            QString rowText = row.join("\t");
            textToShow += rowText + "\n";
        }
        ui->textEdit->setPlainText(textToShow);
    }
}


void busstops::on_pushButton_clicked()
{
    on_lineEdit_returnPressed();
}


void busstops::on_pushButton_2_clicked()
{
    this->close();
    user *h =new user;
    h->show();
}

void busstops::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
