#ifndef OOP_PROJECT_COLOR_H
#define OOP_PROJECT_COLOR_H
#include "../ExternalLibs/nlohmann/json.hpp"

enum class Color
{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    PURPLE,
    PINK,
    ORANGE,
    GREY,
    WHITE,
    BLACK,
    CYAN,
};

inline void to_json(nlohmann::json& j, const Color& color)
{
    switch (color)
    {
        case Color::RED:
            j = "RED";
            break;

        case Color::GREEN:
            j = "GREEN";
            break;

        case Color::BLUE:
            j = "BLUE";
            break;

        case Color::YELLOW:
            j = "YELLOW";
            break;

        case Color::PURPLE:
            j = "PURPLE";
            break;

        case Color::PINK:
            j = "PINK";
            break;

        case Color::ORANGE:
            j = "ORANGE";
            break;

        case Color::GREY:
            j = "GREY";
            break;

        case Color::WHITE:
            j = "WHITE";
            break;

        case Color::BLACK:
            j = "BLACK";
            break;

        case Color::CYAN:
            j = "CYAN";
            break;

        default:
            throw std::invalid_argument("Unknown Color");
    }
}

inline void from_json(const nlohmann::json& j, Color& color)
{
    static const std::unordered_map<std::string, Color> colorMap = {{"RED", Color::RED},
                                                                    {"GREEN", Color::GREEN},
                                                                    {"BLUE", Color::BLUE},
                                                                    {"YELLOW", Color::YELLOW},
                                                                    {"PURPLE", Color::PURPLE},
                                                                    {"PINK", Color::PINK},
                                                                    {"ORANGE", Color::ORANGE},
                                                                    {"GREY", Color::GREY},
                                                                    {"WHITE", Color::WHITE},
                                                                    {"BLACK", Color::BLACK},
                                                                    {"CYAN", Color::CYAN}};
    std::string                                         colorStr = j.get<std::string>();

    auto it = colorMap.find(colorStr);
    if (it != colorMap.end())
    {
        color = it->second;
        return;
    }

    throw std::invalid_argument("Unknown Color: " + colorStr);
}

#endif // OOP_PROJECT_COLOR_H
