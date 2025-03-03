#include <memory>

#include "Customer.h"
#include "StoreSystem.h"

std::string Customer::GetId() { return id; }

std::string Customer::GetName() { return name; }

std::string Customer::GetSurname() { return surname; }

std::string Customer::GetEmail() { return email; }

std::string Customer::GetPhone() { return phone; }

std::string Customer::GetCity() { return city; }

std::string Customer::GetAddress() { return address; }

std::string Customer::GetPESEL() { return PESEL; }

std::string Customer::GetPassword() { return password; }

Customer &Customer::operator=(const Customer &other)
{
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

std::shared_ptr<Wallet> Customer::GetWallet() { return wallet; }

Customer::Customer(std::string id,
                   std::string name,
                   std::string surname,
                   std::string email,
                   std::string phone,
                   std::string city,
                   std::string address,
                   std::string PESEL,
                   std::string password)
    : wallet(std::make_shared<Wallet>(0, 0))
{
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->email = email;
    this->phone = phone;
    this->city = city;
    this->address = address;
    this->PESEL = PESEL;
    this->password = password;
}

Customer::Customer(std::string id,
                   std::string name,
                   std::string surname,
                   std::string email,
                   std::string phone,
                   std::string city,
                   std::string address,
                   std::string PESEL,
                   std::string password,
                   std::shared_ptr<Wallet> wallet)
    : wallet(wallet)
{
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->email = email;
    this->phone = phone;
    this->city = city;
    this->address = address;
    this->PESEL = PESEL;
    this->password = password;
    this->wallet = wallet;
}

nlohmann::json Customer::toJSON() const
{
    return nlohmann::json{{"id", id},
                          {"name", name},
                          {"surname", surname},
                          {"email", email},
                          {"phone", phone},
                          {"city", city},
                          {"address", address},
                          {"PESEL", PESEL},
                          {"password", password},
                          {"wallet", wallet->toJSON()}};
}

void Customer::fromJSON(const nlohmann::json &json)
{
    id = json.at("id").get<std::string>();
    name = json.at("name").get<std::string>();
    surname = json.at("surname").get<std::string>();
    email = json.at("email").get<std::string>();
    phone = json.at("phone").get<std::string>();
    city = json.at("city").get<std::string>();
    address = json.at("address").get<std::string>();
    PESEL = json.at("PESEL").get<std::string>();
    password = json.at("password").get<std::string>();
    wallet = std::make_shared<Wallet>(json.at("wallet"));
}

Customer::Customer(const nlohmann::json &json)
{
    this->Customer::fromJSON(json);
}
