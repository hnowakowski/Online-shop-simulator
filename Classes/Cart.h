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
    bool AddBuyable(std::shared_ptr<Buyable> buyable);
    bool RemoveBuyable(std::shared_ptr<Buyable> buyable);
    uint32_t Size();
    std::pair<uint32_t, uint32_t> GetTotalPrice();
    std::vector<std::shared_ptr<Buyable>> &GetBuyables();
    Cart &operator=(const Cart &cart);

    Cart();
    Cart(std::vector<std::shared_ptr<Buyable>> &buyables);

signals:
    void CartChanged();
};

#endif // OOP_PROJECT_CART_H
