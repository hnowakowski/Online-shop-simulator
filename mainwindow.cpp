#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Templates/LoaderSaver.h"
#include "Headers/System/StoreSystem.h"
#include "Headers/Core/Product.h"
#include "Headers/CustomWidgets/BuyableScrollAreaMain.h"

void loadBuyables();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    loadBuyables();
    BuyableScrollAreaMain test(ui->scrollAreaProducts);
    test.Populate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void loadBuyables(){
    std::vector<std::shared_ptr<Buyable>> loadedBuyables; //this array is pointless, everything is taken care of in storesystem already on god 😭🙏
    StoreSystem& system = StoreSystem::GetInstance();
    if(!LoaderSaver<Buyable>::Load(PATH + "Assets\\products.json", loadedBuyables)){
        qDebug() <<"WARNING! - Loading products.json failed!\n";
    }
    if(!LoaderSaver<Buyable>::Load(PATH + "Assets\\services.json", loadedBuyables)){
        qDebug() <<"WARNING! - Loading services.json failed!\n";
    }
    for (auto buyable : loadedBuyables){
        if(!system.GetBuyable(buyable->GetId(), buyable)){
            system.AddBuyable(buyable);
        }
    }
}

