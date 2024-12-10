#ifndef OOP_PROJECT_CURRENCY_H
#define OOP_PROJECT_CURRENCY_H

#include <cstdint>
#include <string>
#include <map>
#include "Interfaces/Serializable.h"

class Currency : public Serializable {
private:
    std::string name;
    std::string code;
    std::string symbol;
    uint32_t subs_is_main;
    std::map<std::string, float> exchange_rates;
public:
    std::string GetName();

    std::string GetCode();

    std::string GetSymbol();

    bool SetExchangeRate(std::string code, float &rate);

    bool GetExchangeRate(std::string code, float &rate);

    uint32_t GetSubsIsMain();

    bool operator==(const Currency &other_currency);

    Currency &operator=(const Currency &currency);

    Currency(std::string name, std::string code, std::string symbol, uint32_t subs_is_main,
             std::map<std::string, float> exchange_rates = {});

    nlohmann::json toJSON() const override;

    void fromJSON(const nlohmann::json &json) override;
};


#endif //OOP_PROJECT_CURRENCY_H
