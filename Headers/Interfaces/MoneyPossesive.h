#ifndef OOP_PROJECT_MONEYPOSSESIVE_H
#define OOP_PROJECT_MONEYPOSSESIVE_H


#include <cstdint>
#include "../Core/Currency.h"

class MoneyPossesive {
private:
    bool GetConvertedTotal(uint32_t & mainunit, uint32_t & subunit, Currency & new_currency);
protected:
    Currency & currency;
    uint32_t mainunit;
    uint32_t subunit;
public:
    virtual bool GetTotal(uint32_t & mainunit, uint32_t & subunit);
    virtual bool GetTotal(uint32_t & mainunit, uint32_t & subunit, Currency & currency);
    virtual uint32_t GetMainUnit();
    virtual uint32_t GetSubUnit();
    virtual bool ChangeCurrency(Currency & currency);

    MoneyPossesive(Currency & currency, uint32_t mainunit, uint32_t subunit);
    MoneyPossesive(Currency & currency);

};


#endif //OOP_PROJECT_MONEYPOSSESIVE_H
