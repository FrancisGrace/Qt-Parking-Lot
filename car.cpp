#include"parking.h"

Car::Car()
{
	id = "";
	parkingPlace = -1;
}

Car::Car(const string& ID)
{
	id = ID;
	parkingPlace = -1;
}

void Car::enter(int place, int currentTime)
{
    extern QString msg;
    enterTime.push_back(currentTime);
	parkingPlace = place;
    msg+=("汽车" + QString::fromStdString(id) + "已在"
          + QString::number(currentTime) + "时刻进入车位" +
          QString::number(place) + "。");
}

void Car::leave(int currentTime)
{
    extern QString msg;
    int i = enterTime.size();
	leaveTime.push_back(currentTime);
	parkedPlace.push_back(parkingPlace);
	costMoney.push_back(cost(enterTime[i - 1], leaveTime[i - 1]));
    msg+=("汽车" + QString::fromStdString(id) + "已在"
          + QString::number(currentTime) +
          "时刻离开车位" + QString::number(parkingPlace) + "，");
    msg+=("消费" + QString::number(cost(enterTime[i - 1], leaveTime[i - 1]))+"元\n");
	parkingPlace = -1;
}

double Car::cost(int start, int end) const
{
	int delta = end - start - 15;
	double s;
	if (delta < 0)
		s = 0;
	else
		s = (delta / 30 + 1) * 1.5;
	return s;
}

void Car::showRecord() const
{
    extern QTableWidget* record;
    record->setRowCount(costMoney.size());
	for (int i = 0; i < costMoney.size(); i++)
    {
        record->setItem(i,0,new QTableWidgetItem(QString::number(enterTime[i])));
        record->setItem(i,1,new QTableWidgetItem(QString::number(leaveTime[i])));
        record->setItem(i,2,new QTableWidgetItem(QString::number(parkedPlace[i])));
        record->setItem(i,3,new QTableWidgetItem(QString::number(costMoney[i])));
    }
}

void Car::reset()
{
	id = "";
	enterTime.clear();
	leaveTime.clear();
	parkedPlace.clear();
	costMoney.clear();
	parkingPlace = -1;
}
