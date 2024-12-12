#ifndef OOP_PROJECT_STORESYSTEM_H
#define OOP_PROJECT_STORESYSTEM_H


#include <vector>
#include "../Domain/Order.h"
#include "../../Templates/Listing.h"
#include "../Core/Service.h"

class StoreSystem {
    std::shared_ptr<Currency> basecurrency;
    std::vector<std::shared_ptr<Currency>> currencies;

    Listing<std::shared_ptr<Product>> products;
    Listing<std::shared_ptr<Service>> services;

    Listing<std::shared_ptr<Customer>> customers;
    Listing<std::shared_ptr<Order>> orders;

    StoreSystem() : basecurrency(new Currency("Złoty polski","PLN","Zł",100)) {
        AddCurrency(GetBaseCurrency());
    };

    StoreSystem(StoreSystem &other) = delete;

    StoreSystem &operator=(StoreSystem &other) = delete;

public:
    std::shared_ptr<Currency> GetBaseCurrency();

    bool GetProduct(const std::string &id, std::shared_ptr<Product> &product);
    bool GetService(const std::string &id, std::shared_ptr<Service> &service);
    bool GetCustomer(const std::string &id, std::shared_ptr<Customer> &customer);
    bool GetOrder(const std::string &id, std::shared_ptr<Order> &order);
    bool GetCurrency(const std::string &code, std::shared_ptr<Currency> &currency);

    void AddProduct(std::shared_ptr<Product> product);
    void AddService(std::shared_ptr<Service> service);
    void AddCustomer(std::shared_ptr<Customer> customer);
    void AddOrder(std::shared_ptr<Order> order);
    void AddCurrency(std::shared_ptr<Currency> currency);

    bool RemoveProduct(const std::string &id);
    bool RemoveCustomer(const std::string &id);
    bool RemoveService(const std::string &id);
    bool RemoveOrder(const std::string &id);
    bool RemoveCurrency(const std::string &code);

    static StoreSystem &GetInstance() {
        static StoreSystem instance;
        return instance;
    }
};


#endif //OOP_PROJECT_STORESYSTEM_H
