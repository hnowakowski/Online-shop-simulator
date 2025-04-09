#ifndef OOP_PROJECT_LOADERSAVER_H
#define OOP_PROJECT_LOADERSAVER_H

#include "../ExternalLibs/nlohmann/json.hpp"
#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include <QMainWindow>
#include "../Abstracts/Buyable.h"

template<typename T>
class LoaderSaver
{
public:
    static bool load(const std::string &filename, std::vector<std::shared_ptr<T>> &objects)
    {
        std::ifstream file(filename);

        if (!file.is_open()) {
            qDebug() << filename << " <-- Could not open\n";
            return false;
        }
        nlohmann::json json;
        file >> json;
        file.close();

        for (const auto &item : json) {
            std::shared_ptr<T> object;

            if constexpr (std::is_same_v<T, Buyable>) {
                object = std::static_pointer_cast<T>(Buyable::createFromJSON(item));
            } else {
                object = std::make_shared<T>(item);
            }

            objects.push_back(object);
        }

        return true;
    }

    static bool save(const std::string &filename, std::vector<std::shared_ptr<T>> &objects)
    {
        nlohmann::json json;
        for (const auto &object : objects) {
            json.push_back(object->toJSON());
        }

        std::ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        file << json.dump(4);
        file.close();

        return true;
    }
};

#endif // OOP_PROJECT_LOADERSAVER_H
