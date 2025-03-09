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
        ui->labelLoginBadData->setText(
            QString::fromStdString("Some fields have not been filled in!"));
        ui->labelLoginBadData->setVisible(true);
    } else {
        StoreSystem &system = StoreSystem::GetInstance();
        auto customers = system.GetCustomers();
        QString formEmail = ui->lineEditLoginEmail->text();
        QString formPassword = ui->lineEditLoginPassword->text();

        if (customers->size()) {
            for (const auto &customer : *customers) {
                QString qEmail = QString::fromStdString(customer->GetEmail());
                QString qPassword = QString::fromStdString(customer->GetPassword());

                if (qEmail == formEmail && qPassword == formPassword) {
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
