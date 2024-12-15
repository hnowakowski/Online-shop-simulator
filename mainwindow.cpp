#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    if(LoaderSaver<Product>::Load(PATH + "Assets\\products.json", products)){
        qDebug() <<"Products loaded!\n";
    }
    ProductScrollArea test(ui->scrollAreaProducts, products);
    test.Populate();
    //qDebug() << "Curr path: " << PATH;

}

MainWindow::~MainWindow()
{
    delete ui;
}


