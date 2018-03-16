#ifndef SUPERVISION_H
#define SUPERVISION_H

#include <ctime>
#include "conio.h"
#include <cstring>
#include <string>
#include <cstdlib>
#include "SortedType.h"
#include "Driver.h"
#include "Management.h"
#include <fstream>
class Supervision
{
public:
    Supervision();
    void ConsolePrintfromFile(ifstream&);
    void ListChecking(SortedType<Driver>&,ofstream&,ifstream&, int);
    void ListChecking2(SortedType<Driver>&, ofstream&,ifstream&);
    void ListChecking3(SortedType<Driver>&, ofstream&,ifstream&);
    void UpdateAndPrintMemo(Management&, int, double, string, string, fstream&);
    void AddressValidation(string&,Management&);
    void get5LeastRatedDriver(Management&, ofstream&);
    void get5Earners(Management&, ofstream&);
    void get5Fined(Management&, ofstream&);
    bool compare(string);
};
#endif // SUPERVISION_H
