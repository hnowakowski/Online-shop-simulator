#include <algorithm>

#include "Cart.h"

bool Cart::addBuyable(std::shared_ptr<Buyable> buyable)
{
    buyables.push_back(buyable);
    emit cartChanged();
    return true;
}

bool Cart::removeBuyable(std::shared_ptr<Buyable> buyable)
{
    auto it = std::find_if(buyables.begin(),
                           buyables.end(),
                           [&buyable](const std::shared_ptr<Buyable> &item) {
                               return item == buyable;
                           });

    if (it != buyables.end()) {
        buyables.erase(it);
        emit cartChanged();
        return true;
    }
    return false;
}

uint32_t Cart::size()
{
    return buyables.size();
}

Price Cart::getTotalPrice()
{
    Price totalPrice;
    for (auto &buyable : buyables) {
        Price bPrice = buyable->getPrice();
        totalPrice.addPrice(bPrice);
    }

    return totalPrice;
}

std::vector<std::shared_ptr<Buyable>> &Cart::getBuyables()
{
    return buyables;
}

Cart &Cart::operator=(const Cart &cart)
{
    this->mainunit = cart.mainunit;
    this->subunit = cart.subunit;
    this->buyables = cart.buyables;
    return *this;
}

Cart::Cart()
{
    this->mainunit = 0;
    this->subunit = 0;
    this->buyables = std::vector<std::shared_ptr<Buyable>>();
}

Cart::Cart(std::vector<std::shared_ptr<Buyable>> &buyables)
{
    this->mainunit = 0;
    this->subunit = 0;
    this->buyables = buyables;
}
