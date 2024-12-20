#ifndef OOP_PROJECT_BUYABLE_H
#define OOP_PROJECT_BUYABLE_H


#include "Headers/Core/Price.h"
#include "Serializable.h"

class Buyable : virtual public Serializable{
protected:
    std::string id;
    std::string name;
    std::string description;
    std::string image;
    std::string rating;
    std::shared_ptr<Price> price;
public:
    virtual std::string GetId();

    virtual std::string GetName();

    virtual std::string GetDescription();

    virtual std::string GetImage();

    virtual std::string GetRating();

    virtual uint32_t GetMainUnitPrice();

    virtual uint32_t GetSubUnitPrice();

    virtual bool GetPrice(uint32_t &mainunit, uint32_t &subunit);

    virtual void UpdateMainUnitPrice(uint32_t newmainprice);

    virtual void UpdateSubUnitPrice(uint32_t newsubprice);

    Buyable();

    Buyable(std::string id, std::string name, std::string description, std::string image, std::string rating, std::shared_ptr<Price> price);

    virtual nlohmann::json toJSON() const override;

    virtual void fromJSON(const nlohmann::json &json) override;

    Buyable(const nlohmann::json& json);

    virtual ~Buyable() = default;
};


#endif //OOP_PROJECT_BUYABLE_H
