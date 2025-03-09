#ifndef OOP_PROJECT_CART_H
#define OOP_PROJECT_CART_H

#include <QObject>
#include <memory>
#include <vector>

#include "Product.h"

class Cart : public QObject, public MoneyPossesive
{
    Q_OBJECT

    std::vector<std::shared_ptr<Buyable>> buyables;

public:
    bool addBuyable(std::shared_ptr<Buyable> buyable);
    bool removeBuyable(std::shared_ptr<Buyable> buyable);
    uint32_t size();
    Price getTotalPrice();
    std::vector<std::shared_ptr<Buyable>> &getBuyables();
    Cart &operator=(const Cart &cart);

    Cart();
    Cart(std::vector<std::shared_ptr<Buyable>> &buyables);

signals:
    void cartChanged();
};

#endif // OOP_PROJECT_CART_H
