#ifndef DRIVER_H
#define DRIVER_H

#include <cmath>
#include <fstream>
#include <string>
using namespace std;

enum RelationType{ GREATER, LESS, EQUAL};

class Driver
{
private:
    string name, phone, currentLocation, carType;
    int noFined, sumOfFine, CarNo, Passenger, customerRated ;
    double Rating, FarePerKM, totalKMperMonth;
public:
    Driver();
    Driver(int, string, string, string, double, int, double, double, int, int, string, int);

    void setName(string name);
    void setCurrentLocation(string);
    void setCarNo(int);
    void IncreaseTotalKMperMonth(double);
    void setRating(double);
    void IncreaseSumOfFines(int);

    string getName();
    string getCurrentLocation();
    string getCarType();
    string getPhoneNumber();

    int getNoCustomerRated();
    int getTotalEaringThisMonth();
    int getNoOfTimesFined();
    int getSumOfFine();
    int getCarNo();
    int getPassengerSupports();
    double getRating();
    double getTotalKMperMonth();
    double getFarePerKM();

    RelationType CompareBYrating(Driver);
    RelationType CompareBYfine(Driver);
    RelationType CompareBYearnings(Driver);
    RelationType CompareTo(Driver);

    void print(ofstream&);
    void printUpdate(fstream&);

};
#endif // DRIVER_H

