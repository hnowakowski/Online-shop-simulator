#ifndef OOP_PROJECT_WALLET_H
#define OOP_PROJECT_WALLET_H


#include <cstdint>
#include "../Core/Currency.h"
#include "Interfaces/MoneyPossesive.h"

class Wallet : virtual public MoneyPossesive {
public:
    void AddMain(uint32_t amount);
    void AddSub(uint32_t amount);
    void RemoveMain(uint32_t amount);
    void RemoveSub(uint32_t amount);

    Wallet &operator=(const Wallet &other);
    Wallet(std::shared_ptr<Currency>& currency, uint32_t mainunit, uint32_t subunit);
};


#endif //OOP_PROJECT_WALLET_H
