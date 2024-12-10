#include "../../Headers/Core/Product.h"

uint32_t Product::GetQuantity() {
    return quantity;
}


Product::Product(std::string id, std::string name, std::string description, uint32_t quantity, std::shared_ptr<Price> &price) : Buyable(id, name, description, price) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->quantity = quantity;
    this->price = price;
}

Product &Product::operator=(const Product &other) {
    if(this == &other) {
        return *this;
    }

    this->id = other.id;
    this->name = other.name;
    this->description = other.description;
    this->quantity = other.quantity;
    this->price = other.price;

    return *this;
}

nlohmann::json Product::toJSON() const {
    return nlohmann::json{
            {"id",          id},
            {"name",        name},
            {"description", description},
            {"quantity",     quantity},
            {"price",       price->toJSON()}
    };
}

void Product::fromJSON(const nlohmann::json &json) {
    id = json.at("id").get<std::string>();
    name = json.at("name").get<std::string>();
    description = json.at("description").get<std::string>();
    quantity = json.at("quantity").get<uint32_t>();
    price->fromJSON(json.at("price"));
}
