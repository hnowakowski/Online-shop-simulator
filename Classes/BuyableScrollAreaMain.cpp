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

void BuyableScrollAreaMain::populateBuyables(QVBoxLayout *layout)
{
    StoreSystem &system = StoreSystem::getInstance();
    std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> buyables = system.getBuyables();
    if (buyables->empty()) {
        qDebug() << "WARNING! - No buyables in storesystem to display!\n";
    }

    for (auto &buyable : *buyables) {
        generatePanel(buyable, layout);
    }

    scrollArea->widget()->adjustSize();
}

void BuyableScrollAreaMain::displayBuyables()
{
    StoreSystem &system = StoreSystem::getInstance();
    BuyableDisplayedType displayedType = system.getBuyableDisplayedType();
    std::string query = system.getBuyableSearchQuery();
    BuyableSortedBy sortedBy = system.getBuyableSortedBy();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(scrollArea->widget()->layout());

    switch (sortedBy) {
    case BuyableSortedBy::NAME:
        std::sort(buyableWidgets->begin(), buyableWidgets->end(), [](const auto &a, const auto &b) {
            return a.first->getName() < b.first->getName();
        });
        // for (const auto &b : *buyables) {
        //     qDebug() << b->getName();
        // }
        break;
    case BuyableSortedBy::PRICE:
        std::sort(buyableWidgets->begin(), buyableWidgets->end(), [](const auto &a, const auto &b) {
            return *(a.first->getPrice()) < *(b.first->getPrice());
        });
        // for (const auto &b : *buyables) {
        //     qDebug() << b->getPrice()->getMainUnit() << " " << b->getPrice()->getSubUnit();
        // }
        break;
    case BuyableSortedBy::RATING:
        std::sort(buyableWidgets->begin(), buyableWidgets->end(), [](const auto &a, const auto &b) {
            return std::stof(a.first->getRating()) > std::stof(b.first->getRating());
        });
        // for (const auto &b : *buyables) {
        //     qDebug() << b->getRating();
        // }
        break;
    }

    // filtering
    for (const auto &[buyable, widget] : *buyableWidgets) {
        widget->setVisible(false);
        layout->removeWidget(widget);

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
        widget->setVisible(true);
        layout->addWidget(widget);
    }
}

void BuyableScrollAreaMain::generatePanel(std::shared_ptr<Buyable> &buyable, QVBoxLayout *layout)
{
    QWidget *buyablePanel = new QWidget();
    QVBoxLayout *buyableLayout = new QVBoxLayout(buyablePanel);

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
    infoLayout->addWidget(ratingLabel);

    QLabel *descriptionLabel = new QLabel(QString::fromStdString(buyable->getDescription()));
    //descriptionLabel->setWordWrap(true);
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

    std::string quantityText = "";

    if (std::shared_ptr<Product> product = std::dynamic_pointer_cast<Product>(buyable)) {
        uint32_t quantity = product->getQuantity();
        quantityText = "In stock: " + std::to_string(quantity);
        if (quantity == 0) {
            addToCartButton->setDisabled(true);
        }
    }
    QLabel *quantityLabel = new QLabel(QString::fromStdString(quantityText));

    QObject::connect(addToCartButton,
                     &QPushButton::clicked,
                     [buyable, quantityLabel, addToCartButton]() {
                         StoreSystem &system = StoreSystem::getInstance();
                         //qDebug() << "Adding " << buyable->getName() << " to cart.";

                         if (std::shared_ptr<Product> product = std::dynamic_pointer_cast<Product>(
                                 buyable)) {
                             product->setQuantity(product->getQuantity() - 1);

                             quantityLabel->setText(QString::fromStdString(
                                 "In stock: " + std::to_string(product->getQuantity())));

                             if (product->getQuantity() == 0) {
                                 addToCartButton->setDisabled(true);
                             }
                         }
                         system.getCart().addBuyable(buyable);
                     });

    std::shared_ptr<Price> price = buyable->getPrice();
    std::string priceText = std::to_string(price->getMainUnit()) + "."
                            + std::to_string(price->getSubUnit()) + " ZŁ";

    QLabel *priceLabel = new QLabel(QString::fromStdString(priceText));
    buttonLayout->addWidget(priceLabel);
    buttonLayout->addWidget(quantityLabel);

    QSpacerItem *vButtonSpacerBottom = new QSpacerItem(40,
                                                       20,
                                                       QSizePolicy::Minimum,
                                                       QSizePolicy::Expanding);
    buttonLayout->addItem(vButtonSpacerBottom);

    productLayout->addWidget(buttonPanel);

    buyableLayout->addWidget(productPanel);

    QFrame *sepLine = new QFrame();
    sepLine->setFrameShape(QFrame::HLine);
    sepLine->setFrameShadow(QFrame::Plain);
    sepLine->setLineWidth(1);
    buyableLayout->addWidget(sepLine);

    //layout->addWidget(buyablePanel);

    buyableWidgets->push_back(std::pair<std::shared_ptr<Buyable>, QWidget *>(buyable, buyablePanel));
}

BuyableScrollAreaMain::BuyableScrollAreaMain(QScrollArea *scrollArea)
    : BuyableScrollArea(scrollArea)
{}

BuyableScrollAreaMain::BuyableScrollAreaMain()
    : BuyableScrollArea()
{}
