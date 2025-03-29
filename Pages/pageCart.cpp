#include <QMessageBox>
#include <string>

#include "../Classes/ItemScrollAreaCheckout.h"
#include "../Classes/StoreSystem.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

void MainWindow::on_btnCartGotoMain_clicked()
{
    mainScrollArea.displayItems();
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}

void MainWindow::updateCartTotalPrice()
{
    std::shared_ptr<Price> totalPrice = StoreSystem::getInstance().getCart().getTotalPrice();
    std::string priceStr = "Total: " + std::to_string(totalPrice->getMainUnit()) + "."
                           + std::to_string(totalPrice->getSubUnit()) + " ZŁ";
    QString priceQStr = QString::fromStdString(priceStr);
    ui->labelCartTotalPrice->setText(priceQStr);
}

void MainWindow::on_btnCartGotoCheckout_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageCheckout);
    checkoutScrollArea.populate();
    std::shared_ptr<Price> totalPrice = StoreSystem::getInstance().getCart().getTotalPrice();
    std::string priceStr = "Checkout (Total: " + std::to_string(totalPrice->getMainUnit()) + "."
                           + std::to_string(totalPrice->getSubUnit()) + " ZŁ)";
    QString priceQStr = QString::fromStdString(priceStr);
    ui->labelCheckout->setText(priceQStr);

    StoreSystem &system = StoreSystem::getInstance();
    std::string currentId = system.getCurrentCustomerId();
    if (currentId == "U0") {
        ui->labelCheckoutLoggedInStatus->setVisible(true);
        ui->labelCheckoutWalletStatus->setText("Not logged in, wallet not available!");
    } else {
        ui->labelCheckoutLoggedInStatus->setVisible(false);
        ui->labelCheckoutWalletStatus->setText("Not logged in, wallet not available!");
        std::shared_ptr<Customer> currCustomer = system.getCurrentCustomer();
        uint32_t walletFirst = currCustomer->getWallet()->getMainUnit();
        uint32_t walletSecond = currCustomer->getWallet()->getSubUnit();
        std::string walletStr = "Wallet: " + std::to_string(walletFirst) + "."
                                + std::to_string(walletSecond) + " ZŁ";
        ui->labelCheckoutWalletStatus->setText(QString::fromStdString(walletStr));
    }
}
