//
// Created by pawel on 29/11/2024.
//

#include <cmath>
#include "Headers/Interfaces/MoneyPossesive.h"

bool MoneyPossesive::GetTotal(uint32_t &mainunit, uint32_t &subunit) {
   mainunit = this->mainunit;
   subunit = this->subunit;
   return true;
}

bool MoneyPossesive::GetTotal(uint32_t &mainunit, uint32_t &subunit, Currency & new_currency) {
    if(new_currency == this->currency) {
        mainunit = this->mainunit;
        subunit = this->subunit;
        return true;
    }

    uint32_t mainunitcopy = this->mainunit;
    uint32_t subunitcopy = this->subunit;

    if(this->GetConvertedTotal(mainunitcopy, subunitcopy, new_currency)) {
        mainunit = mainunitcopy;
        subunit = subunitcopy;
        return true;
    }
    return false;
}

uint32_t MoneyPossesive::GetMainUnit() {
    return mainunit;
}

uint32_t MoneyPossesive::GetSubUnit() {
    return subunit;
}

bool MoneyPossesive::ChangeCurrency(Currency & new_currency) {
    if(this->GetConvertedTotal(mainunit, subunit, new_currency)){
        this->currency = new_currency;
        return true;
    }
    return false;
}

MoneyPossesive::MoneyPossesive(Currency &currency, uint32_t mainunit, uint32_t subunit) : currency(currency) {
    this->currency = currency;
    this->mainunit = mainunit;
    this->subunit = subunit;
}

bool MoneyPossesive::GetConvertedTotal(uint32_t &mainunit, uint32_t &subunit, Currency &new_currency) {
    float exchange_rate;
    if(!new_currency.GetExchangeRate(this->currency.GetCode(), exchange_rate)) {
        return false;
    }

    mainunit = (uint32_t) std::round( mainunit * exchange_rate);
    subunit = (uint32_t) std::round(subunit * exchange_rate);

    mainunit = mainunit + subunit / new_currency.GetSubsIsMain();
    subunit = subunit % new_currency.GetSubsIsMain();
    return true;
}

MoneyPossesive::MoneyPossesive(Currency &currency) : currency(currency) {
    this->currency = currency;
    this->mainunit = 0;
    this->subunit = 0;
}
