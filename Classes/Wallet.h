#ifndef OOP_PROJECT_WALLET_H
#define OOP_PROJECT_WALLET_H

#include <cstdint>

#include "../Interfaces/MoneyPossesive.h"
#include "../Interfaces/Serializable.h"

class Price;

class Wallet : virtual public MoneyPossesive
{
public:
    void addMain(uint32_t amount);
    void addSub(uint32_t amount);
    void removeMain(uint32_t amount);
    void removeSub(uint32_t amount);

    Wallet &operator=(const Wallet &other);
    Wallet(uint32_t mainunit, uint32_t subunit);

    nlohmann::json toJSON() const;

    void fromJSON(const nlohmann::json &json);

    explicit Wallet(const nlohmann::json &json);

    ~Wallet() = default;
};

#endif // OOP_PROJECT_WALLET_H
