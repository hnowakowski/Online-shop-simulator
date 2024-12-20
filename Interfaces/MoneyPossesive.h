#ifndef OOP_PROJECT_MONEYPOSSESIVE_H
#define OOP_PROJECT_MONEYPOSSESIVE_H

#include <cstdint>

class MoneyPossesive {
protected:
    uint32_t mainunit;
    uint32_t subunit;
public:
    virtual bool GetTotal(uint32_t & mainunit, uint32_t & subunit);
    virtual uint32_t GetMainUnit();
    virtual uint32_t GetSubUnit();

    MoneyPossesive(uint32_t mainunit, uint32_t subunit);
    MoneyPossesive();

};


#endif //OOP_PROJECT_MONEYPOSSESIVE_H
