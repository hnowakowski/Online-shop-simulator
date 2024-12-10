#ifndef OOP_PROJECT_LOADERSAVER_H
#define OOP_PROJECT_LOADERSAVER_H

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <ExternalLibs/nlohmann/json.hpp>

template <typename T>
class LoaderSaver {
public:
    static bool Load(const std::string &filename, std::vector<std::shared_ptr<T>> &objects) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        nlohmann::json json;
        file >> json;
        file.close();

        for (const auto &item : json) {
            auto object = std::make_shared<T>();
            object->fromJSON(item);
            objects.push_back(object);
        }

        return true;
    }

    static bool Save(const std::string &filename, const std::vector<std::shared_ptr<T>> &objects) {
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

#endif //OOP_PROJECT_LOADERSAVER_H