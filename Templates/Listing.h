#ifndef OOP_PROJECT_LISTING_H
#define OOP_PROJECT_LISTING_H

#include <vector>
#include <stdexcept>
#include "../Headers/Domain/Customer.h"
#include <algorithm>
#include <functional>

template <typename T>
class Listing {
private:
    std::vector<T> items;
public:
    bool GetItem(const std::string& id, T &item) {
        for(int i = 0; i < items.size(); ++i) {
            if(items[i]->GetId() == id) {
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

    bool RemoveItem(const std::string& id) {
        for(int i = 0; i < items.size(); ++i) {
            if(items[i]->GetId() == id) {
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

    void Sort(const std::function<bool(const T&, const T&)>& comparator) {
        std::sort(items.begin(), items.end(), comparator);
    }

    auto begin() { return items.begin(); }
    auto end() { return items.end(); }
    auto begin() const { return items.cbegin(); }
    auto end() const { return items.cend(); }
};


#endif //OOP_PROJECT_LISTING_H
