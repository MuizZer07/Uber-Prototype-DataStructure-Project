#ifndef SUPERVISION_CPP
#define SUPERVISION_CPP


#include "Supervision.h"

void fordelay(int j){
    int i;
    for(i=0;i<j;i++)
         int k=i;
}

Supervision::Supervision()
{

}
void Supervision::ConsolePrintfromFile(ifstream& in)
{
    string line;
    while (in)
    {
        getline(in ,line);
        cout << line << endl;
    }
}
void Supervision::ListChecking(SortedType<Driver>& NewdriverList, ofstream& o, ifstream& in, int radius)
{
    if(NewdriverList.getLength() != 0)
    {
        NewdriverList.printList(o);
        ConsolePrintfromFile(in);
    }
    else cout << "Sorry! We don't have any car near by! (Within " << radius << " K.M). Try Again!" << endl;
}
void Supervision::ListChecking2(SortedType<Driver>& NewdriverList, ofstream& o, ifstream& in)
{
    if(NewdriverList.getLength() != 0)
    {
        NewdriverList.setHighestLength(5);
        NewdriverList.printList(o);
        ConsolePrintfromFile(in);
    }
}
void Supervision::ListChecking3(SortedType<Driver>& NewdriverList, ofstream& o, ifstream& in)
{
    if(NewdriverList.getLength() != 0)
    {
        NewdriverList.printList(o);
        ConsolePrintfromFile(in);
    }
}
void Supervision::UpdateAndPrintMemo(Management& m, int carno, double dis, string cur, string des, fstream& i)
{
        double r;
        Driver driver = m.getDriver(carno);
        double fare = m.getTotalFare(driver, dis);
        double as = m.getDistance(cur, driver.getCurrentLocation());
        double b = m.getAproximatedTime(as);
        int con;
        cout << "Confirm your fare:" << endl << "Press 1 to Confirm" << endl << "Press 2 to cancel" << endl;
        cin >> con;
        if(con == 1)
        {
            cout << "Your ride will be arrived within " << b << " minutes (Apprx.).. please wait...";
            cout << "\n\n\nThank you for your patience. Enjoy your ride with Uber." << endl;
            cout << "\nRate your driver (out of 5): "; cin >> r;
            if(r > 5) r = 5;

            int fine = 0;
            srand(time(NULL));

            if(r < 2) fine = 1 + rand() % 100 ;

            system("cls");
            ifstream inv("welcome.txt");
            ConsolePrintfromFile(inv);
            cout<<"\n\n\n\n LOADING\n Please Wait";
            for(int i=0;i<=5;i++)
            {
                fordelay(110000000);
                cout<< " .";
            }system("cls");
            ifstream inv1("welcome.txt");
            ConsolePrintfromFile(inv1);

            cout << endl << endl;
            cout << "-------------------------------" << endl;
            cout << "-------------------------------" << endl;
            cout << "\tPayment Memo " << endl;
            cout << "-------------------------------" << endl;
            cout << "-------------------------------" << endl;
            cout << "\tFrom : " << cur << endl << endl;
            cout << "\tTo   : " << des << endl << endl;
            cout << "\tFare : " << fare << " BDT" <<endl << endl ;
            cout << "-------------------------------" << endl;
            cout << "-------------------------------" << endl;
            cout << "\nDriver's Signature: " << driver.getName() << endl;
            cout << "Date : 20.12.16" << endl;
            cout << "-------------------------------" << endl;
            cout << "-------------------------------" << endl << endl << endl;
            cout << "To Find our Top 5 Monthly Earners list open 'Top 5 Earners.txt' " << endl;
            cout << "To Find our Top 5 least rated drivers list Open 'Top 5 Least Rated.txt' " << endl;
            cout << "To Find our Top 5 Most Fined drivers list Open 'Top 5 Most Fined Drivers.txt' " << endl;

            m.UpdateDriver(carno, cur, des, r, fine, i);
        }
        else
        {
            cout << "You've canceled your fare. Restart the program to make a fare. Thank You" << endl;
        }
}

bool Supervision::compare(string cur)
{
    ifstream places("places.txt");
    string l ;
    bool found;
    while (places>> l)
    {
        if(l.compare(cur) == 0)
            return (found = true);
        else
            found = false;
    }
    return found;
}
void Supervision::AddressValidation(string& current,Management& m)
{
    string cur;
     while(current == "")
    {
         cin >> cur;
        if(compare(cur)== true) current = cur;
        else
        {
             cout << "Invalid Address. ";
             m.getSuggestions(cur);
             cout << endl << "Type Address Again: " ;
        }
    }

}
void Supervision::get5LeastRatedDriver(Management& m, ofstream& out)
{
        SortedType<Driver> leastRated;
        SortedType<Driver> top;
        m.getTopRatedDrivers(top);
        StackType<Driver> dstack;

        top.resetList();
        for (int i=0; i< top.getLength(); i++)
        {
            leastRated.putRandom(top.getNextItem());
        }
        leastRated.setHighestLength(5);
        leastRated.printList(out);
}
void Supervision::get5Earners(Management& m, ofstream& out)
{
    SortedType<Driver> NewdriverList;
    m.getTopEarnerDrivers(NewdriverList);
    NewdriverList.setHighestLength(5);
    NewdriverList.printList(out);
}
void Supervision::get5Fined(Management& m, ofstream& out)
{
    SortedType<Driver> NewdriverList;
    m.getMostFined(NewdriverList);
    NewdriverList.setHighestLength(5);
    NewdriverList.printList(out);
}
#endif // SUPERVISION_CPP
