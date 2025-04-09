#include "Wallet.h"

void Wallet::subtractMain(const uint32_t &amount)
{
    units = (amount * 100) > units ? 0 : (units - (amount * 100));
}

void Wallet::subtractSub(const uint32_t &amount)
{
    units = amount > units ? 0 : (units - amount);
}

Wallet &Wallet::operator=(const Wallet &other)
{
    if (this == &other) {
        return *this;
    }

    units = other.units;
    return *this;
}

Wallet::Wallet(uint32_t mainunit, uint32_t subunit)
    : MoneyPossesive(mainunit, subunit)
{}

nlohmann::json Wallet::toJSON() const
{
    return nlohmann::json{{"units", units}};
}

void Wallet::fromJSON(const nlohmann::json &json)
{
    units = json.at("units").get<uint32_t>();
}

Wallet::Wallet(const nlohmann::json &json)
{
    this->Wallet::fromJSON(json);
}
