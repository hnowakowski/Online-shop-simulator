#include "Price.h"

void Price::UpdatePrice(uint32_t newmainprice, uint32_t newsubprice)
{
    mainunit = newmainprice;
    subunit  = newsubprice;
    mainunit += subunit / 100;
    subunit %= 100;
}

void Price::UpdateMainUnit(uint32_t newmainprice) { mainunit = newmainprice; }

void Price::UpdateSubUnit(uint32_t newsubprice)
{
    mainunit += newsubprice / 100;
    subunit = newsubprice % 100;
}

Price& Price::operator=(const Price& price)
{
    if (this == &price)
    {
        return *this;
    }

    this->mainunit = price.mainunit;
    this->subunit  = price.subunit;
    return *this;
}

Price::Price(uint32_t mainunit, uint32_t subunit) : MoneyPossesive(mainunit, subunit)
{
    this->mainunit = mainunit;
    this->subunit  = subunit;
}

nlohmann::json Price::toJSON() const { return nlohmann::json {{"mainunit", mainunit}, {"subunit", subunit}}; }

void Price::fromJSON(const nlohmann::json& json)
{
    mainunit = json.at("mainunit").get<uint32_t>();
    subunit  = json.at("subunit").get<uint32_t>();
}

Price::Price(const nlohmann::json& json) : MoneyPossesive(0, 0) { this->Price::fromJSON(json); }
