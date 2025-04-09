#ifndef TESTLOADERSAVER_H
#define TESTLOADERSAVER_H

#include <QTest>
#include "../project/Abstracts/Buyable.h"
#include "../project/Abstracts/MoneyPossesive.h"
#include "../project/Classes/Clothing.h"
#include "../project/Classes/Customer.h"
#include "../project/Classes/Price.h"
#include "../project/Classes/Product.h"
#include "../project/Classes/Service.h"
#include "../project/Classes/StoreSystem.h"
#include "../project/Classes/Wallet.h"
#include "../project/Templates/LoaderSaver.h"

class TestLoaderSaver : public QObject
{
    Q_OBJECT

private slots:
    void savePrice();
    void saveWallet();
    void saveProduct();
    void saveClothing();
    void saveService();
    void saveCustomer();
    // void saveAndLoadPrice();
    // void saveAndLoadWallet();
    // void saveAndLoadProduct();
    // void saveAndLoadClothing();
    // void saveAndLoadService();
    // void saveAndLoadCustomer();
    //void cleanupTestCase();
};

#endif // TESTLOADERSAVER_H
