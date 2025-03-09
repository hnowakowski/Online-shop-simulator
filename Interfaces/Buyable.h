#ifndef OOP_PROJECT_BUYABLE_H
#define OOP_PROJECT_BUYABLE_H

#include "../Classes/Price.h"
#include "Serializable.h"

class Product;
class Service;
class Clothing;

class Buyable : virtual public Serializable
{
protected:
    std::string id;
    std::string name;
    std::string description;
    std::string image;
    std::string rating;
    std::shared_ptr<Price> price;

public:
    virtual std::string getId();

    virtual std::string getName();

    virtual std::string getDescription();

    virtual std::string getImage();

    virtual std::string getRating();

    virtual uint32_t getMainUnitPrice();

    virtual uint32_t getSubUnitPrice();

    virtual Price getPrice();

    virtual void updateMainUnitPrice(const uint32_t &newmainprice);

    virtual void updateSubUnitPrice(const uint32_t &newsubprice);

    Buyable();

    Buyable(std::string id,
            std::string name,
            std::string description,
            std::string image,
            std::string rating,
            std::shared_ptr<Price> price);

    static std::shared_ptr<Buyable> createFromJSON(const nlohmann::json &json);

    virtual nlohmann::json toJSON() const override;

    virtual void fromJSON(const nlohmann::json &json) override;

    Buyable(const nlohmann::json &json);

    virtual ~Buyable() = default;
};

#endif // OOP_PROJECT_BUYABLE_H
