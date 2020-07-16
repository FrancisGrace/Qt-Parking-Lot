#include "carinfo.h"
#include "ui_carinfo.h"
#include "parking.h"

carInfo::carInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carInfo)
{
    ui->setupUi(this);
}

carInfo::~carInfo()
{
    delete ui;
}

void carInfo::on_pushButton_clicked()
{
    extern System sys;
    extern QString state;
    extern string id;
    extern QTableWidget* record;
    record=ui->recordView;
    id=(ui->idInput->text()).toStdString();
    ui->recordView->clear();

    QStringList headerText;
    headerText<<"入场时间"<<"离场时间"<<"泊车位"<<"费用";
    ui->recordView->setHorizontalHeaderLabels(headerText);
    ui->recordView->setColumnCount(headerText.count());

    sys.showCar(id);
    ui->spaceView->setText(state);
}
