#include <cmath>
#include "Interfaces/MoneyPossesive.h"

bool MoneyPossesive::GetTotal(uint32_t &mainunit, uint32_t &subunit) {
   mainunit = this->mainunit;
   subunit = this->subunit;
   return true;
}

uint32_t MoneyPossesive::GetMainUnit() {
    return mainunit;
}

uint32_t MoneyPossesive::GetSubUnit() {
    return subunit;
}

MoneyPossesive::MoneyPossesive(uint32_t mainunit, uint32_t subunit) {
    this->mainunit = mainunit;
    this->subunit = subunit;
}

MoneyPossesive::MoneyPossesive() {
    this->mainunit = 0;
    this->subunit = 0;
}
