#include <cmath>

#include "MoneyPossesive.h"

uint32_t MoneyPossesive::getMainUnit() { return mainunit; }

uint32_t MoneyPossesive::getSubUnit() { return subunit; }

void MoneyPossesive::addMainUnit(const uint32_t& amount)
{
    mainunit += amount;
}

void MoneyPossesive::addSubUnit(const uint32_t& amount)
{
    subunit += amount % 100;
    mainunit += amount / 100;
}

MoneyPossesive::MoneyPossesive(uint32_t mainunit, uint32_t subunit)
{
    this->mainunit = mainunit;
    this->subunit = subunit;
}

MoneyPossesive::MoneyPossesive()
{
    this->mainunit = 0;
    this->subunit = 0;
}

bool MoneyPossesive::operator>=(const MoneyPossesive &price)
{
    if (this->mainunit > price.mainunit) {
        return true;
    } else if (this->mainunit == price.mainunit) {
        if (this->subunit > price.subunit) {
            return true;
        }
    }
    return false;
}
