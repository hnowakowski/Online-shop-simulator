#ifndef OOP_PROJECT_SERVICE_H
#define OOP_PROJECT_SERVICE_H


#include "Headers/Interfaces/Buyable.h"
#include "../../Enums/ServiceType.h"

class Service : public Buyable {
private:
    ServiceType servicetype;
public:
    ServiceType GetType();

    Service & operator=(const Service &other);
    Service(std::string id, std::string name, std::string description, Price &price, ServiceType type);
};


#endif //OOP_PROJECT_SERVICE_H
