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
    Color getColor() const;
    std::string getClothingType() const;
    uint32_t getSize() const;
    bool operator==(const Clothing &other) const;

    Clothing &operator=(const Clothing &other);
    Clothing(std::string id, std::string name, std::string description, std::string image, std::string rating, uint32_t quantity, std::shared_ptr<Price> price,
             Color color, std::string clothing_type, uint32_t size);

    nlohmann::json toJSON() const override;
    void fromJSON(const nlohmann::json &json) override;

    Clothing(const nlohmann::json &json);
};

#endif // OOP_PROJECT_CLOTHING_H
