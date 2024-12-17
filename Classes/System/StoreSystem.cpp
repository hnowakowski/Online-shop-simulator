#include "../../Headers/System/StoreSystem.h"

 std::shared_ptr<Currency> StoreSystem::GetBaseCurrency() {
    return basecurrency;
}

bool StoreSystem::GetBuyable(const std::string &id, std::shared_ptr<Buyable> &buyable) {
    if (buyables.GetItem(id, buyable)) {
        return true;
    }
    return false;
}

bool StoreSystem::GetBuyables(Listing<std::shared_ptr<Buyable>> &buyables){
    if (this->buyables.GetSize()) {
        buyables = this->buyables;
        return true;
    }
    return false;
}


bool StoreSystem::GetCustomer(const std::string &id, std::shared_ptr<Customer> &customer) {
    if (customers.GetItem(id, customer)) {
        return true;
    }
    return false;
}

bool StoreSystem::GetOrder(const std::string &id, std::shared_ptr<Order> &order) {
    if(orders.GetItem(id, order)) {
        return true;
    }
    return false;
}

bool StoreSystem::GetCurrency(const std::string &code, std::shared_ptr<Currency> &currency) {
    for (auto &c : currencies) {
        if (c->GetCode() == code) {
            currency = c;
            return true;
        }
    }
    return false;
}

void StoreSystem::GetBuyableDisplayedType(BuyableDisplayedType& e){
    e = this->buyableDisplayedType;
}

void StoreSystem::GetBuyableSortedBy(BuyableSortedBy& e){
    e = this->buyableSortedBy;
}

void StoreSystem::SetBuyableDisplayedType(BuyableDisplayedType buyableDisplayedType){
    this->buyableDisplayedType = buyableDisplayedType;
}

void StoreSystem::SetBuyableSortedBy(BuyableSortedBy buyableSortedBy){
    this->buyableSortedBy = buyableSortedBy;
}

void StoreSystem::AddBuyable(std::shared_ptr<Buyable> buyable) {
    buyables.AddItem(buyable);
}

void StoreSystem::AddCustomer(std::shared_ptr<Customer> customer) {
    customers.AddItem(customer);
}

void StoreSystem::AddOrder(std::shared_ptr<Order> order) {
    orders.AddItem(order);
}


void StoreSystem::AddCurrency(std::shared_ptr<Currency> currency) {
    currencies.push_back(currency);
}


bool StoreSystem::RemoveBuyable(const std::string& id) {
    if (buyables.RemoveItem(id)) {
        return true;
    }
    return false;
}

bool StoreSystem::RemoveCustomer(const std::string& id) {
    if(customers.RemoveItem(id)) {
        return true;
    }
    return false;
}

bool StoreSystem::RemoveOrder(const std::string& id) {
    if(orders.RemoveItem(id)) {
        return true;
    }
    return false;
}

bool StoreSystem::RemoveCurrency(const std::string& code) {
    for(int i = 0; i < currencies.size(); ++i) {
        if(currencies[i]->GetCode() == code) {
            currencies.erase(currencies.begin() + i);
            return true;
        }
    }
    return false;
}

