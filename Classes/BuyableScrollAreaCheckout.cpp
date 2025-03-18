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
#include "BuyableScrollAreaCheckout.h"
#include "Clothing.h"
#include "Service.h"
#include "StoreSystem.h"

void BuyableScrollAreaCheckout::populateBuyables(QVBoxLayout *layout)
{
    StoreSystem &system = StoreSystem::getInstance();
    std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> buyables = system.getCart().getBuyables();

    for (auto &buyable : *buyables) {
        generatePanel(buyable, layout);
    }
}

void BuyableScrollAreaCheckout::displayBuyables() {}

void BuyableScrollAreaCheckout::generatePanel(std::shared_ptr<Buyable> &buyable, QVBoxLayout *layout)
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

    layout->addWidget(productPanel);

    QFrame *sepLine = new QFrame();
    sepLine->setFrameShape(QFrame::HLine);
    sepLine->setFrameShadow(QFrame::Plain);
    sepLine->setLineWidth(1);
    layout->addWidget(sepLine);
}

BuyableScrollAreaCheckout::BuyableScrollAreaCheckout(QScrollArea *scrollArea)
    : BuyableScrollArea(scrollArea)
{}

BuyableScrollAreaCheckout::BuyableScrollAreaCheckout()
    : BuyableScrollArea()
{}
