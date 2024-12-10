#include "mainwindow.h"
#include "Templates/LoaderSaver.h"
#include "Headers/Core/Product.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout<<"Start\n";
    std::cout<<argv[0]<<"\n";
    LoaderSaver<Product> loaderSaver;
    std::vector<std::shared_ptr<Product>> test;
    if(loaderSaver.Load("PUT YOUR GLOBAL PATH HERE", test)){
        std::cout<<"yipeee!\n";
    }
    std::cout<<test.size();
    //std::cout<<test[0]->GetName();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
