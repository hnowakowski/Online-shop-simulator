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

Service::Service(std::string id, std::string name, std::string description, Price &price, ServiceType type) : Buyable(
        id, name, description, price) {
    this->servicetype = type;
}


