#ifndef OOP_PROJECT_CUSTOMER_H
#define OOP_PROJECT_CUSTOMER_H

#include <memory>
#include <string>

#include "Wallet.h"
#include "../Interfaces/Serializable.h"

class Customer : virtual public Serializable
{
    std::string             id;
    std::string             name;
    std::string             surname;
    std::string             email;
    std::string             phone;
    std::shared_ptr<Wallet> wallet;

  public:
    std::string             GetId();
    std::string             GetName();
    std::string             GetSurname();
    std::string             GetEmail();
    std::string             GetPhone();
    std::shared_ptr<Wallet> GetWallet();

    Customer& operator=(const Customer& other);

    Customer(std::string id, std::string name, std::string surname, std::string email, std::string phone);
    Customer(std::string             id,
             std::string             name,
             std::string             surname,
             std::string             email,
             std::string             phone,
             std::shared_ptr<Wallet> wallet);

    nlohmann::json toJSON() const;

    void fromJSON(const nlohmann::json& json);

    explicit Customer(const nlohmann::json& json);

    ~Customer() = default;
};

#endif // OOP_PROJECT_CUSTOMER_H
