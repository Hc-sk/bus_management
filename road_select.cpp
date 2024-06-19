#include "road_select.h"
#include "ui_road_select.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

road_select::road_select(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::road_select)
{
    ui->setupUi(this);
}

road_select::~road_select()
{
    delete ui;
}

void road_select::on_pushButton_clicked()
{
    QString start_id = ui->startEdit->text();
    QString end_id = ui->endEdit->text();

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
    QString queryString = "SELECT * FROM BusRoutes WHERE StartStationID = :start_id AND EndStationID = :end_id";
    query.prepare(queryString);
    query.bindValue(":start_id", start_id);
    query.bindValue(":end_id", end_id);
    if (!query.exec()) {
        qDebug() << "查询失败:";
        qDebug() << query.lastError().text();
    }
    bool found = false;
    QList<QStringList> resultList;
    while (query.next()) {
        QStringList row;
        row << "线路ID:"+query.value(0).toString() << "线路编号："+query.value(1).toString()<<"途径站点顺序:"+query.value(4).toString();
        resultList.append(row);
        found = true;
    }
    if(!found){
         ui->textEdit->setPlainText("未找到相应的路线信息");
    }else{
    QString textToShow;
    for (const QStringList& row : resultList) {
        QString rowText = row.join("\t");
        textToShow += rowText + "\n";
    }
    ui->textEdit->setPlainText(textToShow);
    }
}


void road_select::on_pushButton_2_clicked()
{
    user *f = new user;
    this->close();
    f->show();
}

void road_select::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
