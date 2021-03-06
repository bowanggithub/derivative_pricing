#include "NewtonRaphson.h"
#include <cmath>
#include <iostream>
#include "BSCallTwo.h"
#include "BlackScholesFormulas.h"
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

    cout << "\nspot\n";
    cin >> Spot;

    cout << "\nEnter price\n";
    cin >> Price;

    cout << "\nr\n";
    cin >> r;

    cout << "\nd\n";
    cin >> d;

    double start;
    cout << "\nstart guess\n";
    cin >> start;

    double tolerance;

    cout << "\ntolerance\n";
    cin >> tolerance;

    BSCallTwo theCall(r,d,Expiry,Spot,Strike);
    double vol=NewtonRaphson<BSCallTwo,&BSCallTwo::Price,
           &BSCallTwo::Vega> (Price, start, tolerance, theCall);

    double PriceTwo = BlackScholesCall(Spot,Strike,r,d,vol,Expiry);

    cout << "\n vol " << vol << "\nprice two: " << PriceTwo << "\n";

    double tmp;
    cin >> tmp;

    return 0;
}
