#include "testLoaderSaver.h"

void TestLoaderSaver::initTestCase()
{
    QVERIFY(std::filesystem::create_directory(JSONPATH + "TestJsons"));
}

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
    mockProducts.push_back(std::make_shared<Product>("P1", "prod1", "desc1", "", "1", 1, std::make_shared<Price>(10, 1)));
    mockProducts.push_back(std::make_shared<Product>("P2", "prod2", "desc2", "", "2", 2, std::make_shared<Price>(20, 2)));
    QVERIFY(LoaderSaver<Product>::save(JSONPATH + "TestJsons\\productTest.json", mockProducts));
}

void TestLoaderSaver::saveClothing()
{
    std::vector<std::shared_ptr<Clothing>> mockClothing;
    mockClothing.push_back(std::make_shared<Clothing>("P1", "prod1", "desc1", "", "1", 1, std::make_shared<Price>(10, 1), Color::BLACK, "type1", 1));
    mockClothing.push_back(std::make_shared<Clothing>("P2", "prod2", "desc2", "", "2", 2, std::make_shared<Price>(20, 2), Color::BLUE, "type2", 2));
    QVERIFY(LoaderSaver<Clothing>::save(JSONPATH + "TestJsons\\clothingTest.json", mockClothing));
}

void TestLoaderSaver::saveService()
{
    std::vector<std::shared_ptr<Service>> mockServices;
    mockServices.push_back(std::make_shared<Service>("S1", "serv1", "desc1", "", "1", std::make_shared<Price>(10, 1), ServiceType::ART));
    mockServices.push_back(std::make_shared<Service>("S2", "serv2", "desc2", "", "2", std::make_shared<Price>(20, 2), ServiceType::DISCORDIAN));
    QVERIFY(LoaderSaver<Service>::save(JSONPATH + "TestJsons\\serviceTest.json", mockServices));
}

void TestLoaderSaver::saveCustomer()
{
    std::vector<std::shared_ptr<Customer>> mockCustomers;
    mockCustomers.push_back(
        std::make_shared<Customer>("C1", "cust1", "sur1", "email1", "phone1", "city1", "address1", "pesel1", "pass1", std::make_shared<Wallet>(10, 1)));
    mockCustomers.push_back(
        std::make_shared<Customer>("C2", "cust2", "sur2", "email2", "phone2", "city2", "address2", "pesel2", "pass2", std::make_shared<Wallet>(20, 2)));
    QVERIFY(LoaderSaver<Customer>::save(JSONPATH + "testJsons\\customerTest.json", mockCustomers));
}

void TestLoaderSaver::saveAndLoadPrice()
{
    std::vector<std::shared_ptr<Price>> mockPrices;
    mockPrices.push_back(std::make_shared<Price>(10, 1));
    mockPrices.push_back(std::make_shared<Price>(20, 2));
    LoaderSaver<Price>::save(JSONPATH + "TestJsons\\priceTest2.json", mockPrices);
    std::vector<std::shared_ptr<Price>> loadedPrices;
    QVERIFY(LoaderSaver<Price>::load(JSONPATH + "TestJsons\\priceTest2.json", loadedPrices));
    QVERIFY(*loadedPrices[0] == *mockPrices[0]);
    QVERIFY(*loadedPrices[1] == *mockPrices[1]);
}

void TestLoaderSaver::saveAndLoadWallet()
{
    std::vector<std::shared_ptr<Wallet>> mockWallets;
    mockWallets.push_back(std::make_shared<Wallet>(10, 1));
    mockWallets.push_back(std::make_shared<Wallet>(20, 2));
    LoaderSaver<Wallet>::save(JSONPATH + "TestJsons\\walletTest2.json", mockWallets);
    std::vector<std::shared_ptr<Wallet>> loadedWallets;
    QVERIFY(LoaderSaver<Wallet>::load(JSONPATH + "TestJsons\\walletTest2.json", loadedWallets));
    QVERIFY(*loadedWallets[0] == *mockWallets[0]);
    QVERIFY(*loadedWallets[1] == *mockWallets[1]);
}

