#ifndef MANAGEMENT_CPP
#define MANAGEMENT_CPP

#include <string>
#include <fstream>
#include <iostream>
#include "Management.h"

Management::Management()
{

}
void Management::setDrivers(fstream& in, ofstream& out)
{
    int Serialno;
    while(in >> Serialno)
    {
            string line;
            in >> line;
            string name = line;
            in >> line;
            string location = line;
            in >> line;
            string type = line;
            double fare;
            in >> fare;
            int passenger;
            in >> passenger;
            double drivenKM;
            in >> drivenKM;
            double rating;
            in >> rating;
            int fine;
            in >> fine;
            int noFined;
            in >> noFined;
            string phone;
            in >> phone;
            int rated;
            in >> rated;

            Driver d(Serialno, name, location, type, fare, passenger, drivenKM, rating, fine, noFined, phone, rated);
            u.putItem(d);
    }
    u.printList(out);
}
void Management::setDestinations(ifstream& infile, ifstream& inputfile)
{
     string line;
     while(infile >> line)
       {
           g.AddVertex(line);
       }
     while(inputfile >> line)
       {
           string place1, place2;
           place1 = line;
           inputfile >> line;
           place2 = line;
           double dis;
           inputfile >> dis;
           g.AddEdge(place1, place2, dis);
       }
    g.ShortestPath();
}

double Management::getDistance(string from, string to)
{
    return g.getShortestDistance(from, to);
}
double Management::getTotalFare(Driver d, double distance)
{
    return d.getFarePerKM() * distance;
}
Driver Management::getDriver(int no)
{
    bool f;
    Driver d;
    d.setCarNo(no);
    return u.getItem(d, f);
}
void Management::getNearestDriver(SortedType<Driver>& s, string cur, int radius)
{
    u.resetList();
    for(int i=0; i < u.getLength(); i++)
    {
        Driver d = u.getNextItem();
        string loc = d.getCurrentLocation();
        if(getDistance(loc,cur) <= radius)
        {
            s.putItem(d);
        }
    }
}
void Management::getSuitableCarByPassengerNo(SortedType<Driver>& s, int pasNo)
{
    u.resetList();
    for(int i=0; i < u.getLength(); i++)
    {
        Driver d = u.getNextItem();
        int spprts = d.getPassengerSupports();
        if(spprts >= pasNo) s.putItem(d);
    }
}
void Management::getSuitableCarByType(SortedType<Driver>& s, string type)
{
    u.resetList();
    for(int i=0; i < u.getLength(); i++)
    {
        Driver d = u.getNextItem();
        string CarType = d.getCarType();

        int found = CarType.find(type);
        if (found!= string::npos)
        s.putItem(d);
    }
}
void Management::getSuggestions(string loc)
{
    string* a = g.getAllVertices();
    cout << "Suggestions: ";
    for(int i = 0; i <g.getNumVertices(); i++)
    {
        int found = a[i].find(loc);
        if (found!= string::npos) cout << a[i] << " ";
    }
}
void Management::getTopRatedDrivers(SortedType<Driver>& s)
{
    u.resetList();
    for(int i=0; i < u.getLength(); i++)
    {
        Driver d = u.getNextItem();
        s.PutBYRating(d);
    }
}
void Management::getTopEarnerDrivers(SortedType<Driver>& s)
{
    u.resetList();
    for(int i=0; i < u.getLength(); i++)
    {
        Driver d = u.getNextItem();
        s.PutBYearnings(d);
    }
}
void Management::getMostFined(SortedType<Driver>& s)
{
    u.resetList();
    for(int i=0; i < u.getLength(); i++)
    {
        Driver d = u.getNextItem();
        s.PutBYfine(d);
    }
}
void Management::UpdateDriver(int no, string from, string to, double rating, int fine, fstream& out)
{
    Driver d = getDriver(no);
    d.IncreaseTotalKMperMonth(g.GetWeight(from, to));
    d.setCurrentLocation(to);
    d.setRating(rating);
    d.IncreaseSumOfFines(fine);

    Driver temp = getDriver(no);
    u.deleteItem(temp);
    u.putItem(d);

    u.printUpdatedList(out);
    out << endl << endl;
}
void Management::getNearestTopRatedDriver(SortedType<Driver>& s, string cur, int radius)
{
    SortedType<Driver> Nearest;

    getNearestDriver(Nearest, cur, radius);
    Nearest.resetList();
    for(int i=0; i < Nearest.getLength(); i++)
    {
        Driver d = Nearest.getNextItem();
        if(d.getRating() >= 4 )s.PutBYRating(d);
    }

}
void Management::getAllDrivers(SortedType<Driver>& s)
{
    u.resetList();
    for(int i=0; i < u.getLength(); i++)
    {
        Driver d = u.getNextItem();
        s.putItem(d);
    }
}
void Management::getNearestByCarType(SortedType<Driver>& s, string cur, int radius, string type)
{
    SortedType<Driver> Nearest;
    getNearestDriver(Nearest, cur, radius);
    Nearest.resetList();
    for(int i=0; i < Nearest.getLength(); i++)
    {
        Driver d = Nearest.getNextItem();
        string CarType = d.getCarType();

        int found = CarType.find(type);
        if (found!= string::npos)
        s.putItem(d);
    }
}
void Management::getNearestByPas(SortedType<Driver>& s, string cur, int radius, int pasNo)
{
    SortedType<Driver> Nearest;
    getNearestDriver(Nearest, cur, radius);
    Nearest.resetList();
    for(int i=0; i < Nearest.getLength(); i++)
    {
        Driver d = Nearest.getNextItem();
        int spprts = d.getPassengerSupports();
        if(spprts >= pasNo) s.putItem(d);
    }
}
void Management::getTopRatedByCarType(SortedType<Driver>& s, string type)
{
    SortedType<Driver> Cartype;
    getSuitableCarByType(Cartype, type);
    Cartype.resetList();
    for(int i=0; i < Cartype.getLength(); i++)
    {
        Driver d = Cartype.getNextItem();
        s.PutBYRating(d);
    }
}
void Management::getTopRatedByPas(SortedType<Driver>& s, int pas)
{
    SortedType<Driver> PasNo;
    getSuitableCarByPassengerNo(PasNo, pas);
    PasNo.resetList();
    for(int i=0; i < PasNo.getLength(); i++)
    {
        Driver d = PasNo.getNextItem();
        int spprts = d.getPassengerSupports();
        if(spprts >= pas) s.PutBYRating(d);
    }
}
double Management::getAproximatedTime(double distance)
{
    if(distance >= 0 && distance <= 2.9) return 5;
    else if(distance >= 3 && distance <= 6.9) return 10;
    else if(distance >= 7 && distance <= 10.9) return 20;
    else if(distance >= 11 && distance <= 15.9) return 35;
    else if(distance >= 15 && distance <= 20.9) return 40;
    else if(distance >= 21 && distance <= 30.9) return 55;
    else return 70;
}
#endif // MANAGEMENT_CPP
