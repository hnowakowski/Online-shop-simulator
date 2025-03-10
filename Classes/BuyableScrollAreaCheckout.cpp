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

void BuyableScrollAreaCheckout::populate()
{
    QWidget *container = scrollArea->widget();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(container->layout());
    StoreSystem &system = StoreSystem::getInstance();
    std::vector<std::shared_ptr<Buyable>> buyables = system.getCart().getBuyables();

    if (buyables.empty()) {
        qDebug() << "WARNING! - No buyables in storesystem to display!\n";
    }

    if (!layout) {
        layout = new QVBoxLayout(container);
        container->setLayout(layout);
    }

    while (QLayoutItem *item = layout->takeAt(0)) {
        delete item->widget();
        delete item;
    }

    for (auto &buyable : buyables) {
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
}

BuyableScrollAreaCheckout::BuyableScrollAreaCheckout(QScrollArea *scrollArea)
    : BuyableScrollArea(scrollArea)
{}

BuyableScrollAreaCheckout::BuyableScrollAreaCheckout()
    : BuyableScrollArea()
{}
