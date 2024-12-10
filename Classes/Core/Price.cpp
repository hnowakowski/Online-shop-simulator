#include "../../Headers/Core/Price.h"


void Price::UpdatePrice(uint32_t newmainprice, uint32_t newsubprice) {
    mainunit = newmainprice + newsubprice / currency->GetSubsIsMain();
    subunit = newsubprice % currency->GetSubsIsMain();
}

void Price::UpdateMainUnit(uint32_t newmainprice) {
    mainunit = newmainprice;
}

void Price::UpdateSubUnit(uint32_t newsubprice) {
    subunit = newsubprice;
}

Price& Price::operator=(const Price &price) {
    if(this == &price) {
        return *this;
    }

    this->currency = price.currency;
    this->mainunit = price.mainunit;
    this->subunit = price.subunit;
    return *this;
}

Price::Price(std::shared_ptr<Currency> &currency, uint32_t mainunit, uint32_t subunit) : MoneyPossesive(currency, mainunit, subunit) {
    this->currency = currency;
    this->mainunit = mainunit;
    this->subunit = subunit;
}

nlohmann::json Price::toJSON() const {
    return nlohmann::json{
            {"currency", currency->toJSON()},
            {"mainunit", mainunit},
            {"subunit", subunit}
    };
}

void Price::fromJSON(const nlohmann::json &json) {
    currency->fromJSON(json.at("currency"));
    mainunit = json.at("mainunit").get<uint32_t>();
    subunit = json.at("subunit").get<uint32_t>();
}
