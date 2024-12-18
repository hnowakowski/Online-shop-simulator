#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Templates/LoaderSaver.h"
#include "Headers/System/StoreSystem.h"
#include "Headers/CustomWidgets/BuyableScrollAreaMain.h"

void loadBuyables();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    loadBuyables();
    mainScrollArea = BuyableScrollAreaMain(ui->scrollAreaProducts);

    QStringList comboBoxItems = {
        "All",
        "Products",
        "Clothes",
        "Services"
    };
    ui->comboBoxSearch->addItems(comboBoxItems);
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


void MainWindow::on_comboBoxSearch_currentIndexChanged(int index)
{
    StoreSystem& system = StoreSystem::GetInstance();
    BuyableDisplayedType type = BuyableDisplayedType::ALL;
    switch (index) {
    case 0: type = BuyableDisplayedType::ALL; break;
    case 1: type = BuyableDisplayedType::PRODUCT; break;
    case 2: type = BuyableDisplayedType::CLOTHING; break;
    case 3: type = BuyableDisplayedType::SERVICE; break;
    }
    system.SetBuyableDisplayedType(type);
    this->mainScrollArea.Populate();
}


void MainWindow::on_btnSearch_clicked()
{
    StoreSystem& system = StoreSystem::GetInstance();
    QString query = ui->lineEditSearch->text();
    system.SetBuyableSearchQuery(query.toStdString());
    this->mainScrollArea.Populate();
}

