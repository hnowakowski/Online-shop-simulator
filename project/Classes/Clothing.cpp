#include "Clothing.h"

Clothing::Clothing (std::string id, std::string name, std::string description,
                    std::string image, std::string rating, uint32_t quantity,
                    std::shared_ptr<Price> price, Color color,
                    std::string clothing_type, uint32_t size)
    : Product (id, name, description, image, rating, quantity, price),
      color (color), clothing_type (clothing_type), size (size)
{
}

bool Clothing::operator==(const Clothing &other) const
{
    return Buyable::operator==(other) && std::tie(color, clothing_type, size) == std::tie(other.color, other.clothing_type, other.size);
}

Color
Clothing::getColor () const
{
  return color;
}

std::string
Clothing::getClothingType () const
{
  return clothing_type;
}

uint32_t
Clothing::getSize () const
{
  return size;
}

Clothing &
Clothing::operator= (const Clothing &other)
{
  if (this == &other)
    {
      return *this;
    }

  this->id = other.id;
  this->name = other.name;
  this->description = other.description;
  this->image = other.image;
  this->rating = other.rating;
  this->quantity = other.quantity;
  this->price = other.price;
  this->color = other.color;
  this->clothing_type = other.clothing_type;
  this->size = other.size;

  return *this;
}

nlohmann::json
Clothing::toJSON () const
{
  return nlohmann::json{ { "id", id },
                         { "name", name },
                         { "description", description },
                         { "image", image },
                         { "rating", rating },
                         { "quantity", quantity },
                         { "price", price->toJSON () },
                         { "color", color },
                         { "clothing_type", clothing_type },
                         { "size", size } };
}

void
Clothing::fromJSON (const nlohmann::json &json)
{
  id = json.at ("id").get<std::string> ();
  name = json.at ("name").get<std::string> ();
  description = json.at ("description").get<std::string> ();
  image = json.at ("image").get<std::string> ();
  rating = json.at ("rating").get<std::string> ();
  quantity = json.at ("quantity").get<uint32_t> ();
  price = std::make_shared<Price> (json.at ("price"));
  color = json.at ("color").get<Color> ();
  clothing_type = json.at ("clothing_type").get<std::string> ();
  size = json.at ("size").get<uint32_t> ();
}

Clothing::Clothing (const nlohmann::json &json)
{
  this->Clothing::fromJSON (json);
}
