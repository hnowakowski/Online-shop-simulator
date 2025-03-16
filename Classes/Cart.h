#ifndef OOP_PROJECT_CART_H
#define OOP_PROJECT_CART_H

#include <QObject>
#include <memory>
#include <vector>

#include "../Abstracts/Buyable.h"
#include "Price.h"

class Cart : public QObject
{
    Q_OBJECT

    std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> buyables;

public:
    bool addBuyable(std::shared_ptr<Buyable> buyable);
    bool removeBuyable(std::shared_ptr<Buyable> buyable);
    uint32_t size() const;
    std::shared_ptr<Price> getTotalPrice() const;
    std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> &getBuyables();

    Cart();
    Cart(std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> &buyables);

signals:
    void cartChanged();
};

#endif // OOP_PROJECT_CART_H
