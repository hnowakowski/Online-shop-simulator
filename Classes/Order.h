#ifndef OOP_PROJECT_ORDER_H
#define OOP_PROJECT_ORDER_H

#include "Cart.h"
#include "Customer.h"

class Order
{
    char*                     id;
    std::shared_ptr<Customer> customer;
    std::shared_ptr<Cart>     cart;

  public:
    char*                     GetId();
    std::shared_ptr<Customer> GetCustomer();
    std::shared_ptr<Cart>     GetCart();

    Order& operator=(const Order& other);
    Order(char id[], std::shared_ptr<Customer> customer, std::shared_ptr<Cart> cart);
    ~Order();
};

#endif // OOP_PROJECT_ORDER_H
