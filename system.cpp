#include"parking.h"

void System::enterParking(Car& car, int currentTime)
{
    extern QString msg;
    string id = car.getNumber();
    if (par.findCar(id, false))
        msg+=("错误：汽车" + QString::fromStdString(id) + "已在车场内！");
    else if (pas.findCar(id, false))
        msg+=("错误：汽车" + QString::fromStdString(id) + "已在便道内！");
    else if (par.isFull())
    {
        pas.enterWay(&car);
        msg+=("车位已满，汽车" + QString::fromStdString(car.getNumber())
              + "已进入便道等候。");
    }
    else
        par.enterPar(car, currentTime);
}

void System::leaveParking(Car& car, int currentTime)
{
    extern QString msg;
    string id = car.getNumber();
    if (!par.findCar(id, false) && !pas.findCar(id, false))
        msg+=("错误：汽车" + QString::fromStdString(id) + "不在停车场内！");
    else if (pas.findCar(id, false))
        msg+=("错误：汽车" + QString::fromStdString(id) + "当前在便道内！");
    else
    {
        bool flag = par.isFull();
        par.remove(car.getPlace());
        car.leave(currentTime);
        earnings += car.lastFee();
        if (flag && pas.countCar())
            passToPark(currentTime);
        extern QLabel* l4;
        l4->setText(QString::number(earnings));
    }
}

void System::enterPassageway(Car& car)
{
    pas.enterWay(&car);
}

void System::passToPark(int currentTime)
{
    Car* car = pas.getFront();
    pas.leaveWay();
    par.enterPar(*car, currentTime);
}

void System::showCar(const string& id) const
{
    extern QString state;
    extern Car* carList[1000];
    extern int size;
    if (!par.findCar(id, true) && !pas.findCar(id, true))
        state="不在场内";
    for (int i = 0; i < size; i++)
    {
        if (carList[i]->getNumber() == id)
        {
            carList[i]->showRecord();
            break;
        }
    }
}

/*void System::showEarnings() const
{
    cout << "The total earnings is " << earnings << endl;
}*/

void System::showCondition(QStandardItemModel* model, QTextBrowser* text) const
{
    par.show(model);
    pas.show(text);
}
