#ifndef OOP_PROJECT_PRICE_H
#define OOP_PROJECT_PRICE_H

#include "../Abstracts/MoneyPossesive.h"
#include "../Abstracts/Serializable.h"

class Wallet;

class Price : public MoneyPossesive, virtual public Serializable
{
public:
    void updatePrice(const uint32_t &newmainPrice, const uint32_t &newSubprice);

    void addPrice(const Price &other);

    Price();

    Price(const uint32_t &mainunit, const uint32_t &subunit);

    nlohmann::json toJSON() const override;

    void fromJSON(const nlohmann::json &json) override;

    Price(const nlohmann::json &json);
};

#endif // OOP_PROJECT_PRICE_H
