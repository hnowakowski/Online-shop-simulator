#include "StoreSystem.h"

StoreSystem::StoreSystem()
    : buyables(std::make_shared<std::vector<std::shared_ptr<Buyable>>>())
    , customers(std::make_shared<std::vector<std::shared_ptr<Customer>>>())
{}

std::shared_ptr<Buyable> StoreSystem::getBuyable(const std::string &id)
{
    if (buyables->empty())
        return std::shared_ptr<Buyable>();
    for (auto &buyable : *buyables) {
        if (buyable->getId() == id) {
            return buyable;
        }
    }
    return std::shared_ptr<Buyable>();
}

std::shared_ptr<Customer> StoreSystem::getCustomer(const std::string &id)
{
    if (customers->empty())
        return std::shared_ptr<Customer>();
    for (auto &customer : *customers) {
        if (customer->getId() == id) {
            return customer;
        }
    }
    return std::shared_ptr<Customer>();
}

std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> StoreSystem::getBuyables()
{
    return buyables;
}

std::shared_ptr<std::vector<std::shared_ptr<Customer>>> StoreSystem::getCustomers()
{
    return customers;
}

BuyableDisplayedType StoreSystem::getBuyableDisplayedType() const
{
    return this->buyableDisplayedType;
}

BuyableSortedBy StoreSystem::getBuyableSortedBy() const
{
    return this->buyableSortedBy;
}

void StoreSystem::setBuyableDisplayedType(const BuyableDisplayedType &buyableDisplayedType)
{
    this->buyableDisplayedType = buyableDisplayedType;
}

void StoreSystem::setBuyableSortedBy(const BuyableSortedBy &buyableSortedBy)
{
    this->buyableSortedBy = buyableSortedBy;
}

void StoreSystem::setBuyableSearchQuery(const std::string &query)
{
    this->buyableSearchQuery = query;
}

std::string StoreSystem::getBuyableSearchQuery() const
{
    return this->buyableSearchQuery;
}

void StoreSystem::setCurrentCustomerId(const std::string &id)
{
    currentCustomerId = id;
}

std::string StoreSystem::getCurrentCustomerId() const
{
    return currentCustomerId;
}

std::shared_ptr<Customer> StoreSystem::getCurrentCustomer()
{
    return getCustomer(currentCustomerId);
}

Cart &StoreSystem::getCart()
{
    return cart;
}

bool StoreSystem::addBuyable(std::shared_ptr<Buyable> &buyable)
{
    if (!getBuyable(buyable->getId())) {
        buyables->push_back(buyable);
        return true;
    }
    return false;
}

bool StoreSystem::addCustomer(std::shared_ptr<Customer> &customer)
{
    if (!getCustomer(customer->getId())) {
        customers->push_back(customer);
        return true;
    }
    return false;
}

bool StoreSystem::removeBuyable(const std::string &id)
{
    for (int i = 0; i < buyables->size(); i++) {
        if ((*buyables)[i]->getId() == id) {
            buyables->erase(buyables->begin() + i);
            return true;
        }
    }
    return false;
}

bool StoreSystem::removeCustomer(const std::string &id)
{
    for (int i = 0; i < customers->size(); i++) {
        if ((*customers)[i]->getId() == id) {
            customers->erase(customers->begin() + i);
            return true;
        }
    }
    return false;
}

void StoreSystem::sortBuyables(
    const std::function<bool(const std::shared_ptr<Buyable> &, const std::shared_ptr<Buyable> &)>
        &comparator)
{
    std::sort(buyables->begin(), buyables->end(), comparator);
}
