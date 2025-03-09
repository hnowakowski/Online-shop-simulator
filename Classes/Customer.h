#ifndef OOP_PROJECT_CUSTOMER_H
#define OOP_PROJECT_CUSTOMER_H

#include <memory>
#include <string>

#include "../Interfaces/Serializable.h"
#include "Wallet.h"

class Customer : virtual public Serializable
{
    std::string id;
    std::string name;
    std::string surname;
    std::string email;
    std::string phone;
    std::string city;
    std::string address;
    std::string PESEL;
    std::string password;
    std::shared_ptr<Wallet> wallet;

public:
    std::string getId();
    std::string getName();
    std::string getSurname();
    std::string getEmail();
    std::string getPhone();
    std::string getCity();
    std::string getAddress();
    std::string getPESEL();
    std::string getPassword();
    std::shared_ptr<Wallet> getWallet();

    Customer &operator=(const Customer &other);

    Customer(std::string id,
             std::string name,
             std::string surname,
             std::string email,
             std::string phone,
             std::string city,
             std::string address,
             std::string PESEL,
             std::string password);

    Customer(std::string id,
             std::string name,
             std::string surname,
             std::string email,
             std::string phone,
             std::string city,
             std::string address,
             std::string PESEL,
             std::string password,
             std::shared_ptr<Wallet> wallet);

    nlohmann::json toJSON() const;

    void fromJSON(const nlohmann::json &json);

    explicit Customer(const nlohmann::json &json);

    ~Customer() = default;
};

#endif // OOP_PROJECT_CUSTOMER_H
