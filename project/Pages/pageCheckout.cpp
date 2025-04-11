#include <QMessageBox>
#include <QRegularExpression>
#include <string>

#include "../Classes/ItemScrollAreaCart.h"
#include "../Classes/ItemScrollAreaCheckout.h"
#include "../Classes/StoreSystem.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

void MainWindow::on_btnCheckoutGotoCart_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageCart);
}

void MainWindow::on_btnCheckoutWallet_clicked()
{
    StoreSystem &system = StoreSystem::getInstance();
    std::string id = system.getCurrentCustomerId();
    if (id == "U0") {
        showWarning(ui->pageCheckout, "Cannot purchase", "You are not logged in!");
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
        std::shared_ptr<Price> totalPrice = system.getCart().getTotalPrice();
        std::shared_ptr<Customer> currCustomer = system.getCurrentCustomer();
        if (*currCustomer->getWallet() >= *totalPrice) {
            showInfo(ui->pageCheckout, "Yipee!", "Products successfully purchased!");
            currCustomer->getWallet()->subtractMain(totalPrice->getMainUnit());
            currCustomer->getWallet()->subtractSub(totalPrice->getSubUnit());
            system.getCart().getItems()->clear();

            qDebug() << system.getCart().size();
            emit system.getCart().cartChanged();

            displayAccountInfo();
            cartScrollArea.populate();
            checkoutScrollArea.populate();
            updateCartTotalPrice();
            ui->labelCheckout->setText("Checkout (Total: 0.0 ZŁ)");
            uint32_t walletFirst = currCustomer->getWallet()->getMainUnit();
            uint32_t walletSecond = currCustomer->getWallet()->getSubUnit();
            std::string walletStr = "Wallet: " + std::to_string(walletFirst) + "." + std::to_string(walletSecond) + " ZŁ";
            ui->labelCheckoutWalletStatus->setText(QString::fromStdString(walletStr));
        } else {
            showWarning(ui->pageCheckout, "Cannot purchase", "Not enough funds in your account! :(");
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
        static const QRegularExpression reg1("^\\d{16}");
        static const QRegularExpression reg2("^\\d{4}");
        static const QRegularExpression reg3("^\\d{2}/\\d{2}");
        static const QRegularExpression reg4("^\\d{3}");
        if (ui->lineEditCardNum->text().length() != ui->lineEditCardNum->maxLength() || !reg1.match(ui->lineEditCardNum->text()).hasMatch()) {
            ui->labelFieldsNotFilled->setText("Please input a valid card number!");
            ui->labelFieldsNotFilled->setVisible(true);
        } else if (ui->lineEditPin->text().length() != ui->lineEditPin->maxLength() || !reg2.match(ui->lineEditPin->text()).hasMatch()) {
            ui->labelFieldsNotFilled->setText("Please input a valid PIN!");
            ui->labelFieldsNotFilled->setVisible(true);
        } else if (ui->lineEditExpiryDate->text().length() != ui->lineEditExpiryDate->maxLength() || !reg3.match(ui->lineEditExpiryDate->text()).hasMatch()) {
            ui->labelFieldsNotFilled->setText("Please input a valid expiry date! Format MM/YY");
            ui->labelFieldsNotFilled->setVisible(true);
        } else if (ui->lineEditNumOnBack->text().length() != ui->lineEditNumOnBack->maxLength() || !reg4.match(ui->lineEditNumOnBack->text()).hasMatch()) {
            ui->labelFieldsNotFilled->setText("Please input valid numbers on the back!");
            ui->labelFieldsNotFilled->setVisible(true);
        } else {
            showInfo(ui->pageCheckout, "Yipee!", "Products successfully purchased!");
            StoreSystem &system = StoreSystem::getInstance();
            system.getCart().getItems()->clear();
            qDebug() << system.getCart().size();
            emit system.getCart().cartChanged();
            cartScrollArea.populate();
            checkoutScrollArea.populate();
            updateCartTotalPrice();
            ui->labelCheckout->setText("Checkout (Total: 0.0 ZŁ)");
        }
    }
}
