#ifndef OOP_PROJECT_PRODUCT_H
#define OOP_PROJECT_PRODUCT_H


#include <string>
#include "Currency.h"
#include "Price.h"
#include "Interfaces/Buyable.h"

class Product : public Buyable, virtual public Serializable {
protected:
    uint32_t quantity;
public:
    uint32_t GetQuantity();

    Product& operator=(const Product &other);

    Product(std::string id, std::string name, std::string description, uint32_t quantity, std::shared_ptr<Price> &price);

    nlohmann::json toJSON() const override;

    void fromJSON(const nlohmann::json &json) override;
};


#endif //OOP_PROJECT_PRODUCT_H
