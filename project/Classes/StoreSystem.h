#ifndef OOP_PROJECT_STORESYSTEM_H
#define OOP_PROJECT_STORESYSTEM_H

#include "../Enums/BuyableDisplayedType.h"
#include "../Enums/BuyableSortedBy.h"
#include "Cart.h"
#include "Customer.h"
#include <memory>

#define PATH (std::filesystem::current_path().string() + "\\..\\..\\..\\project\\")

class StoreSystem
{
    std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> buyables;
    std::shared_ptr<std::vector<std::shared_ptr<Customer>>> customers;

    Cart cart;

    BuyableDisplayedType buyableDisplayedType;
    BuyableSortedBy buyableSortedBy;

    std::string buyableSearchQuery;
    std::string currentCustomerId;

    StoreSystem();

    StoreSystem(StoreSystem &other) = delete;

    StoreSystem &operator=(StoreSystem &other) = delete;

public:
    std::shared_ptr<Buyable> getBuyable(const std::string &id);
    std::shared_ptr<Customer> getCustomer(const std::string &id);

    bool addBuyable(std::shared_ptr<Buyable> &buyable);
    bool addCustomer(std::shared_ptr<Customer> &customer);

    std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> getBuyables();
    std::shared_ptr<std::vector<std::shared_ptr<Customer>>> getCustomers();

    void setBuyableDisplayedType(const BuyableDisplayedType &buyableDisplayedType);
    void setBuyableSortedBy(const BuyableSortedBy &buyableSortedBy);

    BuyableDisplayedType getBuyableDisplayedType() const;
    BuyableSortedBy getBuyableSortedBy() const;

    void setBuyableSearchQuery(const std::string &query);
    std::string getBuyableSearchQuery() const;

    void setCurrentCustomerId(const std::string &id);
    std::string getCurrentCustomerId() const;

    std::shared_ptr<Customer> getCurrentCustomer();

    Cart &getCart();

    bool removeBuyable(const std::string &id);
    bool removeCustomer(const std::string &id);

    void sortBuyables(const std::function<bool(const std::shared_ptr<Buyable> &,
                                               const std::shared_ptr<Buyable> &)> &comparator);

    static StoreSystem &getInstance()
    {
        static StoreSystem instance;
        return instance;
    }
};

#endif // OOP_PROJECT_STORESYSTEM_H
