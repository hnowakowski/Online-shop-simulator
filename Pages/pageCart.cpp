#include <QMessageBox>
#include <string>

#include "../Classes/BuyableScrollAreaCheckout.h"
#include "../Classes/StoreSystem.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

void MainWindow::on_btnCartGotoMain_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}

void MainWindow::UpdateCartTotalPrice()
{
    std::pair<uint32_t, uint32_t> pricePair = StoreSystem::GetInstance().GetCart().GetTotalPrice();
    std::string priceStr = "Total: " + std::to_string(pricePair.first) + "."
                           + std::to_string(pricePair.second) + " ZŁ";
    QString priceQStr = QString::fromStdString(priceStr);
    ui->labelCartTotalPrice->setText(priceQStr);
}

void MainWindow::on_btnCartGotoCheckout_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageCheckout);
    checkoutScrollArea.Populate();
    std::pair<uint32_t, uint32_t> pricePair = StoreSystem::GetInstance().GetCart().GetTotalPrice();
    std::string priceStr = "Checkout (Total: " + std::to_string(pricePair.first) + "."
                           + std::to_string(pricePair.second) + " ZŁ)";
    QString priceQStr = QString::fromStdString(priceStr);
    ui->labelCheckout->setText(priceQStr);

    std::string currentId;
    StoreSystem::GetInstance().GetCurrentCustomerId(currentId);
    if (currentId == "U0") {
        ui->labelCheckoutLoggedInStatus->setVisible(true);
        ui->labelCheckoutWalletStatus->setText("Not logged in, wallet not available!");
    } else {
        ui->labelCheckoutLoggedInStatus->setVisible(false);
        ui->labelCheckoutWalletStatus->setText("Not logged in, wallet not available!");
        std::shared_ptr<Customer> currCustomer;
        StoreSystem::GetInstance().GetCurrentCustomer(currCustomer);
        uint32_t walletFirst = currCustomer->GetWallet()->GetMainUnit();
        uint32_t walletSecond = currCustomer->GetWallet()->GetSubUnit();
        std::string walletStr = "Wallet: " + std::to_string(walletFirst) + "."
                                + std::to_string(walletSecond) + " ZŁ";
        ui->labelCheckoutWalletStatus->setText(QString::fromStdString(walletStr));
    }
}
