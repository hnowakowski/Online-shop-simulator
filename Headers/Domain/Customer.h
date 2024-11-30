//
// Created by pawel on 30/11/2024.
//

#ifndef OOP_PROJECT_CUSTOMER_H
#define OOP_PROJECT_CUSTOMER_H

#include <vector>
#include <memory>
#include "Order.h"
#include "Wallet.h"

class Customer {
private:
    std::string id;
    std::string name;
    std::string surname;
    std::string email;
    std::string phone;
    Wallet wallet;
public:
    std::string GetId();
    std::string GetName();
    std::string GetSurname();
    std::string GetEmail();
    std::string GetPhone();
    Wallet & GetWallet();

    Customer & operator=(const Customer &other);

    Customer(std::string id, std::string name, std::string surname, std::string email, std::string phone);
    Customer(std::string id, std::string name, std::string surname, std::string email, std::string phone, Wallet &wallet);
};

#endif //OOP_PROJECT_CUSTOMER_H