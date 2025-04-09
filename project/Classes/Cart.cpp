#include "Cart.h"

bool Cart::addBuyable(std::shared_ptr<Buyable> buyable)
{
    std::shared_ptr<CartItem> item = std::make_shared<CartItem>(CartItem(buyable, currId));
    items->push_back(item);
    currId++;
    emit cartChanged();
    return true;
}

bool Cart::removeBuyable(std::shared_ptr<Buyable> buyable)
{
    for (int32_t i = items->size() - 1; i >= 0; i--) {
        if (items->at(i)->getBuyable() == buyable) {
            items->erase(items->begin() + i);
            emit cartChanged();
            return true;
        }
    }
    return false;
}

bool Cart::removeBuyable(const uint32_t &id)
{
    for (int32_t i = items->size() - 1; i >= 0; i--) {
        if (items->at(i)->getId() == id) {
            items->erase(items->begin() + i);
            emit cartChanged();
            return true;
        }
    }
    return false;
}

bool Cart::hasBuyable(const std::shared_ptr<Buyable> &buyable) const
{
    for (auto &item : *items) {
        if (item->getBuyable() == buyable) {
            return true;
        }
    }
    return false;
}

bool Cart::hasItemId(const uint32_t &id) const
{
    for (auto &item : *items) {
        if (item->getId() == id) {
            return true;
        }
    }
    return false;
}

uint32_t Cart::size() const
{
    return items->size();
}

std::shared_ptr<Price> Cart::getTotalPrice() const
{
    std::shared_ptr<Price> totalPrice = std::make_shared<Price>();
    for (auto &item : *items) {
        std::shared_ptr<Price> bPrice = item->getBuyable()->getPrice();
        totalPrice->addPrice(*bPrice);
    }
    return totalPrice;
}

std::shared_ptr<std::vector<std::shared_ptr<CartItem>>> &Cart::getItems()
{
    return items;
}

Cart::Cart()
{
    this->items = std::make_shared<std::vector<std::shared_ptr<CartItem>>>();
}

Cart::Cart(std::shared_ptr<std::vector<std::shared_ptr<CartItem>>> &items)
    : items(items)
    , currId(0)
{}
