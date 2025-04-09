#include "testLoaderSaver.h"

void TestLoaderSaver::savePrice()
{
    std::vector<std::shared_ptr<Price>> mockPrices;
    mockPrices.push_back(std::make_shared<Price>(10, 1));
    mockPrices.push_back(std::make_shared<Price>(20, 2));
    QVERIFY(LoaderSaver<Price>::save(JSONPATH + "TestJsons\\priceTest.json", mockPrices));
}

void TestLoaderSaver::saveWallet()
{
    std::vector<std::shared_ptr<Wallet>> mockWallets;
    mockWallets.push_back(std::make_shared<Wallet>(10, 1));
    mockWallets.push_back(std::make_shared<Wallet>(20, 2));
    QVERIFY(LoaderSaver<Wallet>::save(JSONPATH + "TestJsons\\walletTest.json", mockWallets));
}

void TestLoaderSaver::saveProduct()
{
    std::vector<std::shared_ptr<Product>> mockProducts;
    mockProducts.push_back(std::make_shared<Product>("P1", "prod1", "desc1", "", "1/10", 1, std::make_shared<Price>(10, 1)));
    mockProducts.push_back(std::make_shared<Product>("P2", "prod2", "desc2", "", "2/10", 2, std::make_shared<Price>(20, 2)));
    QVERIFY(LoaderSaver<Product>::save(JSONPATH + "TestJsons\\productTest.json", mockProducts));
}

void TestLoaderSaver::saveClothing()
{
    std::vector<std::shared_ptr<Clothing>> mockClothing;
    mockClothing.push_back(std::make_shared<Clothing>("P1", "prod1", "desc1", "", "1/10", 1, std::make_shared<Price>(10, 1), Color::BLACK, "type1", 1));
    mockClothing.push_back(std::make_shared<Clothing>("P2", "prod2", "desc2", "", "2/10", 2, std::make_shared<Price>(20, 2), Color::BLUE, "type2", 2));
    QVERIFY(LoaderSaver<Clothing>::save(JSONPATH + "TestJsons\\clothingTest.json", mockClothing));
}

void TestLoaderSaver::saveService()
{
    std::vector<std::shared_ptr<Service>> mockServices;
    mockServices.push_back(std::make_shared<Service>("S1", "serv1", "desc1", "", "1/10", std::make_shared<Price>(10, 1), ServiceType::ART));
    mockServices.push_back(std::make_shared<Service>("S2", "serv2", "desc2", "", "2/10", std::make_shared<Price>(20, 2), ServiceType::DISCORDIAN));
    QVERIFY(LoaderSaver<Service>::save(JSONPATH + "TestJsons\\serviceTest.json", mockServices));
}

void TestLoaderSaver::saveCustomer()
{
    std::vector<std::shared_ptr<Customer>> mockCustomers;
    mockCustomers.push_back(std::make_shared<Customer>("C1", "cust1", "sur1", "email1", "phone1", "city1", "address1", "pesel1", "pass1", std::make_shared<Wallet>(10, 1)));
    mockCustomers.push_back(std::make_shared<Customer>("C2", "cust2", "sur2", "email2", "phone2", "city2", "address2", "pesel2", "pass2", std::make_shared<Wallet>(20, 2)));
    QVERIFY(LoaderSaver<Customer>::save(JSONPATH + "testJsons\\customerTest.json", mockCustomers));
}

// void TestLoaderSaver::saveAndLoadPrice() {}

// void TestLoaderSaver::saveAndLoadWallet() {}

// void TestLoaderSaver::saveAndLoadProduct() {}

// void TestLoaderSaver::saveAndLoadClothing() {}

// void TestLoaderSaver::saveAndLoadService() {}

// void TestLoaderSaver::saveAndLoadCustomer() {}

// void TestLoaderSaver::cleanupTestCase()
// {
//     //delete files
// }
