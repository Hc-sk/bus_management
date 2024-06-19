#ifndef CONNECT_SQL_H
#define CONNECT_SQL_H

#include <QWidget>

namespace Ui {
class connect_sql;
}

class connect_sql : public QWidget
{
    Q_OBJECT

public:
    explicit connect_sql(QWidget *parent = nullptr);
    ~connect_sql();

private:
    Ui::connect_sql *ui;
};

#endif // CONNECT_SQL_H
