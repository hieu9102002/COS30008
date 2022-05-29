#define _USE_MATH_DEFINES
#include "Inductor.h"
#include <cmath>

bool Inductor::mustScale(double aValue) const
{
    return aValue<1.0;
}

const double Inductor::getMultiplier() const
{
    return 1000.0;
}

const std::string Inductor::getMajorUnit() const
{
    return "H";
}

const std::string Inductor::getMinorUnits() const
{
    return "Hmunp";
}

Inductor::Inductor(double aBaseValue) : ResistorBase(aBaseValue)
{
}

double Inductor::getReactance(double aFrequency) const
{
    return 2*M_PI*getBaseValue()*aFrequency;
}
