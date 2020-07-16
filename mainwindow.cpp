#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enterdialog.h"
#include "leavedialog.h"
#include "parkinginfo.h"
#include "carinfo.h"
#include "parking.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("停车场管理系统 汉化版"));
    ui->freePlaces->setText(QString::number(MAX_CAR));
    ui->statusBar->showMessage("Designed and translated by Francis Grace©2020");

    extern QLabel *l1,*l2,*l3,*l4;
    l1=ui->occupiedPlaces;
    l2=ui->freePlaces;
    l3=ui->countPas;
    l4=ui->totalEarnings;
}

void MainWindow::updateMessage(QString msg)
{
    ui->message->append(msg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enter_clicked()
{
    enterDialog enterInput(this);
    enterInput.setWindowTitle("车辆入场");
    enterInput.exec();
}

void MainWindow::on_leave_clicked()
{
    leaveDialog leaveInput(this);
    leaveInput.setWindowTitle("车辆离场");
    leaveInput.exec();
}

void MainWindow::on_checkParking_clicked()
{
    extern System sys;
    parkingInfo info(this);
    info.setWindowTitle("场地查询");
    QTableView* table=info.getTableAddress();
    QStandardItemModel* model=new QStandardItemModel();
    table->setModel(model);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QTextBrowser* text=info.getTextAddress();
    sys.showCondition(model,text);
    info.exec();
}

void MainWindow::on_checkCar_clicked()
{
    carInfo info(this);
    info.setWindowTitle("车辆查询");
    info.exec();
}

void MainWindow::closeEvent()
{
    extern int size;
    extern Car* carList[1000];
    for (int i = 0; i < size; i++){
        //cout<<"delete "<<carList[i]->getNumber()<<endl;
        delete carList[i];
    }
}
