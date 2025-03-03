#include <QMessageBox>
#include <string>

#include "../Classes/BuyableScrollAreaCart.h"
#include "../Classes/BuyableScrollAreaCheckout.h"
#include "../Classes/StoreSystem.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

void MainWindow::on_btnCheckoutGotoCart_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageCart);
}

bool operator>=(const std::shared_ptr<Wallet> wallet, const Price &price)
{
    if (wallet->mainunit < price.mainunit)
        return false;
    else if (wallet->mainunit == price.mainunit && wallet->subunit < price.subunit)
        return false;
    return true;
}

void MainWindow::on_btnCheckoutWallet_clicked()
{
    std::string id;
    StoreSystem::GetInstance().GetCurrentCustomerId(id);
    if (id == "U0") {
        showWarning(ui->pageCheckout, "Cannot consume", "You are not logged in!");
        return;
    }

    bool allFilled = true;
    if (!ui->checkBoxCheckoutAgree1->isChecked()) {
        allFilled = false;
    } else if (!ui->checkBoxCheckoutAgree2->isChecked()) {
        allFilled = false;
    }

    if (!allFilled) {
        ui->labelFieldsNotFilled->setText("Some fields were not selected!");
        ui->labelFieldsNotFilled->setVisible(true);
    } else {
        ui->labelFieldsNotFilled->setVisible(false);
        std::pair<uint32_t, uint32_t> pricePair
            = StoreSystem::GetInstance().GetCart().GetTotalPrice();
        Price priceObj(pricePair.first, pricePair.second);
        std::shared_ptr<Customer> currCustomer;
        StoreSystem::GetInstance().GetCurrentCustomer(currCustomer);
        if (currCustomer->GetWallet() >= priceObj) {
            showInfo(ui->pageCheckout, "Yipee!", "Products successfully consumed!");
            currCustomer->GetWallet()->RemoveMain(pricePair.first);
            currCustomer->GetWallet()->RemoveSub(pricePair.second);
            StoreSystem::GetInstance().GetCart().GetBuyables().clear();

            qDebug() << StoreSystem::GetInstance().GetCart().Size();
            emit StoreSystem::GetInstance().GetCart().CartChanged();

            displayAccountInfo();
            cartScrollArea.Populate();
            checkoutScrollArea.Populate();
            UpdateCartTotalPrice();
            ui->labelCheckout->setText("Checkout (Total: 0.0 ZŁ)");
            uint32_t walletFirst = currCustomer->GetWallet()->GetMainUnit();
            uint32_t walletSecond = currCustomer->GetWallet()->GetSubUnit();
            std::string walletStr = "Wallet: " + std::to_string(walletFirst) + "."
                                    + std::to_string(walletSecond) + " ZŁ";
            ui->labelCheckoutWalletStatus->setText(QString::fromStdString(walletStr));
        } else {
            showWarning(ui->pageCheckout, "Cannot consume", "Not enough funds in your account! :(");
        }
    }
}

void MainWindow::on_btnCheckoutCard_clicked()
{
    bool allFilled = true;
    if (ui->lineEditCardNum->text().isEmpty()) {
        allFilled = false;
    } else if (ui->lineEditPin->text().isEmpty()) {
        allFilled = false;
    } else if (ui->lineEditExpiryDate->text().isEmpty()) {
        allFilled = false;
    } else if (ui->lineEditNumOnBack->text().isEmpty()) {
        allFilled = false;
    } else if (!ui->checkBoxCheckoutAgree1->isChecked()) {
        allFilled = false;
    } else if (!ui->checkBoxCheckoutAgree2->isChecked()) {
        allFilled = false;
    }

    if (!allFilled) {
        ui->labelFieldsNotFilled->setText("Some fields were not filled in or selected!");
        ui->labelFieldsNotFilled->setVisible(true);
    } else {
        showInfo(ui->pageCheckout, "Yipee!", "Products successfully consumed!");
        StoreSystem::GetInstance().GetCart().GetBuyables().clear();
        qDebug() << StoreSystem::GetInstance().GetCart().Size();
        emit StoreSystem::GetInstance().GetCart().CartChanged();
        cartScrollArea.Populate();
        checkoutScrollArea.Populate();
        UpdateCartTotalPrice();
        ui->labelCheckout->setText("Checkout (Total: 0.0 ZŁ)");
    }
}
