//
// Created by pawel on 29/11/2024.
//

#include "Headers/Domain/Cart.h"
#include <algorithm>

bool Cart::AddBuyable(std::shared_ptr<Buyable> buyable) {
    buyables.push_back(buyable);
    return true;
}

bool Cart::RemoveBuyable(std::shared_ptr<Buyable> buyable) {
    buyables.erase(std::remove(buyables.begin(), buyables.end(), buyable), buyables.end());
    return false;
}

std::pair<uint32_t, uint32_t> Cart::GetTotalPrice(std::vector<std::shared_ptr<Buyable>> &unconvertable_buyables) {
    uint32_t maintotal = 0;
    uint32_t subtotal = 0;
    for (auto &buyable: buyables) {
        uint32_t mainunit;
        uint32_t subunit;
        if (buyable->GetPrice(mainunit, subunit, this->currency)) {
            unconvertable_buyables.push_back(buyable);
        } else {
            maintotal += mainunit;
            subtotal += subunit;
        }
    }

    return std::make_pair(maintotal, subtotal);
}

Cart &Cart::operator=(const Cart &cart) {
    this->currency = cart.currency;
    this->mainunit = cart.mainunit;
    this->subunit = cart.subunit;
    this->buyables = cart.buyables;
    return *this;
}

Cart::Cart(Currency &currency) : MoneyPossesive(currency) {
    this->currency = currency;
    this->mainunit = 0;
    this->subunit = 0;
    this->buyables = std::vector<std::shared_ptr<Buyable>>();
}

Cart::Cart(Currency &currency, std::vector<std::shared_ptr<Buyable>> & buyables) : MoneyPossesive(currency) {
    this->currency = currency;
    this->mainunit = 0;
    this->subunit = 0;
    this->buyables = buyables;
}
