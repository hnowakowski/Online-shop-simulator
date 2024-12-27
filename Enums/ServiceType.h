#ifndef OOP_PROJECT_SERVICETYPE_H
#define OOP_PROJECT_SERVICETYPE_H
#include "ExternalLibs/nlohmann/json.hpp"

enum class ServiceType
{
    DISCORDIAN,
    ART,
    OTHER
};

inline void to_json(nlohmann::json& j, const ServiceType& type)
{
    switch (type)
    {
        case ServiceType::DISCORDIAN:
            j = "DISCORDIAN";
            break;

        case ServiceType::ART:
            j = "ART";
            break;

        case ServiceType::OTHER:
            j = "OTHER";
            break;

        default:
            throw std::invalid_argument("Unknown ServiceType");
    }
}

inline void from_json(const nlohmann::json& j, ServiceType& type)
{
    static const std::unordered_map<std::string, ServiceType> typeMap = {
        {"DISCORDIAN", ServiceType::DISCORDIAN},
        {"ART", ServiceType::ART},
        {"OTHER", ServiceType::OTHER},
    };
    std::string typeStr = j.get<std::string>();

    auto it = typeMap.find(typeStr);
    if (it != typeMap.end())
    {
        type = it->second;
        return;
    }

    throw std::invalid_argument("Unknown ServiceType: " + typeStr);
}

#endif // OOP_PROJECT_SERVICETYPE_H
