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

    QObject::connect(&StoreSystem::GetInstance().GetCart(), &Cart::CartChanged, this, &MainWindow::UpdateCartLabel);


    // end of setup, final function calls
    // KEEP THIS AT THE BOTTOM AT ALL TIMES
    mainScrollArea.Populate();
    UpdateCartLabel();
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
}


void MainWindow::on_btnSearch_clicked()
{
    StoreSystem& system = StoreSystem::GetInstance();
    QString query = ui->lineEditSearch->text();
    system.SetBuyableSearchQuery(query.toStdString());
    this->mainScrollArea.Populate();
}


void MainWindow::on_radioSortName_clicked()
{
    StoreSystem& system = StoreSystem::GetInstance();
    system.SetBuyableSortedBy(BuyableSortedBy::NAME);
    mainScrollArea.Populate();
}


void MainWindow::on_radioSortPrice_clicked()
{
    StoreSystem& system = StoreSystem::GetInstance();
    system.SetBuyableSortedBy(BuyableSortedBy::PRICE);
    mainScrollArea.Populate();
}


void MainWindow::on_radioRating_clicked()
{
    StoreSystem& system = StoreSystem::GetInstance();
    system.SetBuyableSortedBy(BuyableSortedBy::RATING);
    mainScrollArea.Populate();
}

void MainWindow::UpdateCartLabel() {
    uint32_t size = StoreSystem::GetInstance().GetCart().Size();
    QString label = QString::fromStdString("Cart ("+std::to_string(size)+")");
    ui->labelCart->setText(label);
}

