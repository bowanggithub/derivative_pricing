#include "BinomialTree.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include <BlackScholesFormulas.h>
#include "PayOffForward.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ...;
    PayOffCall thePayOff(Strike);

    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    TreeEuropean europeanOption(Expiry,thePayOff);
    TreeAmerican americanOption(Expiry,thePayOff);

    SimpleBinomialTree theTree(Spot,rParam,dParam,Vol,Steps,Expiry);
    double euroPrice = theTree.GetThePrice(europeanOption);
    double americanPrice = theTree.GetThePrice(americanOption);
    cout << "euro price" << euroPrice << "amer price" << americanPrice << "\n";

    double BSPrice=BlackScholesCall(Spot,Strike,r,d,Vol,Expiry);
    cout << "BS formula euro price" << BSPrice << "\n";
    PayOffForward forwardPayOff(Strike);
    TreeEuropean forward(Expiry, forwardPayOff);

    double forwardPrice = theTree.GetThePrice(forward);
    cout << "forward price by tree" << forwardPrice << "\n";

    double actualForwardPrice = exp(-r*Expiry)*(Spot*exp((r-d)*Expiry)-Strike);
    cout << "forward price " << actualForwardPrice << "\n";

    Steps++;
