//
// Created by pawel on 30/11/2024.
//

#ifndef OOP_PROJECT_ORDER_H
#define OOP_PROJECT_ORDER_H


#include <string>
#include "Customer.h"
#include "Cart.h"

class Order {
private:
    std::string id;
    Customer & customer;
    Cart & cart;
public:
    std::string GetId();
    Customer& GetCustomer();
    Cart& GetCart();

    Order& operator=(const Order &other);
    Order(std::string id, Customer &customer, Cart &cart);
};


#endif //OOP_PROJECT_ORDER_H
