#include <QMessageBox>
#include <string>

#include "../Classes/StoreSystem.h"
#include "../Templates/LoaderSaver.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

void MainWindow::on_btnSignUpGotoLogin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageLogIn);
}

void MainWindow::on_btnSignUp_clicked()
{
    bool allFilled = true;

    QList<QLineEdit *> lineEdits = ui->pageSignUp->findChildren<QLineEdit *>();
    for (QLineEdit *lineEdit : lineEdits) {
        if (lineEdit->text().isEmpty()) {
            allFilled = false;
            break;
        }
    }

    if (!allFilled) {
        ui->labelSignUpBadData->setText("Some fields have not been filled in!");
        ui->labelSignUpBadData->setVisible(true);
    } else {
        StoreSystem &system = StoreSystem::getInstance();
        auto customers = system.getCustomers();
        QString formEmail = ui->lineEditEmail->text();
        QString formPassword = ui->lineEditPassword->text();
        QString formPasswordR = ui->lineEditRepeatPassword->text();

        if (formPassword != formPasswordR) {
            ui->labelSignUpBadData->setText("Passwords do not match!");
            ui->labelSignUpBadData->setVisible(true);
            return;
        }

        if (customers->size()) {
            for (const auto &customer : *customers) {
                QString qEmail = QString::fromStdString(customer->getEmail());
                if (qEmail == formEmail) {
                    ui->labelSignUpBadData->setText("A user with this email already exists!");
                    ui->labelSignUpBadData->setVisible(true);
                    return;
                }
            }
        }

        std::string newId = "U" + std::to_string(customers->size() + 1);
        std::string newName = ui->lineEditFName->text().toStdString();
        std::string newSurname = ui->lineEditLName->text().toStdString();
        std::string newEmail = formEmail.toStdString();
        std::string newPhone = ui->lineEditPhoneNum->text().toStdString();
        std::string newCity = ui->lineEditCity->text().toStdString();
        std::string newAddress = ui->lineEditAddress->text().toStdString();
        std::string newPESEL = ui->lineEditPesel->text().toStdString();
        std::string newPassword = formPassword.toStdString();

        std::shared_ptr<Customer> newCustomer = std::make_shared<Customer>(newId,
                                                                           newName,
                                                                           newSurname,
                                                                           newEmail,
                                                                           newPhone,
                                                                           newCity,
                                                                           newAddress,
                                                                           newPESEL,
                                                                           newPassword);

        system.addCustomer(newCustomer);
        system.setCurrentCustomerId(newId);
        ui->labelSignUpBadData->setVisible(false);
        displayAccountInfo();

        if (!LoaderSaver<Customer>::save(PATH + "Assets\\customers.json", *customers)) {
            qDebug() << "WARNING! - Saving customers.json failed!\n";
        }
        ui->stackedWidgetLogin->setCurrentWidget(ui->pageLoginLoggedIn);
        ui->stackedWidget->setCurrentWidget(ui->pageMain);
    }
}
