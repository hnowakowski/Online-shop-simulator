#include "../../Headers/Domain/Cart.h"
#include <algorithm>

bool Cart::AddBuyable(std::shared_ptr<Buyable> buyable) {
    buyables.push_back(buyable);
    emit CartChanged();
    return true;
}

bool Cart::RemoveBuyable(std::shared_ptr<Buyable> buyable) {
    buyables.erase(std::remove(buyables.begin(), buyables.end(), buyable), buyables.end());
    emit CartChanged();
    return false;
}

uint32_t Cart::Size(){
    return buyables.size();
}

std::pair<uint32_t, uint32_t> Cart::GetTotalPrice(std::vector<std::shared_ptr<Buyable>> &unconvertable_buyables) {
    uint32_t maintotal = 0;
    uint32_t subtotal = 0;
    for (auto &buyable: buyables) {
        uint32_t mainunit;
        uint32_t subunit;
        if (buyable->GetPrice(mainunit, subunit)) {
            unconvertable_buyables.push_back(buyable);
        } else {
            maintotal += mainunit;
            subtotal += subunit;
        }
    }

    return std::make_pair(maintotal, subtotal);
}

Cart &Cart::operator=(const Cart &cart) {
    this->mainunit = cart.mainunit;
    this->subunit = cart.subunit;
    this->buyables = cart.buyables;
    return *this;
}

Cart::Cart() {
    this->mainunit = 0;
    this->subunit = 0;
    this->buyables = std::vector<std::shared_ptr<Buyable>>();
}

Cart::Cart(std::vector<std::shared_ptr<Buyable>> & buyables){
    this->mainunit = 0;
    this->subunit = 0;
    this->buyables = buyables;
}
