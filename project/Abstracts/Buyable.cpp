#include "Buyable.h"
#include "../Classes/Clothing.h"
#include "../Classes/Product.h"
#include "../Classes/Service.h"

std::string Buyable::getId() const
{
    return id;
}

std::string Buyable::getName() const
{
    return name;
}

std::string Buyable::getDescription() const
{
    return description;
}

std::string Buyable::getImage() const
{
    return image;
}

std::string Buyable::getRating() const
{
    return rating;
}

std::shared_ptr<Price> Buyable::getPrice()
{
    return price;
}

bool Buyable::operator==(const Buyable &other) const
{
    return std::tie(id, name, description, image, *price) == std::tie(other.id, other.name, other.description, other.image, *other.price);
}

Buyable::Buyable()
    : id("")
    , name("")
    , description("")
    , image("")
    , price(nullptr)
{}

Buyable::Buyable(std::string id, std::string name, std::string description, std::string image, std::string rating, std::shared_ptr<Price> price)
    : id(id)
    , name(name)
    , description(description)
    , image(image)
    , rating(rating)
    , price(price)
{}

std::shared_ptr<Buyable> Buyable::createFromJSON(const nlohmann::json &json)
{
    if (json.contains("color")) {
        return std::make_shared<Clothing>(json);
    } else if (json.contains("servicetype")) {
        return std::make_shared<Service>(json);
    } else if (json.contains("quantity")) {
        return std::make_shared<Product>(json);
    } else {
        return std::make_shared<Buyable>(json);
    }
}

nlohmann::json Buyable::toJSON() const
{
    return nlohmann::json{{"id", id}, {"name", name}, {"description", description}, {"image", image}, {"rating", rating}, {"price", price->toJSON()}};
}

void Buyable::fromJSON(const nlohmann::json &json)
{
    id = json.at("id").get<std::string>();
    name = json.at("name").get<std::string>();
    description = json.at("description").get<std::string>();
    image = json.at("image").get<std::string>();
    rating = json.at("rating").get<std::string>();
    price = std::make_shared<Price>(json.at("price"));
}

Buyable::Buyable(const nlohmann::json &json)
{
    this->Buyable::fromJSON(json);
}
