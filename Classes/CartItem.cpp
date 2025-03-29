#include "CartItem.h"

uint32_t CartItem::getId() const
{
    return id;
}
std::shared_ptr<Buyable> CartItem::getBuyable()
{
    return buyable;
}

CartItem::CartItem()
    : buyable(nullptr)
    , id(-1)
{}

CartItem::CartItem(std::shared_ptr<Buyable> &buyable, uint32_t id)
    : buyable(buyable)
    , id(id)
{}
