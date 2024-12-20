#ifndef OOP_PROJECT_COLOR_H
#define OOP_PROJECT_COLOR_H
#include "ExternalLibs/nlohmann/json.hpp"

enum class Color {
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

inline void to_json(nlohmann::json &j, const Color &color) {
    switch (color) {
    case Color::RED: j = "RED"; break;
    case Color::GREEN: j = "GREEN"; break;
    case Color::BLUE: j = "BLUE"; break;
    case Color::YELLOW: j = "YELLOW"; break;
    case Color::PURPLE: j = "PURPLE"; break;
    case Color::PINK: j = "PINK"; break;
    case Color::ORANGE: j = "ORANGE"; break;
    case Color::GREY: j = "GREY"; break;
    case Color::WHITE: j = "WHITE"; break;
    case Color::BLACK: j = "BLACK"; break;
    case Color::CYAN: j = "CYAN"; break;
    default: throw std::invalid_argument("Unknown Color");
    }
}

inline void from_json(const nlohmann::json &j, Color &color) {
    std::string colorStr = j.get<std::string>();
    if (colorStr == "RED") color = Color::RED;
    else if (colorStr == "GREEN") color = Color::GREEN;
    else if (colorStr == "BLUE") color = Color::BLUE;
    else if (colorStr == "YELLOW") color = Color::YELLOW;
    else if (colorStr == "PURPLE") color = Color::PURPLE;
    else if (colorStr == "PINK") color = Color::PINK;
    else if (colorStr == "ORANGE") color = Color::ORANGE;
    else if (colorStr == "GREY") color = Color::GREY;
    else if (colorStr == "WHITE") color = Color::WHITE;
    else if (colorStr == "BLACK") color = Color::BLACK;
    else if (colorStr == "CYAN") color = Color::CYAN;
    else throw std::invalid_argument("Unknown Color: " + colorStr);
}

#endif //OOP_PROJECT_COLOR_H