void TestLoaderSaver::saveAndLoadProduct()
{
    std::vector<std::shared_ptr<Product>> mockProducts;
    mockProducts.push_back(std::make_shared<Product>("P1", "prod1", "desc1", "", "1", 1, std::make_shared<Price>(10, 1)));
    mockProducts.push_back(std::make_shared<Product>("P2", "prod2", "desc2", "", "2", 2, std::make_shared<Price>(20, 2)));
    LoaderSaver<Product>::save(JSONPATH + "TestJsons\\productTest2.json", mockProducts);
    std::vector<std::shared_ptr<Product>> loadedProducts;
    QVERIFY(LoaderSaver<Product>::load(JSONPATH + "TestJsons\\productTest2.json", loadedProducts));
    QVERIFY(*loadedProducts[0] == *mockProducts[0]);
    QVERIFY(*loadedProducts[1] == *mockProducts[1]);
}

void TestLoaderSaver::saveAndLoadClothing()
{
    std::vector<std::shared_ptr<Clothing>> mockClothing;
    mockClothing.push_back(std::make_shared<Clothing>("P1", "prod1", "desc1", "", "1", 1, std::make_shared<Price>(10, 1), Color::BLACK, "type1", 1));
    mockClothing.push_back(std::make_shared<Clothing>("P2", "prod2", "desc2", "", "2", 2, std::make_shared<Price>(20, 2), Color::BLUE, "type2", 2));
    LoaderSaver<Clothing>::save(JSONPATH + "TestJsons\\clothingTest2.json", mockClothing);
    std::vector<std::shared_ptr<Clothing>> loadedClothing;
    QVERIFY(LoaderSaver<Clothing>::load(JSONPATH + "TestJsons\\clothingTest2.json", loadedClothing));
    QVERIFY(*loadedClothing[0] == *mockClothing[0]);
    QVERIFY(*loadedClothing[1] == *mockClothing[1]);
}

void TestLoaderSaver::saveAndLoadService()
{
    std::vector<std::shared_ptr<Service>> mockServices;
    mockServices.push_back(std::make_shared<Service>("S1", "serv1", "desc1", "", "1", std::make_shared<Price>(10, 1), ServiceType::ART));
    mockServices.push_back(std::make_shared<Service>("S2", "serv2", "desc2", "", "2", std::make_shared<Price>(20, 2), ServiceType::DISCORDIAN));
    LoaderSaver<Service>::save(JSONPATH + "TestJsons\\serviceTest2.json", mockServices);
    std::vector<std::shared_ptr<Service>> loadedServices;
    QVERIFY(LoaderSaver<Service>::load(JSONPATH + "TestJsons\\serviceTest2.json", loadedServices));
    QVERIFY(*loadedServices[0] == *mockServices[0]);
    QVERIFY(*loadedServices[1] == *mockServices[1]);
}

void TestLoaderSaver::saveAndLoadCustomer()
{
    std::vector<std::shared_ptr<Customer>> mockCustomers;
    mockCustomers.push_back(
        std::make_shared<Customer>("C1", "cust1", "sur1", "email1", "phone1", "city1", "address1", "pesel1", "pass1", std::make_shared<Wallet>(10, 1)));
    mockCustomers.push_back(
        std::make_shared<Customer>("C2", "cust2", "sur2", "email2", "phone2", "city2", "address2", "pesel2", "pass2", std::make_shared<Wallet>(20, 2)));
    LoaderSaver<Customer>::save(JSONPATH + "testJsons\\customerTest2.json", mockCustomers);
    std::vector<std::shared_ptr<Customer>> loadedCustomers;
    QVERIFY(LoaderSaver<Customer>::load(JSONPATH + "TestJsons\\customerTest2.json", loadedCustomers));
    QVERIFY(*loadedCustomers[0] == *mockCustomers[0]);
    QVERIFY(*loadedCustomers[1] == *mockCustomers[1]);
}

void TestLoaderSaver::cleanupTestCase()
{
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\priceTest.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\walletTest.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\productTest.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\clothingTest.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\serviceTest.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\customerTest.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\priceTest2.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\walletTest2.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\productTest2.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\clothingTest2.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\serviceTest2.json").c_str()));
    QVERIFY(!std::remove((JSONPATH + "TestJsons\\customerTest2.json").c_str()));
    QVERIFY(std::filesystem::remove(JSONPATH + "TestJsons"));
}
