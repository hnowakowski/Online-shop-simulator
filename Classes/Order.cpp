#include "Order.h"
#include "Customer.h"

char* Order::GetId() { return id; }

std::shared_ptr<Customer> Order::GetCustomer() { return customer; }

std::shared_ptr<Cart> Order::GetCart() { return cart; }

Order& Order::operator=(const Order& other)
{
    if (this != &other)
    {
        delete[] id;
        this->id = new char[strlen(other.id) + 1];
        strcpy(this->id, other.id);
        this->customer = other.customer;
        this->cart = other.cart;
    }
    return *this;
}

Order::Order(char id[], std::shared_ptr<Customer> customer, std::shared_ptr<Cart> cart)
    : customer(customer), cart(cart)
{
    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);
}


Order::~Order()
{
    delete[] id;
}
