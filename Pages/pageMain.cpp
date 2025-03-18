#include <QMessageBox>
#include <QPixmap>
#include <string>

#include "../Classes/BuyableScrollAreaCart.h"
#include "../Classes/BuyableScrollAreaCheckout.h"
#include "../Classes/BuyableScrollAreaMain.h"
#include "../Classes/StoreSystem.h"
#include "../Templates/LoaderSaver.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

void MainWindow::showInfo(QWidget *parent, std::string title, std::string text)
{
    QMessageBox::information(parent, QString::fromStdString(title), QString::fromStdString(text));
}

void MainWindow::showWarning(QWidget *parent, std::string title, std::string text)
{
    QMessageBox::warning(parent, QString::fromStdString(title), QString::fromStdString(text));
}

void MainWindow::showError(QWidget *parent, std::string title, std::string text)
{
    QMessageBox::critical(parent, QString::fromStdString(title), QString::fromStdString(text));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    StoreSystem &system = StoreSystem::getInstance();
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    loadBuyables();
    loadCustomers();

    StoreSystem::getInstance().setCurrentCustomerId("U1");
    ui->stackedWidgetLogin->setCurrentWidget(ui->pageLoginLoggedIn);
    displayAccountInfo();

    mainScrollArea = BuyableScrollAreaMain(ui->scrollAreaProducts);
    cartScrollArea = BuyableScrollAreaCart(ui->scrollAreaCart);
    checkoutScrollArea = BuyableScrollAreaCheckout(ui->scrollAreaCheckout);

    QStringList comboBoxItems = {"All", "Products", "Clothes", "Services"};
    ui->comboBoxSearch->addItems(comboBoxItems);

    QObject::connect(&system.getCart(), &Cart::cartChanged, this, &MainWindow::updateCartLabel);
    QObject::connect(&system.getCart(), &Cart::cartChanged, this, &MainWindow::updateCartTotalPrice);

    QPixmap pixmapLogo((PATH + "Assets\\Images\\UI\\logo.png").c_str());
    QPixmap pixmapAd1((PATH + "Assets\\Images\\UI\\ad1.png").c_str());
    QPixmap pixmapAd2((PATH + "Assets\\Images\\UI\\ad2.png").c_str());
    QPixmap pixmapAd3((PATH + "Assets\\Images\\UI\\ad3.png").c_str());
    QPixmap pixmapAd4((PATH + "Assets\\Images\\UI\\ad4.png").c_str());

    ui->labelLogoImage->setPixmap(pixmapLogo.scaled(125, 125));
    ui->labelMainAd1->setPixmap(pixmapAd1.scaled(125, 450));
    ui->labelCartAd1->setPixmap(pixmapAd2.scaled(200, 720));
    ui->labelCheckoutAd1->setPixmap(pixmapAd3.scaled(200, 720));
    ui->labelLoginAd1->setPixmap(pixmapAd2.scaled(200, 720));
    ui->labelLoginAd2->setPixmap(pixmapAd4.scaled(200, 720));
    ui->labelSingUpAd1->setPixmap(pixmapAd3.scaled(200, 720));
    ui->labelSignUpAd2->setPixmap(pixmapAd1.scaled(200, 720));

    ui->labelCheckoutLoggedInStatus->setVisible(false);
    ui->labelSignUpBadData->setVisible(false);
    ui->labelFieldsNotFilled->setVisible(false);
    ui->labelLoginBadData->setVisible(false);
    mainScrollArea.populate();
    mainScrollArea.displayBuyables();
    updateCartLabel();
    updateCartTotalPrice();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAccountInfo()
{
    StoreSystem &system = StoreSystem::getInstance();
    std::shared_ptr<Customer> currCustomer = system.getCurrentCustomer();
    ui->labelUserLogin->setText(
        QString::fromStdString(currCustomer->getName() + " " + currCustomer->getSurname()));
    uint32_t walletFirst = currCustomer->getWallet()->getMainUnit();
    uint32_t walletSecond = currCustomer->getWallet()->getSubUnit();
    std::string walletStr = "Wallet: " + std::to_string(walletFirst) + "."
                            + std::to_string(walletSecond) + " ZŁ";
    ui->labelWalletStatus->setText(QString::fromStdString(walletStr));
}

void MainWindow::loadBuyables()
{
    std::vector<std::shared_ptr<Buyable>> loadedBuyables;
    StoreSystem &system = StoreSystem::getInstance();
    if (!LoaderSaver<Buyable>::load(PATH + "Assets\\products.json", loadedBuyables)) {
        qDebug() << "WARNING! - Loading products.json failed!\n";
    }
    if (!LoaderSaver<Buyable>::load(PATH + "Assets\\services.json", loadedBuyables)) {
        qDebug() << "WARNING! - Loading services.json failed!\n";
    }
    for (auto &buyable : loadedBuyables) {
        system.addBuyable(buyable);
    }
}

void MainWindow::loadCustomers()
{
    std::vector<std::shared_ptr<Customer>> loadedCustomers;
    StoreSystem &system = StoreSystem::getInstance();
    if (!LoaderSaver<Customer>::load(PATH + "Assets\\customers.json", loadedCustomers)) {
        qDebug() << "WARNING! - Loading customers.json failed!\n";
    }
    for (auto &customer : loadedCustomers) {
        system.addCustomer(customer);
    }
}

void MainWindow::on_comboBoxSearch_currentIndexChanged(int index)
{
    StoreSystem &system = StoreSystem::getInstance();
    BuyableDisplayedType type = BuyableDisplayedType::ALL;
    switch (index) {
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
    system.setBuyableDisplayedType(type);
}

void MainWindow::on_btnSearch_clicked()
{
    StoreSystem &system = StoreSystem::getInstance();
    QString query = ui->lineEditSearch->text();
    system.setBuyableSearchQuery(query.toStdString());
    mainScrollArea.displayBuyables();
}

void MainWindow::on_radioSortName_clicked()
{
    StoreSystem &system = StoreSystem::getInstance();
    system.setBuyableSortedBy(BuyableSortedBy::NAME);
    mainScrollArea.displayBuyables();
}

void MainWindow::on_radioSortPrice_clicked()
{
    StoreSystem &system = StoreSystem::getInstance();
    system.setBuyableSortedBy(BuyableSortedBy::PRICE);
    mainScrollArea.displayBuyables();
}

void MainWindow::on_radioRating_clicked()
{
    StoreSystem &system = StoreSystem::getInstance();
    system.setBuyableSortedBy(BuyableSortedBy::RATING);
    mainScrollArea.displayBuyables();
}

void MainWindow::updateCartLabel()
{
    uint32_t size = StoreSystem::getInstance().getCart().size();
    QString label = QString::fromStdString("Cart (" + std::to_string(size) + ")");
    ui->labelCart->setText(label);
}

void MainWindow::on_btnMainGotoCart_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageCart);
    cartScrollArea.displayBuyables();
    updateCartTotalPrice();
}

void MainWindow::on_btnMainGotoLogin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageLogIn);
}

void MainWindow::on_btnLogout_clicked()
{
    ui->stackedWidgetLogin->setCurrentWidget(ui->pageLoginLoggedOut);
    StoreSystem::getInstance().setCurrentCustomerId("U0");
}
