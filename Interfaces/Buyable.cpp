#include "Interfaces/Buyable.h"

std::string Buyable::GetId() {
    return id;
}

std::string Buyable::GetName() {
    return name;
}

std::string Buyable::GetDescription() {
    return description;
}

std::string Buyable::GetImage() {
    return image;
}

bool Buyable::GetPrice(uint32_t &mainunit, uint32_t &subunit) {
    return price->GetTotal(mainunit, subunit);
}

bool Buyable::GetPrice(uint32_t &mainunit, uint32_t &subunit, std::shared_ptr<Currency> &currency) {
    return price->GetTotal(mainunit, subunit, currency);
}

uint32_t Buyable::GetMainUnitPrice() {
    return price->GetMainUnit();
}

uint32_t Buyable::GetSubUnitPrice() {
    return price->GetSubUnit();
}

void Buyable::UpdateMainUnitPrice(uint32_t newmainprice) {
    price->UpdateMainUnit(newmainprice);
}

void Buyable::UpdateSubUnitPrice(uint32_t newsubprice) {
    price->UpdateSubUnit(newsubprice);
}

Buyable::Buyable()
    : id(""), name(""), description(""), image(""), price(nullptr) {}

Buyable::Buyable(std::string id, std::string name, std::string description, std::string image, std::shared_ptr<Price> price) : price(price) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->image = image;
    this->price = price;
}

nlohmann::json Buyable::toJSON() const {
    return nlohmann::json{
        {"id",          id},
        {"name",        name},
        {"description", description},
        {"image", image},
        {"price",       price->toJSON()}
    };
}

void Buyable::fromJSON(const nlohmann::json &json) {
    id = json.at("id").get<std::string>();
    name = json.at("name").get<std::string>();
    description = json.at("description").get<std::string>();
    image = json.at("image").get<std::string>();
    price = std::make_shared<Price>(json.at("price"));
}

Buyable::Buyable(const nlohmann::json& json) {
    this->Buyable::fromJSON(json);
}
