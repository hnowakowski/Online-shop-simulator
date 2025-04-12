#include <cmath>

#include "MoneyPossesive.h"

uint32_t MoneyPossesive::getMainUnit()
{
    return units / 100;
}

uint32_t MoneyPossesive::getSubUnit()
{
    return units % 100;
}

void MoneyPossesive::setMainUnit(const uint32_t &amount)
{
    units = amount * 100;
}

void MoneyPossesive::setSubUnit(const uint32_t &amount)
{
    units = (units / 100) * 100 + amount % 100;
}

void MoneyPossesive::addMainUnit(const uint32_t &amount)
{
    units += amount * 100;
}

void MoneyPossesive::addSubUnit(const uint32_t &amount)
{
    units += amount;
}

MoneyPossesive::MoneyPossesive(const uint32_t &mainunit, const uint32_t &subunit)
{
    units = mainunit * 100 + subunit;
}

MoneyPossesive::MoneyPossesive(const uint32_t &units)
{
    this->units = units;
}

MoneyPossesive::MoneyPossesive()
{
    units = 0;
}

bool MoneyPossesive::operator==(const MoneyPossesive &other) const
{
    return units == other.units;
}

bool MoneyPossesive::operator<(const MoneyPossesive &other) const
{
    return units < other.units;
}

bool MoneyPossesive::operator>=(const MoneyPossesive &other) const
{
    return units >= other.units;
}
