#ifndef OOP_PROJECT_CART_H
#define OOP_PROJECT_CART_H


#include <vector>
#include "../Core/Product.h"
#include <memory>

class Cart : virtual public MoneyPossesive {
private:
    std::vector<std::shared_ptr<Buyable>> buyables;
public:
    bool AddBuyable(std::shared_ptr<Buyable> buyable);
    bool RemoveBuyable(std::shared_ptr<Buyable> buyable);
    std::pair<uint32_t, uint32_t> GetTotalPrice(std::vector<std::shared_ptr<Buyable>> &unconvertable_buyables);
    Cart& operator=(const Cart &cart);

    Cart(Currency & currency);
    Cart(Currency & currency, std::vector<std::shared_ptr<Buyable>> & buyables);
};


#endif //OOP_PROJECT_CART_H
