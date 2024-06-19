#include "changestop.h"
#include "ui_changestop.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>


changestop::changestop(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::changestop)
{
    ui->setupUi(this);
    groupbutton = new QButtonGroup(this);
    groupbutton->addButton(ui->nameButton,1);
    groupbutton->addButton(ui->numButton,2);
    groupbutton->addButton(ui->locationButton,3);

}

changestop::~changestop()
{
    delete ui;
}


void changestop::on_pushButton_clicked()
{
    QString stop_id = ui->idEdit->text();
    QString change = ui->contentEdit->text();
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
        queryString = "UPDATE BusStops SET StationName = :change  WHERE StationID = :stop_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":stop_id", stop_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    case 2:
        queryString = "UPDATE BusStops SET StationNumber = :change  WHERE StationID = :stop_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":stop_id", stop_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    case 3:
        queryString = "UPDATE BusStops SET Location = :change  WHERE StationID = :stop_id ";
        query.prepare(queryString);
        query.bindValue(":change", change);
        query.bindValue(":stop_id", stop_id);
        if (!query.exec()) {
            qDebug() << "修改失败:";
        }else{
            QMessageBox::information(this,tr("消息"),tr("修改成功"));
        }
        break;
    }
}


void changestop::on_pushButton_2_clicked()
{
    this->close();
    stop_man *s = new stop_man;
    s->show();
}
void changestop::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
