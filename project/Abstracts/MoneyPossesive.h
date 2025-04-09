#ifndef OOP_PROJECT_MONEYPOSSESIVE_H
#define OOP_PROJECT_MONEYPOSSESIVE_H

#include <cstdint>

class MoneyPossesive
{
protected:
    uint32_t units;

public:
    virtual uint32_t getMainUnit();

    virtual uint32_t getSubUnit();

    virtual void addMainUnit(const uint32_t &amount);

    virtual void addSubUnit(const uint32_t &amount);

    virtual void setMainUnit(const uint32_t &amount);

    virtual void setSubUnit(const uint32_t &amount);

    virtual bool operator<(const MoneyPossesive &other) const;

    virtual bool operator>=(const MoneyPossesive &other) const;

    MoneyPossesive(const uint32_t &mainunit, const uint32_t &subunit);
    MoneyPossesive(const uint32_t &units);
    MoneyPossesive();

    virtual ~MoneyPossesive() = default;
};

#endif // OOP_PROJECT_MONEYPOSSESIVE_H
