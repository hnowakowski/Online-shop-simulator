#ifndef OOP_PROJECT_WALLET_H
#define OOP_PROJECT_WALLET_H

#include <cstdint>

#include "../Abstracts/MoneyPossesive.h"
#include "../Abstracts/Serializable.h"

class Price;

class Wallet : public MoneyPossesive
{
public:
    void subtractMain(const uint32_t &amount);
    void subtractSub(const uint32_t &amount);

    Wallet &operator=(const Wallet &other);
    Wallet(uint32_t mainunit, uint32_t subunit);

    nlohmann::json toJSON() const;

    void fromJSON(const nlohmann::json &json);

    explicit Wallet(const nlohmann::json &json);

    ~Wallet() = default;
};

#endif // OOP_PROJECT_WALLET_H
