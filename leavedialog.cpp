#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "leavedialog.h"
#include "ui_leavedialog.h"
#include "parking.h"
#include <QDebug>

leaveDialog::leaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::leaveDialog)
{
    ui->setupUi(this);
}

leaveDialog::~leaveDialog()
{
    delete ui;
}

void leaveDialog::on_buttonBox_accepted()
{
    extern string id;
    extern Car* carList[1000];
    extern System sys;
    extern int size, i, currentTime;
    extern QString msg;
    id=(ui->idInput->text()).toStdString();
    currentTime=ui->timeInput->value();
    msg="";
    for (i = 0; i < size; i++)
    {
        if (carList[i]->getNumber() == id)
            break;
    }
    if (i == size)
        msg="错误：汽车"+QString::fromStdString(id)+"当前不在停车场内！";
        //cout << "Error:Car " << id << " is now out of the parking!" << endl;
    else
        sys.leaveParking(*carList[i], currentTime);
    ((MainWindow*)(this->parentWidget()))->updateMessage(msg);
    this->close();
}


void leaveDialog::on_buttonBox_rejected()
{
    this->close();
}
