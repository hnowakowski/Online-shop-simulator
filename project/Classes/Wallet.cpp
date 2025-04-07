#include "Wallet.h"

void Wallet::subtractMain(const uint32_t &amount)
{
    if (amount > mainunit) {
        mainunit = 0;
        subunit = 0;
    } else {
        mainunit -= amount;
    }
}

void Wallet::subtractSub(const uint32_t &amount)
{
    uint32_t amountInSub = mainunit * 100 + subunit;
    if (amountInSub < amount) {
        mainunit = 0;
        subunit = 0;
    } else {
        amountInSub -= amount;
        mainunit = amountInSub / 100;
        subunit = amountInSub % 100;
    }
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
