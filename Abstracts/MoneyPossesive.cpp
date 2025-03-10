#include <cmath>

#include "MoneyPossesive.h"

uint32_t MoneyPossesive::getMainUnit() { return mainunit; }

uint32_t MoneyPossesive::getSubUnit() { return subunit; }

void MoneyPossesive::setMainUnit(const uint32_t &amount)
{
    this->mainunit = amount;
}

void MoneyPossesive::setSubUnit(const uint32_t &amount)
{
    this->subunit = amount % 100;
}

void MoneyPossesive::addMainUnit(const uint32_t& amount)
{
    mainunit += amount;
}

void MoneyPossesive::addSubUnit(const uint32_t& amount)
{
    subunit += amount % 100;
    mainunit += amount / 100;
}

MoneyPossesive::MoneyPossesive(const uint32_t &mainunit, const uint32_t &subunit)
{
    this->mainunit = mainunit;
    this->subunit = subunit;
}

MoneyPossesive::MoneyPossesive()
{
    this->mainunit = 0;
    this->subunit = 0;
}

bool MoneyPossesive::operator>(const MoneyPossesive &other) const
{
    if (this->mainunit > other.mainunit) {
        return true;
    } else if (this->mainunit == other.mainunit) {
        if (this->subunit > other.subunit) {
            return true;
        }
    }
    return false;
}

bool MoneyPossesive::operator>=(const MoneyPossesive &other) const
{
    if (this->mainunit > other.mainunit) {
        return true;
    } else if (this->mainunit == other.mainunit) {
        if (this->subunit > other.subunit || this->subunit == other.subunit) {
            return true;
        }
    }
    return false;
}
