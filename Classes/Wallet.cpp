#include "Wallet.h"

void Wallet::AddMain(uint32_t amount) { mainunit += amount; }

void Wallet::AddSub(uint32_t amount)
{
    subunit += amount % 100;
    mainunit += amount / 100;
}

void Wallet::RemoveMain(uint32_t amount) { mainunit -= amount; }

void Wallet::RemoveSub(uint32_t amount)
{
    mainunit -= amount / 100;
    subunit = (amount % 100) > subunit ? (subunit + 100) - (amount % 100)
                                       : subunit - (amount % 100);
}

Wallet &Wallet::operator=(const Wallet &other)
{
    if (this == &other) {
        return *this;
    }

    this->mainunit = other.mainunit;
    this->subunit = other.subunit;

    return *this;
}

Wallet::Wallet(uint32_t mainunit, uint32_t subunit)
    : MoneyPossesive(mainunit, subunit)
{
    this->mainunit = mainunit;
    this->subunit = subunit;
}

nlohmann::json Wallet::toJSON() const
{
    return nlohmann::json{{"mainunit", mainunit}, {"subunit", subunit}};
}

void Wallet::fromJSON(const nlohmann::json &json)
{
    mainunit = json.at("mainunit").get<uint32_t>();
    subunit = json.at("subunit").get<uint32_t>();
}

Wallet::Wallet(const nlohmann::json &json)
{
    this->Wallet::fromJSON(json);
}
