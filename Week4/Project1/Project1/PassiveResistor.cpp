#include "PassiveResistor.h"

bool PassiveResistor::mustScale(double aValue) const
{
    return aValue >= 1000.0;
}

const double PassiveResistor::getMultiplier() const
{
    return 1.0/1000.0;
}

const std::string PassiveResistor::getMajorUnit() const
{
    return "Ohm";
}

const std::string PassiveResistor::getMinorUnits() const
{
    return "OkM";
}

PassiveResistor::PassiveResistor(double aBaseValue)
{
    setBaseValue(aBaseValue);
}

double PassiveResistor::getReactance(double aFrequency) const
{
    return getBaseValue();
}
