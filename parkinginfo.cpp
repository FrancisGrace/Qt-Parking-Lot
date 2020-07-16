#include "parkinginfo.h"
#include "ui_parkinginfo.h"
#include<QStandardItemModel>

parkingInfo::parkingInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parkingInfo)
{
    ui->setupUi(this);
}

parkingInfo::~parkingInfo()
{
    delete ui;
}

QTableView* parkingInfo::getTableAddress()
{
    return ui->parView;
}

QTextBrowser* parkingInfo::getTextAddress()
{
    return ui->pasView;
}
