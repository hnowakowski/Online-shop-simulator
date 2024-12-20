#ifndef OOP_PROJECT_SERVICE_H
#define OOP_PROJECT_SERVICE_H


#include "Interfaces/Buyable.h"
#include "../../Enums/ServiceType.h"

class Service : public Buyable{
private:
    ServiceType servicetype;
public:
    ServiceType GetType();

    Service & operator=(const Service &other);

    Service();

    Service(std::string id, std::string name, std::string description, std::string image, std::string rating, std::shared_ptr<Price> price, ServiceType type);

    nlohmann::json toJSON() const override;

    void fromJSON(const nlohmann::json &json) override;

    explicit Service(const nlohmann::json& json);

};


#endif //OOP_PROJECT_SERVICE_H
