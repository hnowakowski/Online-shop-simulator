#include "Price.h"
#include <cmath>

void Price::updatePrice(const uint32_t& mainunit, const uint32_t& subunit)
{
    units = (mainunit * 100) + (subunit % 100);
}

void Price::addPrice(const Price& other)
{
    units += other.units;
}

Price::Price()
    : MoneyPossesive() {};

Price::Price(const uint32_t& mainunit, const uint32_t& subunit)
    : MoneyPossesive(mainunit, subunit)
{}

nlohmann::json Price::toJSON() const
{
    return nlohmann::json{{"units", units}};
}

void Price::fromJSON(const nlohmann::json &json)
{
    units = json.at("units").get<uint32_t>();
}

Price::Price(const nlohmann::json& json)
    : MoneyPossesive(0, 0)
{
    this->Price::fromJSON(json);
}
