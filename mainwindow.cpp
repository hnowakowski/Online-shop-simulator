#include <string>

#include "mainwindow.h"
#include "Classes/BuyableScrollAreaCart.h"
#include "Classes/BuyableScrollAreaMain.h"
#include "Classes/StoreSystem.h"
#include "Templates/LoaderSaver.h"
#include "ui_mainwindow.h"

void loadBuyables();

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    loadBuyables();
    mainScrollArea     = BuyableScrollAreaMain(ui->scrollAreaProducts);
    cartScrollArea     = BuyableScrollAreaCart(ui->scrollAreaCart);
    checkoutScrollArea = BuyableScrollAreaCart(ui->scrollAreaCheckout);

    QStringList comboBoxItems = {"All", "Products", "Clothes", "Services"};
    ui->comboBoxSearch->addItems(comboBoxItems);

    QObject::connect(&StoreSystem::GetInstance().GetCart(), &Cart::CartChanged, this, &MainWindow::UpdateCartLabel);

    // end of setup, final function calls
    // KEEP THIS AT THE BOTTOM AT ALL TIMES
    ui->labelFieldsNotFilled->setVisible(false);
    mainScrollArea.Populate();
    UpdateCartLabel();
}

MainWindow::~MainWindow() { delete ui; }

void loadBuyables()
{
    std::vector<std::shared_ptr<Buyable>> loadedBuyables; // this array is pointless, everything is taken care of in storesystem already on god 😭🙏
    StoreSystem& system = StoreSystem::GetInstance();
    if (!LoaderSaver<Buyable>::Load(PATH + "Assets\\products.json", loadedBuyables))
    {
        qDebug() << "WARNING! - Loading products.json failed!\n";
    }
    if (!LoaderSaver<Buyable>::Load(PATH + "Assets\\services.json", loadedBuyables))
    {
        qDebug() << "WARNING! - Loading services.json failed!\n";
    }
    for (auto buyable : loadedBuyables)
    {
        if (!system.GetBuyable(buyable->GetId(), buyable))
        {
            system.AddBuyable(buyable);
        }
    }
}

void loadCustomers()
{
    std::vector<std::shared_ptr<Customer>> loadedCustomers;
    StoreSystem& system = StoreSystem::GetInstance();
    if (!LoaderSaver<Customer>::Load(PATH + "Assets\\customers.json", loadedCustomers))
    {
        qDebug() << "WARNING! - Loading customers.json failed!\n";
    }
    for (auto customer : loadedCustomers)
    {
        if (!system.GetCustomer(customer->GetId(), customer))
        {
            system.AddCustomer(customer);
        }
    }
}

void MainWindow::on_comboBoxSearch_currentIndexChanged(int index)
{
    StoreSystem&         system = StoreSystem::GetInstance();
    BuyableDisplayedType type   = BuyableDisplayedType::ALL;
    switch (index)
    {
        case 0:
            type = BuyableDisplayedType::ALL;
            break;

        case 1:
            type = BuyableDisplayedType::PRODUCT;
            break;

        case 2:
            type = BuyableDisplayedType::CLOTHING;
            break;

        case 3:
            type = BuyableDisplayedType::SERVICE;
            break;
    }
    system.SetBuyableDisplayedType(type);
}

void MainWindow::on_btnSearch_clicked()
{
    StoreSystem& system = StoreSystem::GetInstance();
    QString      query  = ui->lineEditSearch->text();
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

void MainWindow::UpdateCartLabel()
{
    uint32_t size  = StoreSystem::GetInstance().GetCart().Size();
    QString  label = QString::fromStdString("Cart (" + std::to_string(size) + ")");
    ui->labelCart->setText(label);
}

void MainWindow::on_btnMainGotoCart_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageCart);
    cartScrollArea.Populate();
    std::pair<uint32_t, uint32_t> pricePair = StoreSystem::GetInstance().GetCart().GetTotalPrice();
    std::string priceStr                    = "Total: " + std::to_string(pricePair.first) + "." + std::to_string(pricePair.second) + " ZŁ";
    QString priceQStr                       = QString::fromStdString(priceStr);
    ui->labelCartTotalPrice->setText(priceQStr);
}


void MainWindow::on_btnCartGotoMain_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}


void MainWindow::on_btnCartGotoCheckout_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageCheckout);
    checkoutScrollArea.Populate();
    std::pair<uint32_t, uint32_t> pricePair = StoreSystem::GetInstance().GetCart().GetTotalPrice();
    std::string priceStr                    = "Checkout (Total: " + std::to_string(pricePair.first) + "." + std::to_string(pricePair.second) + " ZŁ)";
    QString priceQStr                       = QString::fromStdString(priceStr);
    ui->labelCheckout->setText(priceQStr);
}


void MainWindow::on_btnCheckout_clicked()
{
    // if you have a better idea how to do this then i'd be welcome to hear it
    bool all_filled = true;
    if (ui->lineEditCardNum->text().isEmpty())
    {
        all_filled = false;
    }
    else if (ui->lineEditPin->text().isEmpty())
    {
        all_filled = false;
    }
    else if (ui->lineEditExpiryDate->text().isEmpty())
    {
        all_filled = false;
    }
    else if (ui->lineEditNumOnBack->text().isEmpty())
    {
        all_filled = false;
    }
    else if (!ui->checkBoxCheckoutAgree1->isChecked())
    {
        all_filled = false;
    }
    else if (!ui->checkBoxCheckoutAgree2->isChecked())
    {
        all_filled = false;
    }

    if (!all_filled)
    {
        ui->labelFieldsNotFilled->setVisible(true);
    }
    else
    {
        ui->labelFieldsNotFilled->setVisible(false);
        // do stuff idk
    }


}

