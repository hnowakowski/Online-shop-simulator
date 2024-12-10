#include "../../Headers/Domain/Wallet.h"

void Wallet::AddMain(uint32_t amount) {
    mainunit += amount;
}

void Wallet::AddSub(uint32_t amount) {
    mainunit += amount / currency->GetSubsIsMain();
    subunit += amount % currency->GetSubsIsMain();
}

void Wallet::RemoveMain(uint32_t amount) {
    mainunit -= amount;
}

void Wallet::RemoveSub(uint32_t amount) {
    mainunit -= amount / currency->GetSubsIsMain();
    subunit -= amount % currency->GetSubsIsMain();
}

Wallet &Wallet::operator=(const Wallet &other) {
    if (this == &other) {
        return *this;
    }

    this->currency = other.currency;
    this->mainunit = other.mainunit;
    this->subunit = other.subunit;

    return *this;

}

Wallet::Wallet(std::shared_ptr<Currency> &currency, uint32_t mainunit, uint32_t subunit) : MoneyPossesive(currency, mainunit, subunit) {
    this->currency = currency;
    this->mainunit = mainunit;
    this->subunit = subunit;
}



