#ifndef OOP_PROJECT_CUSTOMER_H
#define OOP_PROJECT_CUSTOMER_H

#include <memory>
#include <string>

#include "../Abstracts/Serializable.h"
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
    std::string getId() const;
    std::string getName() const;
    std::string getSurname() const;
    std::string getEmail() const;
    std::string getPhone() const;
    std::string getCity() const;
    std::string getAddress() const;
    std::string getPESEL() const;
    std::string getPassword() const;
    std::shared_ptr<Wallet> getWallet();

    bool operator==(const Customer &other) const;

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

    nlohmann::json toJSON() const override;

    void fromJSON(const nlohmann::json &json) override;

    explicit Customer(const nlohmann::json &json);

    ~Customer() = default;
};

#endif // OOP_PROJECT_CUSTOMER_H
