#include "Price.h"
#include <cmath>

void Price::updatePrice(const uint32_t& mainunit, const uint32_t& subunit)
{
    this->mainunit = mainunit;
    this->subunit = subunit % 100;
}

void Price::addPrice(const Price& other)
{
    addMainUnit(other.mainunit);
    addSubUnit(other.subunit);
}

Price::Price()
    : MoneyPossesive() {};

Price::Price(const uint32_t& mainunit, const uint32_t& subunit)
    : MoneyPossesive(mainunit, subunit)
{
    this->mainunit = mainunit;
    this->subunit = subunit;
}

nlohmann::json Price::toJSON() const
{
    return nlohmann::json{{"mainunit", mainunit}, {"subunit", subunit}};
}

void Price::fromJSON(const nlohmann::json &json)
{
    mainunit = json.at("mainunit").get<uint32_t>();
    subunit = json.at("subunit").get<uint32_t>();
}

Price::Price(const nlohmann::json& json)
    : MoneyPossesive(0, 0)
{
    this->Price::fromJSON(json);
}
