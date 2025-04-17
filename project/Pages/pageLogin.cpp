#include <QMessageBox>
#include <string>

#include "../Classes/StoreSystem.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

void MainWindow::on_btnLoginGotoMain_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}

void MainWindow::on_btnLoginGotoSignUp_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageSignUp);
}

void MainWindow::on_btnLogIn_clicked()
{
    if (ui->lineEditLoginEmail->text().isEmpty() || ui->lineEditLoginPassword->text().isEmpty()) {
        ui->labelLoginBadData->setText(QString::fromStdString("Some fields have not been filled in!"));
        ui->labelLoginBadData->setVisible(true);
    } else {
        if (!ui->lineEditLoginEmail->text().contains("@") || !ui->lineEditLoginEmail->text().contains(".")) {
            ui->labelLoginBadData->setText(QString::fromStdString("Please input a valid email address!"));
            ui->labelLoginBadData->setVisible(true);
        } else {
            StoreSystem &system = StoreSystem::getInstance();
            auto customers = system.getCustomers();
            QString formEmail = ui->lineEditLoginEmail->text();
            std::string formPassword = ui->lineEditLoginPassword->text().toStdString();

            if (customers->size()) {
                for (const auto &customer : *customers) {
                    QString qEmail = QString::fromStdString(customer->getEmail());

                    if (qEmail == formEmail && customer->checkPassword(formPassword)) {
                        ui->labelLoginBadData->setVisible(false);
                        StoreSystem::getInstance().setCurrentCustomerId(customer->getId());
                        displayAccountInfo();
                        ui->stackedWidgetLogin->setCurrentWidget(ui->pageLoginLoggedIn);
                        ui->stackedWidget->setCurrentWidget(ui->pageMain);
                        ui->lineEditLoginEmail->setText("");
                        ui->lineEditLoginPassword->setText("");
                        return;
                    }
                }
            }
            ui->labelLoginBadData->setText("Email or password are incorrect!");
            ui->labelLoginBadData->setVisible(true);
        }
    }
}
