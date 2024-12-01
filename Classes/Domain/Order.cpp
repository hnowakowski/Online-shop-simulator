//
// Created by pawel on 30/11/2024.
//

#include "Headers/Domain/Order.h"

std::string Order::GetId() {
    return id;
}

Customer &Order::GetCustomer() {
    return customer;
}

Cart &Order::GetCart() {
    return cart;
}

Order &Order::operator=(const Order &other) {
    if (this == &other) {
        return *this;
    }

    this->id = other.id;
    this->customer = other.customer;
    this->cart = other.cart;

    return *this;
}

Order::Order(std::string id, Customer &customer, Cart &cart) : customer(customer), cart(cart) {
    this->id = id;
    this->customer = customer;
    this->cart = cart;
}


