#ifndef OOP_PROJECT_MONEYPOSSESIVE_H
#define OOP_PROJECT_MONEYPOSSESIVE_H

#include <cstdint>

class MoneyPossesive
{
protected:
    uint32_t mainunit;
    uint32_t subunit;

public:
    virtual uint32_t getMainUnit();
    virtual uint32_t getSubUnit();

    void addMainUnit(const uint32_t &amount);

    void addSubUnit(const uint32_t &amount);

    bool operator>=(const MoneyPossesive &price);

    MoneyPossesive(uint32_t mainunit, uint32_t subunit);
    MoneyPossesive();
};

#endif // OOP_PROJECT_MONEYPOSSESIVE_H
