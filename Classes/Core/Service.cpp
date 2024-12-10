#include <utility>

#include "../../Headers/Core/Service.h"

ServiceType Service::GetType() {
    return servicetype;
}

Service &Service::operator=(const Service &other) {
    if (this == &other) {
        return *this;
    }

    this->id = other.id;
    this->name = other.name;
    this->description = other.description;
    this->price = other.price;
    this->servicetype = other.servicetype;

    return *this;
}

Service::Service(std::string id, std::string name, std::string description, std::shared_ptr<Price> &price, ServiceType type) : Buyable(
        std::move(id), std::move(name), std::move(description), price) {
    this->servicetype = type;
}

nlohmann::json Service::toJSON() const {
    return nlohmann::json{
            {"id",          id},
            {"name",        name},
            {"description", description},
            {"price",       price->toJSON()},
            {"servicetype", servicetype}
    };
}

void Service::fromJSON(const nlohmann::json &json){
    id = json.at("id").get<std::string>();
    name = json.at("name").get<std::string>();
    description = json.at("description").get<std::string>();
    price->fromJSON(json.at("price"));
    servicetype = json.at("servicetype").get<ServiceType>();
}


