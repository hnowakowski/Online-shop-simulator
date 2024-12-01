//
// Created by pawel on 24/11/2024.
//

#ifndef OOP_PROJECT_PRODUCT_H
#define OOP_PROJECT_PRODUCT_H


#include <string>
#include "Currency.h"
#include "Price.h"
#include "Headers/Interfaces/Buyable.h"

class Product : public Buyable {
protected:
    uint32_t quantity;
public:
    uint32_t GetQuantity();

    Product& operator=(const Product &other);

    Product(std::string id, std::string name, std::string description, uint32_t quantity, Price &price);
};


#endif //OOP_PROJECT_PRODUCT_H
