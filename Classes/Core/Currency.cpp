//
// Created by pawel on 24/11/2024.
//

#include "Headers/Core/Currency.h"
#include "stdexcept"

std::string Currency::GetName() {
    return name;
}

std::string Currency::GetCode() {
    return code;
}

std::string Currency::GetSymbol() {
    return symbol;
}

bool Currency::SetExchangeRate(std::string code, float rate) {
    if(code != this->code) {
        exchange_rates[code] = rate;
        return true;
    }
    return false;
}

bool Currency::GetExchangeRate(std::string code, float & rate) {
if(exchange_rates.count(code) != 0){
        rate = exchange_rates[code];
        return true;
    }
    return false;
}

uint32_t Currency::GetSubsIsMain() {
    return subs_is_main;
}

Currency::Currency(std::string name, std::string code, std::string symbol, uint32_t subs_is_main,
                   std::map<std::string, float> exchange_rates) {
    this->name = name;
    this->code = code;
    this->symbol = symbol;
    this->subs_is_main = subs_is_main;
    this->exchange_rates = exchange_rates;
}

bool Currency::operator==(const Currency &other_currency) {
    if(this->code == other_currency.code && this->name == other_currency.name && this->symbol == other_currency.symbol && this->subs_is_main == other_currency.subs_is_main && this->exchange_rates == other_currency.exchange_rates) {
        return true;
    }
    return false;
}
