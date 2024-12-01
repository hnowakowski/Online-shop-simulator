//
// Created by pawel on 30/11/2024.
//

#include "Headers/Interfaces/Buyable.h"

std::string Buyable::GetId() {
    return id;
}

std::string Buyable::GetName() {
    return name;
}

std::string Buyable::GetDescription() {
    return description;
}

bool Buyable::GetPrice(uint32_t &mainunit, uint32_t &subunit) {
    return price.GetTotal(mainunit, subunit);
}

bool Buyable::GetPrice(uint32_t &mainunit, uint32_t &subunit, Currency &currency) {
    return price.GetTotal(mainunit, subunit, currency);
}

uint32_t Buyable::GetMainUnitPrice() {
    return price.GetMainUnit();
}

uint32_t Buyable::GetSubUnitPrice() {
    return price.GetSubUnit();
}

void Buyable::UpdateMainUnitPrice(uint32_t newmainprice) {
    price.UpdateMainUnit(newmainprice);
}

void Buyable::UpdateSubUnitPrice(uint32_t newsubprice) {
    price.UpdateSubUnit(newsubprice);
}

Buyable::Buyable(std::string id, std::string name, std::string description, Price &price) : price(price) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->price = price;
}
