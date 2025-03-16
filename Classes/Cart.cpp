#include <algorithm>

#include "Cart.h"

bool Cart::addBuyable(std::shared_ptr<Buyable> buyable)
{
    buyables->push_back(buyable);
    emit cartChanged();
    return true;
}

bool Cart::removeBuyable(std::shared_ptr<Buyable> buyable)
{
    auto it = std::find_if(buyables->begin(),
                           buyables->end(),
                           [&buyable](const std::shared_ptr<Buyable> &item) {
                               return item == buyable;
                           });

    if (it != buyables->end()) {
        buyables->erase(it);
        emit cartChanged();
        return true;
    }
    return false;
}

uint32_t Cart::size() const
{
    return buyables->size();
}

std::shared_ptr<Price> Cart::getTotalPrice() const
{
    std::shared_ptr<Price> totalPrice = std::make_shared<Price>();
    for (auto &buyable : *buyables) {
        std::shared_ptr<Price> bPrice = buyable->getPrice();
        totalPrice->addPrice(*bPrice);
    }

    return totalPrice;
}

std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> &Cart::getBuyables()
{
    return buyables;
}

Cart::Cart()
{
    this->buyables = std::make_shared<std::vector<std::shared_ptr<Buyable>>>();
}

Cart::Cart(std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> &buyables)
{
    this->buyables = buyables;
}
