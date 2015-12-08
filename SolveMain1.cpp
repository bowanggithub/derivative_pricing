#include "Bisection.h"
#include <cmath>
#include <iostream>
#include "BSCallClass.h"
#include "BlackSholesFormulas.h"
using namespace std;
int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double r;
    double d;
    double Price;

    cout << "\nEnter expiry\n";
    cin >> Expiry;

    cout << "\nStrike\n";
    cin >> Strike;

    cout << "\nEnter spot\n";
    cin >> Spot;

    cout << "\nEnter price\n";
    cin >> Price;

    cout << "\nr\n";
    cin >> r;

    cout << "\nd\n";
    cin >> d;

    double low, high;

    cout << "\nlower guess\n";
    cin >> low;

    cout << "\nhigher guess\n";
    cin >> high;

    double tolerance;

    cout << "\nTolerance\n";
    cin >> tolerance;

    BSCall theCall(r,d,Expiry,Spot,Strike);

    double vol = Bisection(Price, low, high, tolerance, theCall);
    double PriceTwo = BlackSholesCall(Spot,Strike,r,d,vol,Expiry);

    cout << "\n vol " << vol << " pricetwo " << PriceTwo << "\n";

    double tmp;
    cin >> tmp;

    return 0;
}
