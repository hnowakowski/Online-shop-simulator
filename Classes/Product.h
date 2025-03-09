#ifndef OOP_PROJECT_PRODUCT_H
#define OOP_PROJECT_PRODUCT_H

#include <string>

#include "../Interfaces/Buyable.h"
#include "Price.h"

class Product : public Buyable
{
protected:
    uint32_t quantity{};

public:
    uint32_t getQuantity();

    Product &operator=(const Product &other);

    Product();

    Product(std::string id,
            std::string name,
            std::string description,
            std::string image,
            std::string rating,
            uint32_t quantity,
            std::shared_ptr<Price> price);

    nlohmann::json toJSON() const override;

    void fromJSON(const nlohmann::json &json) override;

    explicit Product(const nlohmann::json &json);
};

#endif // OOP_PROJECT_PRODUCT_H
