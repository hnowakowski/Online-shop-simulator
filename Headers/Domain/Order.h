#ifndef OOP_PROJECT_ORDER_H
#define OOP_PROJECT_ORDER_H

#include <string>
#include "Cart.h"

class Customer; //this instead of include in header files works somehow, prevents a loop include, requires an include h in a cpp tho

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
