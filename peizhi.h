#ifndef PEIZHI_H
#define PEIZHI_H

#include <QWidget>

namespace Ui {
class peizhi;
}

class peizhi : public QWidget
{
    Q_OBJECT

public:
    explicit peizhi(QWidget *parent = nullptr);
    ~peizhi();

private:
    Ui::peizhi *ui;
};

#endif // PEIZHI_H
