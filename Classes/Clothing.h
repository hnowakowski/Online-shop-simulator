#ifndef OOP_PROJECT_CLOTHING_H
#define OOP_PROJECT_CLOTHING_H

#include "../Enums/Color.h"
#include "Product.h"

class Clothing : public Product
{
    Color color;
    std::string clothing_type;
    uint32_t size{};

public:
    Color GetColor();
    std::string GetClothingType();
    uint32_t GetSize();

    Clothing &operator=(const Clothing &other);
    Clothing(std::string id,
             std::string name,
             std::string description,
             std::string image,
             uint32_t quantity,
             std::shared_ptr<Price> &price,
             Color color,
             std::string clothing_type,
             uint32_t size);

    nlohmann::json toJSON() const override;
    void fromJSON(const nlohmann::json &json) override;

    Clothing(const nlohmann::json &json);
};

#endif // OOP_PROJECT_CLOTHING_H
