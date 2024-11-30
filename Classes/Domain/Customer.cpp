//
// Created by pawel on 30/11/2024.
//

#include "Headers/Domain/Customer.h"
#include "Headers/System/StoreSystem.h"

std::string Customer::GetId() {
    return id;
}

std::string Customer::GetName() {
    return name;
}

std::string Customer::GetSurname() {
    return surname;
}

std::string Customer::GetEmail() {
    return email;
}

std::string Customer::GetPhone() {
    return phone;
}


Customer &Customer::operator=(const Customer &other) {
    if (this == &other) {
        return *this;
    }

    this->id = other.id;
    this->name = other.name;
    this->surname = other.surname;
    this->email = other.email;
    this->phone = other.phone;
    this->wallet = other.wallet;

    return *this;
}

Wallet &Customer::GetWallet() {
    return wallet;
}

Customer::Customer(std::string id, std::string name, std::string surname, std::string email, std::string phone) : wallet(StoreSystem::GetInstance().GetBaseCurrency(), 0, 0) {
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->email = email;
    this->phone = phone;
}

Customer::Customer(std::string id, std::string name, std::string surname, std::string email, std::string phone, Wallet &wallet) : wallet(wallet) {
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->email = email;
    this->phone = phone;
    this->wallet = wallet;
}




