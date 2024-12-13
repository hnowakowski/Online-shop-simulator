#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Headers/Setupers/pageMain.h"
#include "Templates/LoaderSaver.h"
#include "Headers/Core/Product.h"
#include "Headers/CustomWidgets/ProductScrollArea.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    std::vector<std::shared_ptr<Product>> products;
    if(LoaderSaver<Product>::Load("C:\\Users\\SilverBoi\\Desktop\\hackerman stuff\\uni stuff\\oop\\shop_project\\Assets\\products.json", products)){
        std::cout<<"Products loaded!\n";
    }
    ProductScrollArea test(ui->scrollAreaProducts, products);
    test.Populate();
}

MainWindow::~MainWindow()
{
    delete ui;
}


