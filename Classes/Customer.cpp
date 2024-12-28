#include <memory>

#include "Customer.h"
#include "Order.h"
#include "StoreSystem.h"

std::string Customer::GetId() { return id; }

std::string Customer::GetName() { return name; }

std::string Customer::GetSurname() { return surname; }

std::string Customer::GetEmail() { return email; }

std::string Customer::GetPhone() { return phone; }

Customer& Customer::operator=(const Customer& other)
{
    if (this == &other)
    {
        return *this;
    }

    this->id      = other.id;
    this->name    = other.name;
    this->surname = other.surname;
    this->email   = other.email;
    this->phone   = other.phone;
    this->wallet  = other.wallet;

    return *this;
}

std::shared_ptr<Wallet> Customer::GetWallet() { return wallet; }

Customer::Customer(std::string id, std::string name, std::string surname, std::string email, std::string phone)
    : wallet(std::make_shared<Wallet>(0, 0))
{
    this->id      = id;
    this->name    = name;
    this->surname = surname;
    this->email   = email;
    this->phone   = phone;
}

Customer::Customer(std::string             id,
                   std::string             name,
                   std::string             surname,
                   std::string             email,
                   std::string             phone,
                   std::shared_ptr<Wallet> wallet)
    : wallet(wallet)
{
    this->id      = id;
    this->name    = name;
    this->surname = surname;
    this->email   = email;
    this->phone   = phone;
    this->wallet  = wallet;
}

nlohmann::json Customer::toJSON() const
{
    return nlohmann::json {{"id", id},
                           {"name", name},
                           {"surname", surname},
                           {"email", email},
                           {"phone", phone},
                           {"wallet", wallet->toJSON()}};
}

void Customer::fromJSON(const nlohmann::json& json)
{
    id      = json.at("id").get<std::string>();
    name    = json.at("name").get<std::string>();
    surname = json.at("surname").get<std::string>();
    email   = json.at("email").get<std::string>();
    phone   = json.at("phone").get<std::string>();
    wallet  = std::make_shared<Wallet>(json.at("wallet"));
}

Customer::Customer(const nlohmann::json& json) { this->Customer::fromJSON(json); }
