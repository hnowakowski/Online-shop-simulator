#ifndef OOP_PROJECT_SERIALIZABLE_H
#define OOP_PROJECT_SERIALIZABLE_H

#include "../ExternalLibs/nlohmann/json.hpp"

class Serializable
{
public:
    virtual nlohmann::json toJSON() const = 0;

    virtual void fromJSON(const nlohmann::json &json) = 0;

    explicit Serializable(const nlohmann::json &json);

    Serializable() = default;

    virtual ~Serializable() = default;
};

#endif // OOP_PROJECT_SERIALIZABLE_H
