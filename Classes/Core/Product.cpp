//
// Created by pawel on 24/11/2024.
//

#include "Headers/Core/Product.h"

uint32_t Product::GetQuantity() {
    return quantity;
}


Product::Product(std::string id, std::string name, std::string description, uint32_t quantity, Price &price) : Buyable(id, name, description, price) {
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
