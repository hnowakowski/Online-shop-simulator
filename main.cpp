#include "mainwindow.h"
#include "Templates/LoaderSaver.h"
#include "Headers/Core/Product.h"
#include <QApplication>
#include <iostream>

#include "Enums/Color.h"
#include "Headers/System/StoreSystem.h"

int main(int argc, char *argv[])
{
    std::cout<<"Start\n";
    std::cout<<argv[0]<<"\n";
    std::vector<std::shared_ptr<Product>> send;
    auto item1 = std::make_shared<Product>("id1", "name1", "description1", "image1", 10, std::make_shared<Price>(StoreSystem::GetInstance().GetBaseCurrency(), 100, 10));
    auto item2 = std::make_shared<Product>("id2", "name2", "description2", "image2", 20, std::make_shared<Price>(StoreSystem::GetInstance().GetBaseCurrency(), 200, 20));
    auto item3 = std::make_shared<Product>("id3", "name3", "description3", "image3", 30, std::make_shared<Price>(StoreSystem::GetInstance().GetBaseCurrency(), 300, 30));
    auto item4 = std::make_shared<Product>("id4", "name4", "description4", "image4", 40, std::make_shared<Price>(StoreSystem::GetInstance().GetBaseCurrency(), 400, 40));
    auto item5 = std::make_shared<Product>("id5", "name5", "description5", "image5", 50, std::make_shared<Price>(StoreSystem::GetInstance().GetBaseCurrency(), 500, 50));
    auto item6 = std::make_shared<Product>("id6", "name6", "description6", "image6", 60, std::make_shared<Price>(StoreSystem::GetInstance().GetBaseCurrency(), 600, 60));
    send.push_back(item1);
    send.push_back(item2);
    send.push_back(item3);
    send.push_back(item4);
    send.push_back(item5);
    // send.push_back(item6);
    if(LoaderSaver<Product>::Save("/home/determinator/CLionProjects/OOP/Online-shop-simulator/products.json", send)) {
        std::cout<<"yipeee!\n";
    }
    std::vector<std::shared_ptr<Product>> receive;
    if(LoaderSaver<Product>::Load("/home/determinator/CLionProjects/OOP/Online-shop-simulator/products.json", receive)){
        std::cout<<"yipeee!\n";
    }
    std::cout<<send.size();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
