#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enterdialog.h"
#include "ui_enterdialog.h"
#include "parking.h"
#include <QDebug>

enterDialog::enterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enterDialog)
{
    ui->setupUi(this);
}

enterDialog::~enterDialog()
{
    delete ui;
}

void enterDialog::on_buttonBox_2_accepted()
{
    extern string id;
    extern Car* carList[1000];
    extern System sys;
    extern int size, i, currentTime;
    extern QString msg;
    id=(ui->idInput->text()).toStdString();
    currentTime=ui->timeInput->value();
    msg="";
    bool flag = false;
    for (i = 0; i < size; i++)
    {
        if (carList[i]->getNumber() == id)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        sys.enterParking(*carList[i], currentTime);
    else
    {
        carList[size] = new Car(id);
        sys.enterParking(*carList[size], currentTime);
        //cout<<"new "<<carList[size]->getNumber()<<endl;
        size++;
    }
    ((MainWindow*)(this->parentWidget()))->updateMessage(msg);
    this->close();
}

void enterDialog::on_buttonBox_2_rejected()
{
    this->close();
}
