#ifndef OOP_PROJECT_STORESYSTEM_H
#define OOP_PROJECT_STORESYSTEM_H


#include <vector>
#include "../Domain/Order.h"
#include "../../Templates/Listing.h"
#include "../Core/Service.h"

class StoreSystem {
private:
    Currency basecurrency;

    Listing<Product> products;
    Listing<Service> services;

    Listing<Customer> customers;
    Listing<Order> orders;

    StoreSystem() : basecurrency(*new Currency("Złoty polski", "PLN", "Zł", 100)) {};
    StoreSystem(StoreSystem &other) = delete;
    StoreSystem &operator=(StoreSystem &other) = delete;

public:
    Currency & GetBaseCurrency();

    bool GetProduct(std::string id, Product &product);
    bool GetService(std::string id, Service &service);

    bool GetCustomer(std::string id, Customer &customer);
    bool GetOrder(std::string id, Order &order);

    void AddProduct(Product &product);
    void AddService(Service &service);
    void AddCustomer(Customer &customer);
    void AddOrder(Order &order);
    bool RemoveProduct(std::string id);
    bool RemoveCustomer(std::string id);
    bool RemoveService(std::string id);
    bool RemoveOrder(std::string id);

    static StoreSystem &GetInstance() {
        static StoreSystem instance;
        return instance;
    }
};


#endif //OOP_PROJECT_STORESYSTEM_H
