#include "road_inf.h"
#include "ui_road_inf.h"

#include <QSqlQuery>
#include <QSqlError>
road_inf::road_inf(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::road_inf)
{
    ui->setupUi(this);
}

road_inf::~road_inf()
{
    delete ui;
}

void road_inf::on_lineEdit_returnPressed()
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
    bool found =false;
    QSqlQuery query(db);
    QString queryString = "SELECT * FROM Roads WHERE RoadID = :road_id";
    query.prepare(queryString);
    query.bindValue(":road_id", road_id);
    if (!query.exec()) {
        qDebug() << "查询失败:";
        qDebug() << query.lastError().text();
    }
    QList<QStringList> resultList;
    while (query.next()) {
        QStringList row;
        row<<"道路名称："+query.value(1).toString()<<"道路编号:"+ query.value(2).toString()<<"起点站ID:"+query.value(3).toString()<<"终点站ID:"+query.value(4).toString();
        resultList.append(row);
        found = true;
    }
    if(!found){
        ui->textEdit->setPlainText("未找到相应的道路信息");
    }else{
        QString textToShow;
        for (const QStringList& row : resultList) {
            QString rowText = row.join("\t");
            textToShow += rowText + "\n";
        }
        ui->textEdit->setPlainText(textToShow);
    }
}

void road_inf::on_pushButton_clicked()
{
    this->close();
    user *u =new user;
    u->show();
}


void road_inf::on_pushButton_2_clicked()
{
    on_lineEdit_returnPressed();
}

void road_inf::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
