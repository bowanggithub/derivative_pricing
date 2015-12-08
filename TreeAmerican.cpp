#include "TreeAmerican.h"
#include "minmax.h"

TreeAmerican::TreeAmerican(double FinalTime, const PayOffBridge& ThePayOff_)
    : TreeProduct(FinalTime), ThePayOff(ThePayOff_) {}

TreeProduct* TreeAmerican::clone() const
{
    return new TreeAmerican(*this);
}

double TreeAmerican::FinalPayOff(double SPot) const
{
    return ThePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double,
        double DiscountedFutureValue) const
{
    return max(ThePayOff(Spot), DiscountedFutureValue);
}

