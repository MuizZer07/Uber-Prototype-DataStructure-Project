#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <fstream>
#include <string>
#include <cstring>
#include "Driver.h"
#include "SortedType.h"
#include "GraphType.h"
#include "StackType.h"
class Management
{
private:
    SortedType<Driver> u;
    GraphType<string> g;
public:
    Management();
    void getAllDrivers(SortedType<Driver>&);
    void setDrivers(fstream&, ofstream&);
    void setDestinations(ifstream&, ifstream&);
    void getSuggestions(string);
    double getDistance(string, string );
    double getTotalFare(Driver, double);
    double getAproximatedTime(double);
    Driver getDriver(int);

    void getTopRatedByCarType(SortedType<Driver>&, string);
    void getTopRatedByPas(SortedType<Driver>&, int);
    void getNearestByCarType(SortedType<Driver>&, string, int, string);
    void getNearestByPas(SortedType<Driver>&, string, int, int);
    void getNearestTopRatedDriver(SortedType<Driver>&, string, int);
    void getNearestDriver(SortedType<Driver>&, string, int);
    void getSuitableCarByType(SortedType<Driver>&, string);
    void getSuitableCarByPassengerNo(SortedType<Driver>&, int);
    void getTopRatedDrivers(SortedType<Driver>&);
    void getTopEarnerDrivers(SortedType<Driver>&);
    void getMostFined(SortedType<Driver>&);
    void UpdateDriver(int, string, string, double, int, fstream& );
};
#endif // MANAGEMENT_H

