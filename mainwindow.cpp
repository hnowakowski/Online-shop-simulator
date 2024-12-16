#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Templates/LoaderSaver.h"
#include "Headers/Core/Product.h"
#include "Headers/CustomWidgets/BuyableScrollAreaMain.h"

void loadBuyables(std::vector<std::shared_ptr<Buyable>>& buyables);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    std::vector<std::shared_ptr<Buyable>> buyables;
    loadBuyables(buyables);
    BuyableScrollAreaMain test(ui->scrollAreaProducts, buyables);
    test.Populate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void loadBuyables(std::vector<std::shared_ptr<Buyable>>& buyables){
    if(!LoaderSaver<Buyable>::Load(PATH + "Assets\\products.json", buyables)){
        qDebug() <<"WARNING! - Loading products.json failed!\n";
    }
    if(!LoaderSaver<Buyable>::Load(PATH + "Assets\\services.json", buyables)){
        qDebug() <<"WARNING! - Loading services.json failed!\n";
    }
}

