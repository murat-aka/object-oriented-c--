#include "Ascii.h"
#include <iostream>
#include <iomanip>
using namespace std;

Ascii::Ascii()
{
    cout << "\n\n";
    cout << setfill('*');
    cout << setw(25) << "*"  << endl;
    cout <<  "Database Program"  << endl;

    cout << "2013"  << endl;

    cout << setw(25) << "*"  << endl;
    cout << setfill(' ');
    cout << endl;
}
