#ifndef OOP_PROJECT_PRICE_H
#define OOP_PROJECT_PRICE_H

#include "../Interfaces/MoneyPossesive.h"
#include "../Interfaces/Serializable.h"

class Wallet;

class Price : virtual public MoneyPossesive, virtual public Serializable
{
  public:
    void UpdateMainUnit(uint32_t newmainprice);

    void UpdateSubUnit(uint32_t newsubprice);

    void UpdatePrice(uint32_t newmainprice, uint32_t newsubprice);

    Price& operator=(const Price& price);

    Price operator+(const Price& price);

    Price operator-(const Price& price);

    bool operator>(const Price& price);

    bool operator<(const Price& price);

    bool operator>=(const Price& price);

    bool operator<=(const Price& price);

    Price(uint32_t mainunit, uint32_t subunit);

    nlohmann::json toJSON() const override;

    void fromJSON(const nlohmann::json& json) override;

    Price(const nlohmann::json& json);

    friend bool operator>=(const std::shared_ptr<Wallet> wallet, const Price& price);
};

#endif // OOP_PROJECT_PRICE_H
