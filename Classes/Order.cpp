#include "Order.h"
#include "Customer.h"

std::string Order::GetId() { return id; }

std::shared_ptr<Customer> Order::GetCustomer() { return customer; }

std::shared_ptr<Cart> Order::GetCart() { return cart; }

Order& Order::operator=(const Order& other)
{
    if (this == &other)
    {
        return *this;
    }

    this->id       = other.id;
    this->customer = other.customer;
    this->cart     = other.cart;

    return *this;
}

Order::Order(std::string id, std::shared_ptr<Customer> customer, std::shared_ptr<Cart> cart)
    : customer(customer), cart(cart)
{
    this->id       = id;
    this->customer = customer;
    this->cart     = cart;
}
