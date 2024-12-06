#ifndef OOP_PROJECT_LISTING_H
#define OOP_PROJECT_LISTING_H

#include <vector>
#include <stdexcept>
#include "../Headers/Domain/Customer.h"
#include "algorithm"

template <typename T>
class Listing {
private:
    std::vector<T> items;
public:
    bool GetItem(std::string id, T &item) {
        for(int i = 0; i < items.size(); ++i) {
            if(items[i].GetId() == id) {
                item = items[i];
                return true;
            }
        }
        return false;
    }

    bool AddItem(T &item) {
        items.push_back(item);
        return true;
    }

    bool RemoveItem(std::string id) {
        for(int i = 0; i < items.size(); ++i) {
            if(items[i].GetId() == id) {
                items.erase(items.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool RemoveItem(T &item) {
        size_t size_before = items.size();
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
        if(size_before == items.size()) {
            return false;
        }

        return true;
    }

    size_t GetSize() {
        return items.size();
    }
};


#endif //OOP_PROJECT_LISTING_H
