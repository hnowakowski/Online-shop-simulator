#include "StoreSystem.h"

std::shared_ptr<Buyable> StoreSystem::GetBuyable(const std::string &id)
{
    for (auto &buyable : buyables) {
        if (buyable->GetId() == id) {
            return buyable;
        }
    }
    return std::shared_ptr<Buyable>();
}

std::shared_ptr<Customer> StoreSystem::GetCustomer(const std::string &id)
{
    for (auto &customer : customers) {
        if (customer->GetId() == id) {
            return customer;
        }
    }
    return std::shared_ptr<Customer>();
}

std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> StoreSystem::GetBuyables()
{
    return std::make_shared<std::vector<std::shared_ptr<Buyable>>>(this->buyables);
}

std::shared_ptr<std::vector<std::shared_ptr<Customer>>> StoreSystem::GetCustomers()
{
    return std::make_shared<std::vector<std::shared_ptr<Customer>>>(this->customers);
}

BuyableDisplayedType StoreSystem::GetBuyableDisplayedType()
{
    return this->buyableDisplayedType;
}

BuyableSortedBy StoreSystem::GetBuyableSortedBy()
{
    return this->buyableSortedBy;
}

void StoreSystem::SetBuyableDisplayedType(const BuyableDisplayedType &buyableDisplayedType)
{
    this->buyableDisplayedType = buyableDisplayedType;
}

void StoreSystem::SetBuyableSortedBy(const BuyableSortedBy &buyableSortedBy)
{
    this->buyableSortedBy = buyableSortedBy;
}

void StoreSystem::SetBuyableSearchQuery(const std::string &query)
{
    this->buyableSearchQuery = query;
}

std::string StoreSystem::GetBuyableSearchQuery()
{
    return this->buyableSearchQuery;
}

void StoreSystem::SetCurrentCustomerId(const std::string &id)
{
    currentCustomerId = id;
}

std::string StoreSystem::GetCurrentCustomerId()
{
    return currentCustomerId;
}

std::shared_ptr<Customer> StoreSystem::GetCurrentCustomer()
{
    return GetCustomer(currentCustomerId);
}

Cart &StoreSystem::GetCart()
{
    return cart;
}

bool StoreSystem::AddBuyable(std::shared_ptr<Buyable> &buyable)
{
    if (!GetBuyable(buyable->GetId())) {
        buyables.push_back(buyable);
        return true;
    }
    return false;
}

bool StoreSystem::AddCustomer(std::shared_ptr<Customer> &customer)
{
    if (!GetCustomer(customer->GetId())) {
        customers.push_back(customer);
        return true;
    }
    return false;
}

bool StoreSystem::RemoveBuyable(const std::string &id)
{
    for (int i = 0; i < buyables.size(); i++) {
        if (buyables[i]->GetId() == id) {
            buyables.erase(buyables.begin() + i);
            return true;
        }
    }
    return false;
}

bool StoreSystem::RemoveCustomer(const std::string &id)
{
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i]->GetId() == id) {
            customers.erase(customers.begin() + i);
            return true;
        }
    }
    return false;
}

void StoreSystem::SortBuyables(
    const std::function<bool(const std::shared_ptr<Buyable> &, const std::shared_ptr<Buyable> &)>
        &comparator)
{
    std::sort(buyables.begin(), buyables.end(), comparator);
}
