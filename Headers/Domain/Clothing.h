#ifndef OOP_PROJECT_CLOTHING_H
#define OOP_PROJECT_CLOTHING_H


#include "../Core/Product.h"
#include "../../Enums/Color.h"

class Clothing : public Product {
private:
    Color color;
    std::string clothing_type;
    uint32_t size{};
public:
    Color GetColor();
    std::string GetClothingType();
    uint32_t GetSize();

    Clothing & operator=(const Clothing &other);
    Clothing(std::string id, std::string name, std::string description, uint32_t quantity, Price& price, Color color, std::string clothing_type, uint32_t size);
};


#endif //OOP_PROJECT_CLOTHING_H
