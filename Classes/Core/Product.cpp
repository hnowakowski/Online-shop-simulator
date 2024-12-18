#include "../../Headers/Core/Product.h"
#include <iostream>

uint32_t Product::GetQuantity() {
    return quantity;
}

Product::Product() {}


Product::Product(std::string id, std::string name, std::string description, std::string image, std::string rating,
                 uint32_t quantity, std::shared_ptr<Price> price) : Buyable(id, name, description, image, rating, price), quantity(quantity) {}

Product &Product::operator=(const Product &other) {
    if(this == &other) {
        return *this;
    }

    this->id = other.id;
    this->name = other.name;
    this->description = other.description;
    this->image = other.image;
    this->rating = other.rating;
    this->quantity = other.quantity;
    this->price = other.price;

    return *this;
}

nlohmann::json Product::toJSON() const {
    return nlohmann::json{
            {"id",          id},
            {"name",        name},
            {"description", description},
            {"image", image},
            {"quantity",     quantity},
            {"price",       price->toJSON()}
    };
}

void Product::fromJSON(const nlohmann::json &json) {
    std::cout<<"Product is being read\n";
    id = json.at("id").get<std::string>();
    name = json.at("name").get<std::string>();
    description = json.at("description").get<std::string>();
    image = json.at("image").get<std::string>();
    rating = json.at("rating").get<std::string>();
    quantity = json.at("quantity").get<uint32_t>();
    price = std::make_shared<Price>(json.at("price"));
    std::cout<<"Product read\n";
}

Product::Product(const nlohmann::json& json) {
    this->Product::fromJSON(json);
}
