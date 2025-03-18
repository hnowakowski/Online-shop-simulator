#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include <memory>
#include <string>
#include <typeinfo>

#include "../mainwindow.h"
#include "BuyableScrollAreaCart.h"
#include "Clothing.h"
#include "Service.h"
#include "StoreSystem.h"

void BuyableScrollAreaCart::populateBuyables(QVBoxLayout *layout)
{
    StoreSystem &system = StoreSystem::getInstance();
    std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> buyables = system.getCart().getBuyables();

    for (auto &buyable : *buyables) {
        generatePanel(buyable, layout);
    }
}

void BuyableScrollAreaCart::displayBuyables() {}

void BuyableScrollAreaCart::generatePanel(std::shared_ptr<Buyable> &buyable, QVBoxLayout *layout)
{
    QWidget *productPanel = new QWidget();
    QHBoxLayout *productLayout = new QHBoxLayout(productPanel);

    QLabel *imageLabel = new QLabel();
    std::string imgPath = (PATH + buyable->getImage()).c_str();
    QPixmap pixmap(imgPath.c_str());
    imageLabel->setPixmap(pixmap.scaled(100, 100));
    productLayout->addWidget(imageLabel);

    QWidget *infoPanel = new QWidget();
    QVBoxLayout *infoLayout = new QVBoxLayout(infoPanel);

    QLabel *nameLabel = new QLabel(QString::fromStdString(buyable->getName()));
    QFont nameFont = nameLabel->font();
    nameFont.setPointSize(14);
    nameFont.setBold(true);
    nameLabel->setFont(nameFont);
    infoLayout->addWidget(nameLabel);

    std::shared_ptr<Price> price = buyable->getPrice();
    std::string priceText = std::to_string(price->getMainUnit()) + "."
                            + std::to_string(price->getSubUnit()) + " ZŁ";

    QLabel *priceLabel = new QLabel(QString::fromStdString(priceText));
    QFont priceFont = priceLabel->font();
    priceFont.setPointSize(12);
    priceLabel->setFont(priceFont);
    priceLabel->setWordWrap(true);
    infoLayout->addWidget(priceLabel);

    productLayout->addWidget(infoPanel);

    QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding);
    productLayout->addItem(horizontalSpacer);

    QPushButton *removeFromCartButton = new QPushButton("Remove from cart");
    productLayout->addWidget(removeFromCartButton);

    QObject::connect(removeFromCartButton, &QPushButton::clicked, [buyable, this]() {
        StoreSystem &system = StoreSystem::getInstance();
        //qDebug() << "Removing " << currentBuyable->getName() << " from cart.";
        if (std::shared_ptr<Product> product = std::dynamic_pointer_cast<Product>(buyable)) {
            product->setQuantity(product->getQuantity() + 1);
        }
        system.getCart().removeBuyable(buyable);
        //qDebug() << system.getCart().size();
        this->populate();
    });

    layout->addWidget(productPanel);

    QFrame *sepLine = new QFrame();
    sepLine->setFrameShape(QFrame::HLine);
    sepLine->setFrameShadow(QFrame::Plain);
    sepLine->setLineWidth(1);
    layout->addWidget(sepLine);
}

BuyableScrollAreaCart::BuyableScrollAreaCart(QScrollArea *scrollArea)
    : BuyableScrollArea(scrollArea)
{}

BuyableScrollAreaCart::BuyableScrollAreaCart()
    : BuyableScrollArea()
{}
