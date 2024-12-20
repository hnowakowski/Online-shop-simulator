#ifndef OOP_PROJECT_SERVICETYPE_H
#define OOP_PROJECT_SERVICETYPE_H
#include "ExternalLibs/nlohmann/json.hpp"

enum class ServiceType {
    DISCORDIAN,
    ART,
    OTHER
};

inline void to_json(nlohmann::json &j, const ServiceType &type) {
    switch (type) {
    case ServiceType::DISCORDIAN: j = "DISCORDIAN"; break;
    case ServiceType::ART: j = "ART"; break;
    case ServiceType::OTHER: j = "OTHER"; break;
    default: throw std::invalid_argument("Unknown ServiceType");
    }
}

inline void from_json(const nlohmann::json &j, ServiceType &type) {
    std::string typeStr = j.get<std::string>();
    if (typeStr == "DISCORDIAN") type = ServiceType::DISCORDIAN;
    else if (typeStr == "ART") type = ServiceType::ART;
    else if (typeStr == "OTHER") type = ServiceType::OTHER;
    else throw std::invalid_argument("Unknown ServiceType: " + typeStr);
}

#endif //OOP_PROJECT_SERVICETYPE_H
