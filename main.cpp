#include "Driver.h"
#include "SortedType.h"
#include "GraphType.h"
#include "Management.h"
#include "StackType.h"
#include "Supervision.h"

using namespace std;

int main()
{
    Supervision super;
    system("color 3");
    ifstream in("welcome.txt");
    fstream in1("drivers.txt");
    fstream i("drivers.txt");
    ifstream in2("places.txt");
    ifstream in3("direction.txt");
    ifstream in4("o.txt");
    ifstream op("Options.txt");
    ofstream out("output.txt");
    ofstream o("o.txt");
    ofstream a("a.txt");
    ofstream Top5EarnersList("Top 5 Earners.txt");
    ofstream Top5mostfinedList("Top 5 Most Fined Drivers.txt");
    ofstream Top5LeastRatedList("Top 5 Least Rated.txt");

    super.ConsolePrintfromFile(in);
    Management m;
    m.setDrivers(in1,out);
    m.setDestinations(in2, in3);

    string cur, des;
    double dis= 0;

    string current ;
    string destination;

    cout << "Your current Location: ";
    super.AddressValidation(current, m);
    cout << "Your destination Location: ";
    super.AddressValidation(destination, m);
    dis = m.getDistance(current, destination);

    if(dis !=0 )
    {
        cout << "Distance: " << dis << " K.M." << endl;
        cout << "Approximate time: (to reach the destination) " << m.getAproximatedTime(dis) << " minutes"<< endl << endl << endl;
        int n, radius;

        super.ConsolePrintfromFile(op);
        cout << "Select Your Preference : ";cin >> n;


        string car;
        SortedType<Driver> NewdriverList;

        switch(n)
        {
        case 1:
            NewdriverList.makeEmpty();

            while(NewdriverList.getLength()== 0)
            {
                cout << "Set a radius: (5 K.M default) "; cin >> radius;
                cout << "List of drivers within 0-" << radius << " K.M. :" << endl;
                m.getNearestDriver(NewdriverList, current, radius);
                cout << "Cars Found: " << NewdriverList.getLength() << endl << endl << endl;
                super.ListChecking(NewdriverList, o, in4, radius);
            }
            break;
        case 2:
            NewdriverList.makeEmpty();
            cout << "List of Top rated drivers: " << endl;
            m.getTopRatedDrivers(NewdriverList);
            super.ListChecking2(NewdriverList, o, in4);
            break;
        case 3:
            NewdriverList.makeEmpty();
            while(NewdriverList.getLength()==0)
            {
            cout << "Your preferred Car-Type: "; cin>>car;
            m.getSuitableCarByType(NewdriverList, car);
            if(NewdriverList.getLength() != 0)
                {
                    cout << "List of similar Car-Type: (" << car << ")" << endl;
                    cout << "Cars Found: " << NewdriverList.getLength() << endl << endl << endl;

                    super.ListChecking3(NewdriverList, o, in4);
                }
            else cout << "We don't have any similar type of cars. Keywords : Car, Private, Jeep, Micro." << endl;

            }
            break;
        case 4:
            NewdriverList.makeEmpty();
            int number;
            while(NewdriverList.getLength()==0)
            {
                cout << "You need: (Passengers) "; cin >> number;
                if(number > 8) cout << "We don't have any car that supports more than 8 passengers" << endl;
                else{
                m.getSuitableCarByPassengerNo(NewdriverList, number);
                cout << "List of cars support at least " << number << " passengers: " << endl;
                cout << "Cars Found: " << NewdriverList.getLength() << endl << endl << endl;
            }
            super.ListChecking3(NewdriverList, o, in4);
            }
            break;
        case 5:
            NewdriverList.makeEmpty();
            while(NewdriverList.getLength()==0)
            {
                cout << "Set a radius: (5 K.M default) "; cin >> radius;
                cout << "List of Top Rated drivers within 0-" << radius << " K.M. :" << endl;
                m.getNearestTopRatedDriver(NewdriverList, current, radius);
                cout << "Cars Found: " << NewdriverList.getLength() << endl << endl << endl;

                super.ListChecking(NewdriverList, o, in4, radius);
            }

            break;
        case 6:
            NewdriverList.makeEmpty();

            cout << "Your preferred Car-Type(Keywords: Car, Micro, Private, Jeep): "; cin>>car;
            while(NewdriverList.getLength()==0)
            {
            cout << "Set a radius: (5 K.M default) "; cin >> radius;
            cout << "List of drivers within 0-" << radius << " K.M." << " with similar car type " << car << " :" << endl;
            m.getNearestByCarType(NewdriverList, current, radius , car);
            cout << "Cars Found: " << NewdriverList.getLength() << endl << endl << endl;

            super.ListChecking(NewdriverList, o, in4, radius);
            }
            break;
        case 7:
            NewdriverList.makeEmpty();

            while(NewdriverList.getLength()==0)
            {
                cout << "You need: (Passengers) "; cin >> number;
                if(number > 8) cout << "We don't have any car that supports more than 8 passengers" << endl;
                else{
                cout << "Set a radius: (5 K.M default) "; cin >> radius;
                m.getNearestByPas(NewdriverList, current, radius , number);
                cout << "List of drivers within 0-" << radius << " K.M. :" << "with minimum " << number << " passengers: " << endl;
                cout << "Cars Found: " << NewdriverList.getLength() << endl << endl << endl;

                super.ListChecking(NewdriverList, o, in4, radius);
                }
            }
            break;
        case 8:
            NewdriverList.makeEmpty();

            while(NewdriverList.getLength()==0)
            {
                cout << "Your preferred Car-Type: "; cin>>car;
                m.getTopRatedByCarType(NewdriverList, car);
                if(NewdriverList.getLength() != 0)
                {
                    cout << "List of similar Car-Type(Top Rated): (" << car << ")" << endl;
                    cout << "Cars Found: " << NewdriverList.getLength() << endl << endl << endl;

                    super.ListChecking2(NewdriverList, o, in4);
                }
                else cout << "We don't have any similar type of cars. Keywords : Car, Private, Jeep, Micro." << endl;
            }
            break;
        case 9:
            NewdriverList.makeEmpty();
            int num;
            while(NewdriverList.getLength()==0)
            {
            cout << "You need: (Passengers) "; cin >> num;
            if(num > 8) cout << "We don't have any car that supports more than 8 passengers" << endl;
            else{
            m.getTopRatedByPas(NewdriverList, num);
            cout << "List of Top cars support at least " << num << " passengers: " << endl;
            cout << "Cars Found: " << NewdriverList.getLength() << endl << endl << endl;

            super.ListChecking2(NewdriverList, o, in4);
            }
            }
            break;
        default:
            NewdriverList.makeEmpty();
            cout << "Default Selection. List of all Drivers: " << endl;
            m.getAllDrivers(NewdriverList);
            cout << "Drivers found: " << NewdriverList.getLength() << endl;

            super.ListChecking3(NewdriverList, o, in4);
        }

        int carno;
        cout << "Enter Car Number: "; cin >> carno;

        super.UpdateAndPrintMemo(m, carno, dis, current, destination , i);
        super.get5Earners(m,Top5EarnersList);
        super.get5Fined(m, Top5mostfinedList);
        super.get5LeastRatedDriver(m, Top5LeastRatedList);
    }
    return 0;
}
