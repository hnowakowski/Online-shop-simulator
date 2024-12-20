#ifndef OOP_PROJECT_LOADERSAVER_H
#define OOP_PROJECT_LOADERSAVER_H

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <ExternalLibs/nlohmann/json.hpp>
#include <iostream>
#include "Headers/Core/Product.h"
#include "Headers/Core/Service.h"
#include "Headers/Domain/Clothing.h"
#include "qlogging.h"
#include "mainwindow.h"

template <typename T>
class LoaderSaver {
public:
    static bool Load(const std::string &filename, std::vector<std::shared_ptr<T>> &objects) {
        std::cout<<"Load inside LoaderSaver called\n";
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        std::cout<<"File found\n";
        nlohmann::json json;
        file >> json;
        file.close();

        for (const auto &item : json) {
            qDebug() << "Processing item: " << item.dump();
            qDebug() <<item.contains("price");
            std::shared_ptr<T> object;

            if (item.contains("quantity")) {
                object = std::make_shared<Product>(item);
            } else if (item.contains("servicetype")) {
                object = std::make_shared<Service>(item);
            } else if (item.contains("color")) {
                object = std::make_shared<Clothing>(item);
            } else {
                object = std::make_shared<T>(item);
            }

            objects.push_back(object);
            qDebug() << "Object created successfully!\n";
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
