#ifndef OOP_PROJECT_PRICE_H
#define OOP_PROJECT_PRICE_H


#include "Currency.h"
#include "Headers/Interfaces/MoneyPossesive.h"

class Price : virtual public MoneyPossesive {
public:
    void UpdateMainUnit(uint32_t newmainprice);
    void UpdateSubUnit(uint32_t newsubprice);
    void UpdatePrice(uint32_t newmainprice, uint32_t newsubprice);
    Price& operator=(const Price &price);

    Price(Currency & currency, uint32_t mainunit, uint32_t subunit);

};


#endif //OOP_PROJECT_PRICE_H
