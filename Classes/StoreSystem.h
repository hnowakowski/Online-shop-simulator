#ifndef OOP_PROJECT_STORESYSTEM_H
#define OOP_PROJECT_STORESYSTEM_H

#include "../Enums/BuyableDisplayedType.h"
#include "../Enums/BuyableSortedBy.h"
#include "../Templates/Listing.h"
#include "Cart.h"
#include "Order.h"

class StoreSystem
{
    Listing<std::shared_ptr<Buyable>>  buyables;
    Listing<std::shared_ptr<Customer>> customers;
    Listing<std::shared_ptr<Order>>    orders;

    Cart cart;

    BuyableDisplayedType buyableDisplayedType;
    BuyableSortedBy      buyableSortedBy;

    std::string buyableSearchQuery;
    std::string currentCustomerId;

    StoreSystem() = default;

    StoreSystem(StoreSystem& other) = delete;

    StoreSystem& operator=(StoreSystem& other) = delete;

  public:
    bool GetBuyable(const std::string& id, std::shared_ptr<Buyable>& buyable);
    bool GetCustomer(const std::string& id, std::shared_ptr<Customer>& customer);
    bool GetOrder(const std::string& id, std::shared_ptr<Order>& order);

    void AddBuyable(std::shared_ptr<Buyable> buyable);
    void AddCustomer(std::shared_ptr<Customer> customer);
    void AddOrder(std::shared_ptr<Order> order);

    bool GetBuyables(Listing<std::shared_ptr<Buyable>>& buyables);
    bool GetCustomers(Listing<std::shared_ptr<Customer>>& customers);

    void SetBuyableDisplayedType(BuyableDisplayedType buyableDisplayedType);
    void SetBuyableSortedBy(BuyableSortedBy buyableSortedBy);

    void GetBuyableDisplayedType(BuyableDisplayedType& e);
    void GetBuyableSortedBy(BuyableSortedBy& e);

    void SetBuyableSearchQuery(std::string query);
    void GetBuyableSearchQuery(std::string& query);

    void SetCurrentCustomerId(std::string id);
    void GetCurrentCustomerId(std::string& id);

    void GetCurrentCustomer(std::shared_ptr<Customer>& customer);

    Cart& GetCart();

    bool RemoveBuyable(const std::string& id);
    bool RemoveCustomer(const std::string& id);
    bool RemoveOrder(const std::string& id);

    static StoreSystem& GetInstance()
    {
        static StoreSystem instance;
        return instance;
    }
};

#endif // OOP_PROJECT_STORESYSTEM_H
