#ifndef OOP_PROJECT_MONEYPOSSESIVE_H
#define OOP_PROJECT_MONEYPOSSESIVE_H


#include <cstdint>
#include "Headers/Core/Currency.h"

class MoneyPossesive {
    bool GetConvertedTotal(uint32_t & mainunit, uint32_t & subunit, std::shared_ptr<Currency> new_currency);
protected:
    std::shared_ptr<Currency> currency;
    uint32_t mainunit;
    uint32_t subunit;
public:
    virtual bool GetTotal(uint32_t & mainunit, uint32_t & subunit);
    virtual bool GetTotal(uint32_t & mainunit, uint32_t & subunit, std::shared_ptr<Currency> currency);
    virtual uint32_t GetMainUnit();
    virtual uint32_t GetSubUnit();
    virtual bool ChangeCurrency(std::shared_ptr<Currency> currency);

    MoneyPossesive(std::shared_ptr<Currency> currency, uint32_t mainunit, uint32_t subunit);
    MoneyPossesive(std::shared_ptr<Currency> currency);

};


#endif //OOP_PROJECT_MONEYPOSSESIVE_H
