#ifndef PARKING_H_
#define PARKING_H_
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<deque>
#include<QString>
#include<QStandardItemModel>
#include<QTableView>
#include<QTextBrowser>
#include<QTableWidget>
#include<QLabel>
#include<QFont>
using namespace std;
const int MAX_CAR = 3;

class Car
{
    string id;
    vector<int> enterTime, leaveTime, parkedPlace;
    vector<double> costMoney;
    int parkingPlace;
public:
    Car();
    Car(const string&);
    void enter(int, int);
    void leave(int);
    double cost(int, int) const;
    int getPlace() const{ return parkingPlace; }
    string getNumber() const{ return id; }
    double lastFee() const{ return costMoney[costMoney.size() - 1]; }
    void showRecord() const;
    void reset();
};

class Parking
{
    Car parking[MAX_CAR + 1];
    int occupiedPlaces = 0;
public:
    Parking(){};
    bool isFull() const;
    void enterPar(Car&, int);
    void remove(int);
    bool findCar(const string&, bool) const;
    void show(QStandardItemModel* model) const;
};

class Passageway
{
    deque<Car*> passageway;
public:
    void enterWay(Car*);
    void leaveWay();
    Car* getFront() const;
    int countCar() const;
    bool findCar(const string&, bool) const;
    void show(QTextBrowser*) const;
};

class System
{
    Parking par;
    Passageway pas;
    double earnings = 0;
public:
    System(){};
    void enterParking(Car&, int);
    void leaveParking(Car&, int);
    void enterPassageway(Car&);
    void passToPark(int);
    void showCar(const string&) const;
    //void showEarnings() const;
    void showCondition(QStandardItemModel*, QTextBrowser*) const;
};
#endif
