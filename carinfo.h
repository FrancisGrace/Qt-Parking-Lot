#ifndef CARINFO_H
#define CARINFO_H

#include <QDialog>

namespace Ui {
class carInfo;
}

class carInfo : public QDialog
{
    Q_OBJECT

public:
    explicit carInfo(QWidget *parent = 0);
    ~carInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::carInfo *ui;
};

#endif // CARINFO_H
