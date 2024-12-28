#include <algorithm>

#include "Cart.h"

bool Cart::AddBuyable(std::shared_ptr<Buyable> buyable)
{
    buyables.push_back(buyable);
    emit CartChanged();
    return true;
}

bool Cart::RemoveBuyable(std::shared_ptr<Buyable> buyable)
{
    buyables.erase(std::remove(buyables.begin(), buyables.end(), buyable), buyables.end());
    emit CartChanged();
    return false;
}

uint32_t Cart::Size() { return buyables.size(); }

std::pair<uint32_t, uint32_t> Cart::GetTotalPrice()
{
    uint32_t maintotal = 0;
    uint32_t subtotal  = 0;
    for (auto& buyable : buyables)
    {
        uint32_t mainunit;
        uint32_t subunit;
        buyable->GetPrice(mainunit, subunit);
        maintotal += mainunit;
        subtotal  += subunit;
    }
    while(subtotal > 99){
        maintotal += (subtotal / 100);
        subtotal %= 100;
    }

    return std::make_pair(maintotal, subtotal);
}

std::vector<std::shared_ptr<Buyable>> Cart::GetBuyables()
{
    return buyables;
}

Cart& Cart::operator=(const Cart& cart)
{
    this->mainunit = cart.mainunit;
    this->subunit  = cart.subunit;
    this->buyables = cart.buyables;
    return *this;
}

Cart::Cart()
{
    this->mainunit = 0;
    this->subunit  = 0;
    this->buyables = std::vector<std::shared_ptr<Buyable>>();
}

Cart::Cart(std::vector<std::shared_ptr<Buyable>>& buyables)
{
    this->mainunit = 0;
    this->subunit  = 0;
    this->buyables = buyables;
}
