#include "../../Headers/Core/Currency.h"
#include "stdexcept"
#include "Headers/System/StoreSystem.h"

std::string Currency::GetName() {
    return name;
}

std::string Currency::GetCode() {
    return code;
}

std::string Currency::GetSymbol() {
    return symbol;
}

bool Currency::SetExchangeRate(std::string code, float & rate) {
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

Currency &Currency::operator=(const Currency &currency) {
    if(this == &currency) {
        return *this;
    }

    this->name = currency.name;
    this->code = currency.code;
    this->symbol = currency.symbol;
    this->subs_is_main = currency.subs_is_main;
    this->exchange_rates = currency.exchange_rates;
    return *this;
}

nlohmann::json Currency::toJSON() const {
    return nlohmann::json{
            {"code", code}
    };
}

void Currency::fromJSON(const nlohmann::json &json) {
    code = json.at("code").get<std::string>();
    std::shared_ptr<Currency> c;
    bool found = StoreSystem::GetInstance().GetCurrency(code, c);
    if(found) {
        *this = *c;
    }
    else {
        throw std::invalid_argument("Currency not found");
    }
}

Currency::Currency(const nlohmann::json &json) {
    this->Currency::fromJSON(json);
}
