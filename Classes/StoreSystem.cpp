#include "StoreSystem.h"

bool StoreSystem::GetBuyable(const std::string &id, std::shared_ptr<Buyable> &buyable)
{
    if (buyables.GetItem(id, buyable)) {
        return true;
    }
    return false;
}

bool StoreSystem::GetCustomer(const std::string &id, std::shared_ptr<Customer> &customer)
{
    if (customers.GetItem(id, customer)) {
        return true;
    }
    return false;
}

bool StoreSystem::GetBuyables(Listing<std::shared_ptr<Buyable>> &buyables)
{
    if (this->buyables.GetSize()) {
        buyables = this->buyables;
        return true;
    }
    return false;
}

bool StoreSystem::GetCustomers(Listing<std::shared_ptr<Customer>> &customers)
{
    customers = this->customers;
    if (this->customers.GetSize()) {
        return true;
    }
    return false;
}

void StoreSystem::GetBuyableDisplayedType(BuyableDisplayedType &e)
{
    e = this->buyableDisplayedType;
}

void StoreSystem::GetBuyableSortedBy(BuyableSortedBy &e)
{
    e = this->buyableSortedBy;
}

void StoreSystem::SetBuyableDisplayedType(BuyableDisplayedType buyableDisplayedType)
{
    this->buyableDisplayedType = buyableDisplayedType;
}

void StoreSystem::SetBuyableSortedBy(BuyableSortedBy buyableSortedBy)
{
    this->buyableSortedBy = buyableSortedBy;
}

void StoreSystem::SetBuyableSearchQuery(std::string query)
{
    this->buyableSearchQuery = query;
}

void StoreSystem::GetBuyableSearchQuery(std::string &query)
{
    query = this->buyableSearchQuery;
}

void StoreSystem::SetCurrentCustomerId(std::string id)
{
    currentCustomerId = id;
}

void StoreSystem::GetCurrentCustomerId(std::string &id)
{
    id = currentCustomerId;
}

void StoreSystem::GetCurrentCustomer(std::shared_ptr<Customer> &customer)
{
    GetCustomer(currentCustomerId, customer);
}

Cart &StoreSystem::GetCart()
{
    return cart;
}

void StoreSystem::AddBuyable(std::shared_ptr<Buyable> buyable)
{
    buyables.AddItem(buyable);
}

void StoreSystem::AddCustomer(std::shared_ptr<Customer> customer)
{
    customers.AddItem(customer);
}

bool StoreSystem::RemoveBuyable(const std::string &id)
{
    if (buyables.RemoveItem(id)) {
        return true;
    }
    return false;
}

bool StoreSystem::RemoveCustomer(const std::string &id)
{
    if (customers.RemoveItem(id)) {
        return true;
    }
    return false;
}
