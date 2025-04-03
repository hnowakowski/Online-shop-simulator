#ifndef CARTITEM_H
#define CARTITEM_H
#include "../Abstracts/Buyable.h"

class CartItem
{
    std::shared_ptr<Buyable> buyable;
    uint32_t id;

public:
    std::shared_ptr<Buyable> getBuyable();
    uint32_t getId() const;

    CartItem();
    CartItem(std::shared_ptr<Buyable> &, uint32_t id);
};

#endif // CARTITEM_H
