//
// Created by pawel on 30/11/2024.
//

#include "Headers/System/StoreSystem.h"
#include "algorithm"

Currency &StoreSystem::GetBaseCurrency() {
    return basecurrency;
}

bool StoreSystem::GetProduct(std::string id, Product &product) {
    if (products.GetItem(id, product)) {
        return true;
    }
    return false;
}

bool StoreSystem::GetService(std::string id, Service &service) {
    if (services.GetItem(id, service)) {
        return true;
    }
    return false;
}

bool StoreSystem::GetCustomer(std::string id, Customer &customer) {
    if (customers.GetItem(id, customer)) {
        return true;
    }
    return false;
}

bool StoreSystem::GetOrder(std::string id, Order &order) {
    if(orders.GetItem(id, order)) {
        return true;
    }
    return false;
}

void StoreSystem::AddProduct(Product &product) {
    products.AddItem(product);
}

void StoreSystem::AddService(Service &service) {
    services.AddItem(service);
}

void StoreSystem::AddCustomer(Customer &customer) {
    customers.AddItem(customer);
}

void StoreSystem::AddOrder(Order &order) {
    orders.AddItem(order);
}

bool StoreSystem::RemoveProduct(std::string id) {
    if (products.RemoveItem(id)) {
        return true;
    }
    return false;
}

bool StoreSystem::RemoveService(std::string id) {
    if (services.RemoveItem(id)) {
        return true;
    }
    return false;
}

bool StoreSystem::RemoveCustomer(std::string id) {
    if(customers.RemoveItem(id)) {
        return true;
    }
    return false;
}

bool StoreSystem::RemoveOrder(std::string id) {
    if(orders.RemoveItem(id)) {
        return true;
    }
    return false;
}

