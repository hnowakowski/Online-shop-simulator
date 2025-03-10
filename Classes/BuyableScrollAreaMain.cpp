#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include <memory>
#include <string>

#include "../mainwindow.h"
#include "BuyableScrollAreaMain.h"
#include "Clothing.h"
#include "Service.h"
#include "StoreSystem.h"

void BuyableScrollAreaMain::populate()
{
    QWidget *container = scrollArea->widget();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(container->layout());
    StoreSystem &system = StoreSystem::getInstance();
    std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> buyables = system.getBuyables();
    if (buyables->empty()) {
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

    BuyableDisplayedType displayedType = system.getBuyableDisplayedType();
    std::string query = system.getBuyableSearchQuery();
    BuyableSortedBy sortedBy = system.getBuyableSortedBy();

    switch (sortedBy) {
    case BuyableSortedBy::NAME:
        system.sortBuyables(
            [](const std::shared_ptr<Buyable> &a, const std::shared_ptr<Buyable> &b) {
                return a->getName() < b->getName();
            });
        for (const auto &b : *buyables) {
            qDebug() << b->getName();
        }
        break;
    case BuyableSortedBy::PRICE:
        system.sortBuyables(
            [](const std::shared_ptr<Buyable> &a, const std::shared_ptr<Buyable> &b) {
                return a->getPrice() < b->getPrice();
            });
        break;
    case BuyableSortedBy::RATING:
        system.sortBuyables(
            [](const std::shared_ptr<Buyable> &a, const std::shared_ptr<Buyable> &b) {
                return std::stof(a->getRating()) > std::stof(b->getRating());
            });
        break;
    }

    for (auto &buyable : *buyables) {
        // filtering
        switch (displayedType) {
        case BuyableDisplayedType::ALL:
            break;
        case BuyableDisplayedType::PRODUCT:
            if (!std::dynamic_pointer_cast<Product>(buyable)) {
                continue;
            }
            break;
        case BuyableDisplayedType::CLOTHING:
            if (!std::dynamic_pointer_cast<Clothing>(buyable)) {
                continue;
            }
            break;
        case BuyableDisplayedType::SERVICE:
            if (!std::dynamic_pointer_cast<Service>(buyable)) {
                continue;
            }
            break;
        }

        if (!query.empty()) {
            QString qName = QString::fromStdString(buyable->getName());
            QString qQuery = QString::fromStdString(query);

            if (!qName.contains(qQuery, Qt::CaseInsensitive)) {
                continue;
            }
        }

        // actual display

        QWidget *productPanel = new QWidget();
        QHBoxLayout *productLayout = new QHBoxLayout(productPanel);

        QLabel *imageLabel = new QLabel();
        std::string imgPath = (PATH + buyable->getImage()).c_str();
        QPixmap pixmap(imgPath.c_str());
        imageLabel->setPixmap(pixmap.scaled(200, 200));
        productLayout->addWidget(imageLabel);

        QWidget *infoPanel = new QWidget();
        QVBoxLayout *infoLayout = new QVBoxLayout(infoPanel);

        QLabel *nameLabel = new QLabel(QString::fromStdString(buyable->getName()));
        QFont nameFont = nameLabel->font();
        nameFont.setPointSize(12);
        nameFont.setBold(true);
        nameLabel->setFont(nameFont);
        infoLayout->addWidget(nameLabel);

        QLabel *ratingLabel = new QLabel(QString::fromStdString(buyable->getRating() + "/10"));
        ratingLabel->setWordWrap(true);
        infoLayout->addWidget(ratingLabel);

        QLabel *descriptionLabel = new QLabel(QString::fromStdString(buyable->getDescription()));
        descriptionLabel->setWordWrap(true);
        infoLayout->addWidget(descriptionLabel);

        productLayout->addWidget(infoPanel);

        QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding);
        productLayout->addItem(horizontalSpacer);

        QWidget *buttonPanel = new QWidget();
        QVBoxLayout *buttonLayout = new QVBoxLayout(buttonPanel);

        QSpacerItem *vButtonSpacerTop = new QSpacerItem(40,
                                                        20,
                                                        QSizePolicy::Minimum,
                                                        QSizePolicy::Expanding);
        buttonLayout->addItem(vButtonSpacerTop);

        QPushButton *addToCartButton = new QPushButton("Add to Cart");
        buttonLayout->addWidget(addToCartButton);

        std::shared_ptr<Buyable> currentBuyable = buyable;
        QObject::connect(addToCartButton, &QPushButton::clicked, [currentBuyable]() {
            StoreSystem &system = StoreSystem::getInstance();
            qDebug() << "Adding " << currentBuyable->getName() << " to cart.";
            system.getCart().addBuyable(currentBuyable);
            qDebug() << system.getCart().size();
        });

        std::shared_ptr<Price> price = buyable->getPrice();
        std::string priceText = std::to_string(price->getMainUnit()) + "."
                                + std::to_string(price->getSubUnit()) + " ZŁ";

        QLabel *priceLabel = new QLabel(QString::fromStdString(priceText));
        priceLabel->setWordWrap(true);
        buttonLayout->addWidget(priceLabel);

        QSpacerItem *vButtonSpacerBottom = new QSpacerItem(40,
                                                           20,
                                                           QSizePolicy::Minimum,
                                                           QSizePolicy::Expanding);
        buttonLayout->addItem(vButtonSpacerBottom);

        productLayout->addWidget(buttonPanel);

        layout->addWidget(productPanel);

        QFrame *sepLine = new QFrame();
        sepLine->setFrameShape(QFrame::HLine);
        sepLine->setFrameShadow(QFrame::Plain);
        sepLine->setLineWidth(1);
        layout->addWidget(sepLine);
    }

    scrollArea->widget()->adjustSize();
}

BuyableScrollAreaMain::BuyableScrollAreaMain(QScrollArea *scrollArea)
    : BuyableScrollArea(scrollArea)
{}

BuyableScrollAreaMain::BuyableScrollAreaMain()
    : BuyableScrollArea()
{}
