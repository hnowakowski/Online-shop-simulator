#ifndef OOP_PROJECT_STORESYSTEM_H
#define OOP_PROJECT_STORESYSTEM_H

#include "../Enums/BuyableDisplayedType.h"
#include "../Enums/BuyableSortedBy.h"
#include "Cart.h"
#include "Customer.h"
#include <memory>

class StoreSystem
{
    std::vector<std::shared_ptr<Buyable>> buyables;
    std::vector<std::shared_ptr<Customer>> customers;

    Cart cart;

    BuyableDisplayedType buyableDisplayedType;
    BuyableSortedBy buyableSortedBy;

    std::string buyableSearchQuery;
    std::string currentCustomerId;

    StoreSystem() = default;

    StoreSystem(StoreSystem &other) = delete;

    StoreSystem &operator=(StoreSystem &other) = delete;

public:
    std::shared_ptr<Buyable> GetBuyable(const std::string &id);
    std::shared_ptr<Customer> GetCustomer(const std::string &id);

    bool AddBuyable(std::shared_ptr<Buyable> &buyable);
    bool AddCustomer(std::shared_ptr<Customer> &customer);

    std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> GetBuyables();
    std::shared_ptr<std::vector<std::shared_ptr<Customer>>> GetCustomers();

    void SetBuyableDisplayedType(const BuyableDisplayedType &buyableDisplayedType);
    void SetBuyableSortedBy(const BuyableSortedBy &buyableSortedBy);

    BuyableDisplayedType GetBuyableDisplayedType();
    BuyableSortedBy GetBuyableSortedBy();

    void SetBuyableSearchQuery(const std::string &query);
    std::string GetBuyableSearchQuery();

    void SetCurrentCustomerId(const std::string &id);
    std::string GetCurrentCustomerId();

    std::shared_ptr<Customer> GetCurrentCustomer();

    Cart &GetCart();

    bool RemoveBuyable(const std::string &id);
    bool RemoveCustomer(const std::string &id);

    void SortBuyables(const std::function<bool(const Buyable &, const Buyable &)> &comparator);

    static StoreSystem &GetInstance()
    {
        static StoreSystem instance;
        return instance;
    }
};

#endif // OOP_PROJECT_STORESYSTEM_H
