#ifndef OOP_PROJECT_CART_H
#define OOP_PROJECT_CART_H

#include <QObject>
#include <memory>
#include <vector>

#include "../Abstracts/Buyable.h"
#include "CartItem.h"
#include "Price.h"

class Cart : public QObject
{
    Q_OBJECT

    std::shared_ptr<std::vector<std::shared_ptr<CartItem>>> items;
    uint32_t currId;

public:
    bool addBuyable(std::shared_ptr<Buyable> buyable);
    bool removeBuyable(std::shared_ptr<Buyable> buyable);
    bool removeBuyable(const uint32_t &id);
    bool hasBuyable(const std::shared_ptr<Buyable> &buyable) const;
    bool hasItemId(const uint32_t &id) const;
    uint32_t size() const;
    std::shared_ptr<Price> getTotalPrice() const;
    std::shared_ptr<std::vector<std::shared_ptr<CartItem>>> &getItems();

    Cart();
    Cart(std::shared_ptr<std::vector<std::shared_ptr<CartItem>>> &items);

signals:
    void cartChanged();
};

#endif // OOP_PROJECT_CART_H
