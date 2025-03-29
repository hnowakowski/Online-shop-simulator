#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Classes/ItemScrollAreaCart.h"
#include "Classes/ItemScrollAreaCheckout.h"
#include "Classes/ItemScrollAreaMain.h"
#include "ui_mainwindow.h"

#define PATH (std::filesystem::current_path().string() + "\\..\\..\\")

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBoxSearch_currentIndexChanged(int index);

    void on_btnSearch_clicked();

    void on_radioSortName_clicked();

    void on_radioSortPrice_clicked();

    void on_radioRating_clicked();

    void updateCartLabel();

    void updateCartTotalPrice();

    void on_btnMainGotoCart_clicked();

    void on_btnCartGotoMain_clicked();

    void on_btnCartGotoCheckout_clicked();

    void on_btnCheckoutGotoCart_clicked();

    void on_btnLoginGotoSignUp_clicked();

    void on_btnMainGotoLogin_clicked();

    void on_btnLoginGotoMain_clicked();

    void on_btnSignUpGotoLogin_clicked();

    void on_btnLogout_clicked();

    void on_btnLogIn_clicked();

    void on_btnSignUp_clicked();

    void on_btnCheckoutWallet_clicked();

    void on_btnCheckoutCard_clicked();

private:
    Ui::MainWindow *ui;
    ItemScrollAreaMain mainScrollArea;
    ItemScrollAreaCart cartScrollArea;
    ItemScrollAreaCheckout checkoutScrollArea;

    void showInfo(QWidget *parent, std::string title, std::string text);
    void showWarning(QWidget *parent, std::string title, std::string text);
    void showError(QWidget *parent, std::string title, std::string text);
    void displayAccountInfo();
    void loadBuyables();
    void loadCustomers();
};
#endif // MAINWINDOW_H
