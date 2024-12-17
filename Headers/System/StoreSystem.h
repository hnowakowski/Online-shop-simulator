#ifndef OOP_PROJECT_STORESYSTEM_H
#define OOP_PROJECT_STORESYSTEM_H


#include <vector>
#include "../Domain/Order.h"
#include "../../Templates/Listing.h"
#include "../Core/Service.h"
#include "Enums/BuyableDisplayedType.h"
#include "Enums/BuyableSortedBy.h"

class StoreSystem {
    std::shared_ptr<Currency> basecurrency;
    std::vector<std::shared_ptr<Currency>> currencies;

    Listing<std::shared_ptr<Buyable>> buyables;
    Listing<std::shared_ptr<Customer>> customers;
    Listing<std::shared_ptr<Order>> orders;

    BuyableDisplayedType buyableDisplayedType;
    BuyableSortedBy buyableSortedBy;

    StoreSystem() : basecurrency(new Currency("Złoty polski","PLN","Zł",100)) {
        AddCurrency(GetBaseCurrency());
    };

    StoreSystem(StoreSystem &other) = delete;

    StoreSystem &operator=(StoreSystem &other) = delete;

public:
    std::shared_ptr<Currency> GetBaseCurrency();

    bool GetBuyable(const std::string &id, std::shared_ptr<Buyable> &buyable);
    bool GetCustomer(const std::string &id, std::shared_ptr<Customer> &customer);
    bool GetOrder(const std::string &id, std::shared_ptr<Order> &order);
    bool GetCurrency(const std::string &code, std::shared_ptr<Currency> &currency);

    void AddBuyable(std::shared_ptr<Buyable> buyable);
    void AddCustomer(std::shared_ptr<Customer> customer);
    void AddOrder(std::shared_ptr<Order> order);
    void AddCurrency(std::shared_ptr<Currency> currency);

    void SetBuyableDisplayedType(BuyableDisplayedType buyableDisplayedType);
    void SetBuyableSortedBy(BuyableSortedBy buyableSortedBy);

    BuyableDisplayedType GetBuyableDisplayedType();
    BuyableSortedBy GetBuyableSortedBy();

    Listing<std::shared_ptr<Buyable>> GetBuyables(); //could make ui setup functions friends of this and make it private but idk if keeping this public isn't less bad tbh (it'd be ugly)

    bool RemoveBuyable(const std::string &id);
    bool RemoveCustomer(const std::string &id);
    bool RemoveOrder(const std::string &id);
    bool RemoveCurrency(const std::string &code);

    static StoreSystem &GetInstance() {
        static StoreSystem instance;
        return instance;
    }
};


#endif //OOP_PROJECT_STORESYSTEM_H
