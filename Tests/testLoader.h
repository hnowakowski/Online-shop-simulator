#ifndef TESTLOADER_H
#define TESTLOADER_H

#include <QTest>
#include "../project/Abstracts/Buyable.h"
#include "../project/Classes/Clothing.h"
#include "../project/Classes/Customer.h"
#include "../project/Classes/Product.h"
#include "../project/Classes/Service.h"
#include "../project/Classes/StoreSystem.h"
#include "../project/Templates/LoaderSaver.h"

class TestLoader : public QObject
{
    Q_OBJECT

private slots:
    void loadProduct();
    void loadClothing();
    void loadService();
    void loadCustomer();
};

#endif // TESTLOADER_H
