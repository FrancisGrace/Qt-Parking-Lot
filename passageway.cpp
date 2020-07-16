#include"parking.h"
#include<iostream>
#include<iterator>
using std::cout;
using std::endl;

void Passageway::enterWay(Car* car)
{
	passageway.push_back(car);
    extern QLabel* l3;
    l3->setText(QString::number(passageway.size()));
}

void Passageway::leaveWay()
{
	passageway.pop_front();
    extern QLabel* l3;
    l3->setText(QString::number(passageway.size()));
}

Car* Passageway::getFront() const
{
	return *(passageway.begin());
}

int Passageway::countCar() const
{
	return passageway.size();
}

bool Passageway::findCar(const string& id, bool print) const
{
    extern QString state;
    for (deque<Car*>::const_iterator i = passageway.begin(); i != passageway.end(); i++)
		if ((*i)->getNumber() == id)
		{
            if (print)
                state="便道";
                //cout << "Car " << id << " is in the passageway" << endl;
			return true;
		}
	return false;
}

void Passageway::show(QTextBrowser* text) const
{
	if (passageway.size() == 0)
        return;
        //cout << "(empty)" << endl;
	else
	{
		for (deque<Car*>::const_iterator i = passageway.begin(); i != passageway.end(); i++)
            text->append(QString::fromStdString((*i)->getNumber()));
            //cout << (*i)->getNumber() << endl;
        //cout << "(" << passageway.size() << " car(s))" << endl;
	}
}
