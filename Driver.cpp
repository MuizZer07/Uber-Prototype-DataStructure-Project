#ifndef DRIVER_CPP
#define DRIVER_CPP

using namespace std;
#include "Driver.h"
#include <iostream>

Driver::Driver()
{

}
Driver::Driver(int serial, string name, string loc, string type, double fare, int pas, double KM, double rating, int fine, int noFined, string phone, int rated)
{
    CarNo = serial;
    this->name = name;
    currentLocation = loc;
    carType = type;
    FarePerKM = fare;
    Passenger = pas;
    totalKMperMonth = KM;
    this->Rating = rating;
    sumOfFine = fine;
    this->noFined = noFined;
    this->phone =  phone;
    this->customerRated = rated;
}
void Driver::setName(string name)
{
    this->name = name;
}
void Driver::setCarNo(int n)
{
    CarNo = n;
}
void Driver::IncreaseTotalKMperMonth(double km)
{
    totalKMperMonth = totalKMperMonth + km;
}
int Driver::getTotalEaringThisMonth()
{
    return FarePerKM * totalKMperMonth;
}
string Driver::getPhoneNumber()
{
    return phone;
}
double Driver::getTotalKMperMonth()
{
    return totalKMperMonth;
}
int Driver::getNoOfTimesFined()
{
    return noFined;
}
int Driver::getSumOfFine()
{
    return sumOfFine;
}
double Driver::getRating()
{
    return Rating;
}
double Driver::getFarePerKM()
{
    return FarePerKM;
}
int Driver::getCarNo()
{
    return CarNo;
}
int Driver::getPassengerSupports()
{
    return Passenger;
}
string Driver::getCarType()
{
    return carType;
}
string Driver::getCurrentLocation()
{
    return currentLocation;
}
void Driver::setCurrentLocation(string location)
{
    this->currentLocation = location;
}
string Driver::getName()
{
    return name;
}
void Driver::print(ofstream& out)
{
    out << "Car No.: " << CarNo << endl;
    out << "Car Type: " << carType <<  "\nNo. of Passenger Supports: " << Passenger << endl;
    out << "Driver's Name: " << name << "\nContact Number: " << phone << endl;
    out << "Rating: " << Rating << endl << "Number of times fined: " << noFined << endl;
    out << "Total Fine: " << sumOfFine << endl << "Total Earning in this month: " << getTotalEaringThisMonth() << endl;
    out << "Fare/K.M. : " << FarePerKM << "\nCurrent Location: " << currentLocation <<endl << endl;
}
RelationType Driver::CompareTo(Driver d)
{
    if(CarNo == d.CarNo) return EQUAL;
    else if(CarNo < d.CarNo) return LESS;
    else return GREATER;
}
RelationType Driver::CompareBYrating(Driver d)
{
    if(Rating == d.Rating) return EQUAL;
    else if(Rating < d.Rating) return LESS;
    else return GREATER;
}
RelationType Driver::CompareBYearnings(Driver d)
{
    if(getTotalEaringThisMonth() == d.getTotalEaringThisMonth()) return EQUAL;
    else if(getTotalEaringThisMonth() < d.getTotalEaringThisMonth()) return LESS;
    else return GREATER;
}
RelationType Driver::CompareBYfine(Driver d)
{
    if(sumOfFine == d.sumOfFine) return EQUAL;
    else if(sumOfFine < d.sumOfFine) return LESS;
    else return GREATER;
}

void Driver::setRating(double r)
{
    int noo = getNoCustomerRated();
    customerRated++;
    int no = getNoCustomerRated();
    double prev = getRating() * noo;

    double newRate = prev + r;
    double ratingNew = (newRate/no);
    int a =ratingNew * 10;
    ratingNew = a/10.0;
    this->Rating = ratingNew;
}

int Driver::getNoCustomerRated()
{
    return customerRated;
}
void Driver::IncreaseSumOfFines(int newFine)
{
    if(newFine > 0)noFined++;
    sumOfFine = getSumOfFine() + newFine;
}
void Driver::printUpdate(fstream& out)
{
    out << CarNo << " " << name << " " << currentLocation << " " << carType << " " << FarePerKM << " " << Passenger << " "
    << totalKMperMonth << " " << Rating <<  " "<< sumOfFine << " " << noFined << " " << phone << " " << customerRated << endl;
}
#endif // DRIVER_CPP

