#include <string>
#include <QMessageBox>

#include "mainwindow.h"
#include "Classes/BuyableScrollAreaCart.h"
#include "Classes/BuyableScrollAreaMain.h"
#include "Classes/StoreSystem.h"
#include "Templates/LoaderSaver.h"
#include "ui_mainwindow.h"

void loadBuyables();
void loadCustomers();

//put this somewhere else later but this is useful
void showInfo(QWidget* parent, std::string title, std::string text)
{
    QMessageBox::information(parent, QString::fromStdString(title), QString::fromStdString(text));
}

void showWarning(QWidget* parent, std::string title, std::string text)
{
    QMessageBox::warning(parent, QString::fromStdString(title), QString::fromStdString(text));
}

void showError(QWidget* parent, std::string title, std::string text)
{
    QMessageBox::critical(parent, QString::fromStdString(title), QString::fromStdString(text));
}


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    StoreSystem& system = StoreSystem::GetInstance();
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    loadBuyables();
    loadCustomers();

    StoreSystem::GetInstance().SetCurrentCustomerId("U1"); //for testing, later on we can start off as logged out and then make the user log in/register
    ui->stackedWidgetLogin->setCurrentWidget(ui->pageLoginLoggedIn); //temp for testing, could start off as a logged in user for ease of use
    displayAccountInfo();


    mainScrollArea     = BuyableScrollAreaMain(ui->scrollAreaProducts);
    cartScrollArea     = BuyableScrollAreaCart(ui->scrollAreaCart);
    checkoutScrollArea = BuyableScrollAreaCart(ui->scrollAreaCheckout);

    QStringList comboBoxItems = {"All", "Products", "Clothes", "Services"};
    ui->comboBoxSearch->addItems(comboBoxItems);

    QObject::connect(&system.GetCart(), &Cart::CartChanged, this, &MainWindow::UpdateCartLabel);





    // end of setup, final function calls
    // KEEP THIS AT THE BOTTOM AT ALL TIMES
    ui->labelFieldsNotFilled->setVisible(false);
    ui->labelLoginBadData->setVisible(false);
    mainScrollArea.Populate();
    UpdateCartLabel();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::displayAccountInfo()
{
    StoreSystem& system = StoreSystem::GetInstance();
    std::shared_ptr<Customer> currCustomer;
    system.GetCurrentCustomer(currCustomer);
    ui->labelUserLogin->setText(QString::fromStdString(currCustomer->GetName() + " " + currCustomer->GetSurname()));
    uint32_t walletFirst   = currCustomer->GetWallet()->GetMainUnit();
    uint32_t walletSecond  = currCustomer->GetWallet()->GetSubUnit();
    std::string walletStr  = "Wallet: " + std::to_string(walletFirst) + "." + std::to_string(walletSecond) + " ZŁ";
    ui->labelWalletStatus->setText(QString::fromStdString(walletStr));
}

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

//where do i put this
bool operator>=(const std::shared_ptr<Wallet> wallet, const Price& price)
{
    if (wallet->mainunit < price.mainunit) return false;
    else if (wallet->mainunit == price.mainunit && wallet->subunit < price.subunit) return false;
    return true;
}

void MainWindow::on_btnCheckout_clicked()
{
    std::string id;
    StoreSystem::GetInstance().GetCurrentCustomerId(id);
    if (id == "U0")
    {
        showWarning(ui->pageCheckout, "Cannot consume", "You are not logged in!");
        return;
    }

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
        std::pair<uint32_t, uint32_t> pricePair = StoreSystem::GetInstance().GetCart().GetTotalPrice();
        Price priceObj(pricePair.first, pricePair.second);
        std::shared_ptr<Customer> currCustomer;
        StoreSystem::GetInstance().GetCurrentCustomer(currCustomer);
        if (currCustomer->GetWallet() >= priceObj)
        {
            showInfo(ui->pageCheckout, "Yipee!", "Products successfully consumed!");
            currCustomer->GetWallet()->RemoveMain(pricePair.first);
            currCustomer->GetWallet()->RemoveSub(pricePair.second);
        }
        else
        {
            showWarning(ui->pageCheckout, "Cannot consume", "Not enough funds in your account! :(");
        }

    }


}


void MainWindow::on_btnCheckoutGotoCart_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageCart);
}


void MainWindow::on_btnLoginGotoSignUp_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageSignUp);
}


void MainWindow::on_btnMainGotoLogin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageLogIn);
}


void MainWindow::on_btnLoginGotoMain_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}


void MainWindow::on_btnSignUpGotoLogin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageLogIn);
}


void MainWindow::on_btnLogout_clicked()
{
    ui->stackedWidgetLogin->setCurrentWidget(ui->pageLoginLoggedOut);
    StoreSystem::GetInstance().SetCurrentCustomerId("U0");
}


void MainWindow::on_btnLogIn_clicked()
{
    if(ui->lineEditLoginEmail->text().isEmpty() || ui->lineEditLoginPassword->text().isEmpty())
    {
        ui->labelLoginBadData->setText(QString::fromStdString("Some fields have not been filled in!"));
        ui->labelLoginBadData->setVisible(true);
    }
    else
    {
        Listing<std::shared_ptr<Customer>> customers;
        StoreSystem::GetInstance().GetCustomers(customers);
        QString formEmail = ui->lineEditLoginEmail->text();
        QString formPassword = ui->lineEditLoginPassword->text();
        if (customers.GetSize())
        {
            for (const auto& customer : customers)
            {
                QString qEmail = QString::fromStdString(customer->GetEmail());
                QString qPassword = QString::fromStdString(customer->GetPassword());
                if (qEmail == formEmail && qPassword == formPassword)
                {
                    ui->labelLoginBadData->setVisible(false);
                    StoreSystem::GetInstance().SetCurrentCustomerId(customer->GetId());
                    displayAccountInfo();
                    ui->stackedWidgetLogin->setCurrentWidget(ui->pageLoginLoggedIn);
                    ui->stackedWidget->setCurrentWidget(ui->pageMain);
                    return;
                }
            }
        }
        ui->labelLoginBadData->setText(QString::fromStdString("Email or password are incorrect!"));
        ui->labelLoginBadData->setVisible(true);
    }
}

