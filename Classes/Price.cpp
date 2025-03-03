#include "Price.h"
#include <cmath>

void Price::UpdatePrice(uint32_t newmainprice, uint32_t newsubprice)
{
    mainunit = newmainprice;
    subunit = newsubprice % 100;
}

void Price::UpdateMainUnit(uint32_t newmainprice) { mainunit = newmainprice; }

void Price::UpdateSubUnit(uint32_t newsubprice) { subunit = newsubprice % 100; }

Price &Price::operator=(const Price &price)
{
    if (this == &price) {
        return *this;
    }

    this->mainunit = price.mainunit;
    this->subunit = price.subunit;
    return *this;
}

Price Price::operator+(const Price &price)
{
    uint32_t newmainprice = this->mainunit + price.mainunit
                            + ((this->subunit + price.subunit) / 100);
    uint32_t newsubprice = (this->subunit + price.subunit) % 100;
    return Price(newmainprice, newsubprice);
}

Price Price::operator-(const Price &price)
{
    int newmainprice = this->mainunit - price.mainunit
                       - (abs((int) this->subunit - (int) price.subunit) / 100);
    int newsubprice = abs((int) this->subunit - (int) price.subunit) % 100;

    if (newmainprice < 0) {
        throw std::invalid_argument("Cannot subtract a larger price from a smaller price.");
    }
    return Price(newmainprice, newsubprice);
}

bool Price::operator>(const Price &price)
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

bool Price::operator<(const Price &price)
{
    if (this->mainunit < price.mainunit) {
        return true;
    } else if (this->mainunit == price.mainunit) {
        if (this->subunit < price.subunit) {
            return true;
        }
    }
    return false;
}

bool Price::operator>=(const Price &price)
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

bool Price::operator<=(const Price &price)
{
    if (this->mainunit < price.mainunit) {
        return true;
    } else if (this->mainunit == price.mainunit) {
        if (this->subunit < price.subunit) {
            return true;
        }
    }
    return false;
}

Price::Price(uint32_t mainunit, uint32_t subunit)
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

Price::Price(const nlohmann::json &json)
    : MoneyPossesive(0, 0)
{
    this->Price::fromJSON(json);
}
