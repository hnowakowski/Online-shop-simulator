#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include <memory>
#include <string>

#include "Clothing.h"
#include "ItemScrollAreaMain.h"
#include "Service.h"
#include "StoreSystem.h"

void ItemScrollAreaMain::populateItems()
{
    StoreSystem &system = StoreSystem::getInstance();
    std::shared_ptr<std::vector<std::shared_ptr<Buyable>>> buyables = system.getBuyables();
    if (buyables->empty()) {
        qDebug() << "WARNING! - No buyables in storesystem to display!\n";
    }

    for (auto &buyable : *buyables) {
        generatePanel(buyable);
    }
}

void ItemScrollAreaMain::displayItems()
{
    StoreSystem &system = StoreSystem::getInstance();
    BuyableDisplayedType displayedType = system.getBuyableDisplayedType();
    std::string query = system.getBuyableSearchQuery();
    BuyableSortedBy sortedBy = system.getBuyableSortedBy();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(scrollArea->widget()->layout());

    switch (sortedBy) {
    case BuyableSortedBy::NAME:
        std::sort(itemWidgets->begin(), itemWidgets->end(), [](const auto &a, const auto &b) { return a.first->getName() < b.first->getName(); });
        break;
    case BuyableSortedBy::PRICE:
        std::sort(itemWidgets->begin(), itemWidgets->end(), [](const auto &a, const auto &b) { return *(a.first->getPrice()) < *(b.first->getPrice()); });
        break;
    case BuyableSortedBy::RATING:
        std::sort(itemWidgets->begin(), itemWidgets->end(),
                  [](const auto &a, const auto &b) { return std::stof(a.first->getRating()) > std::stof(b.first->getRating()); });
        break;
    }

    // filtering
    for (const auto &[buyable, widget] : *itemWidgets) {
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
        if (std::shared_ptr<Product> product = std::dynamic_pointer_cast<Product>(buyable)) {
            if (QLabel *quantityLabel = widget->findChild<QLabel *>("quantityLabel", Qt::FindChildrenRecursively)) {
                uint32_t quantity = product->getQuantity();
                std::string quantityText = "In stock: " + std::to_string(quantity);
                quantityLabel->setText(QString::fromStdString(quantityText));
            }
        }

        widget->setVisible(true);
        layout->addWidget(widget);
    }
}

void ItemScrollAreaMain::generatePanel(std::shared_ptr<Buyable> &item)
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(scrollArea->widget()->layout());

    QWidget *buyablePanel = new QWidget();
    QVBoxLayout *buyableLayout = new QVBoxLayout(buyablePanel);

    QWidget *productPanel = new QWidget();
    QHBoxLayout *productLayout = new QHBoxLayout(productPanel);

    QLabel *imageLabel = new QLabel();
    std::string imgPath = (PATH + item->getImage()).c_str();
    QPixmap pixmap(imgPath.c_str());
    imageLabel->setPixmap(pixmap.scaled(200, 200));
    productLayout->addWidget(imageLabel);

    QWidget *infoPanel = new QWidget();
    QVBoxLayout *infoLayout = new QVBoxLayout(infoPanel);

    QLabel *nameLabel = new QLabel(QString::fromStdString(item->getName()));
    QFont nameFont = nameLabel->font();
    nameFont.setPointSize(14);
    nameFont.setBold(true);
    nameLabel->setFont(nameFont);
    infoLayout->addWidget(nameLabel);
    nameLabel->setObjectName("nameLabel");

    QLabel *ratingLabel = new QLabel(QString::fromStdString(item->getRating() + "/10"));
    infoLayout->addWidget(ratingLabel);

    QLabel *descriptionLabel = new QLabel(QString::fromStdString(item->getDescription()));
    infoLayout->addWidget(descriptionLabel);

    productLayout->addWidget(infoPanel);

    QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding);
    productLayout->addItem(horizontalSpacer);

    QWidget *buttonPanel = new QWidget();
    QVBoxLayout *buttonLayout = new QVBoxLayout(buttonPanel);

    QSpacerItem *vButtonSpacerTop = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    buttonLayout->addItem(vButtonSpacerTop);

    QPushButton *addToCartButton = new QPushButton("Add to Cart");
    buttonLayout->addWidget(addToCartButton);

    QLabel *quantityLabel = new QLabel("");
    quantityLabel->setObjectName("quantityLabel");

    QObject::connect(addToCartButton, &QPushButton::clicked, [item, quantityLabel, addToCartButton]() {
        StoreSystem &system = StoreSystem::getInstance();

        if (std::shared_ptr<Product> product = std::dynamic_pointer_cast<Product>(item)) {
            product->setQuantity(product->getQuantity() - 1);

            quantityLabel->setText(QString::fromStdString("In stock: " + std::to_string(product->getQuantity())));

            if (product->getQuantity() == 0) {
                addToCartButton->setDisabled(true);
            }
        }
        system.getCart().addBuyable(item);
        std::shared_ptr<Price> pr = system.getCart().getTotalPrice();
        qDebug() << pr->getMainUnit() << "." << pr->getSubUnit();
    });

    std::shared_ptr<Price> price = item->getPrice();
    std::string priceText = std::to_string(price->getMainUnit()) + "." + std::to_string(price->getSubUnit()) + " ZŁ";

    QLabel *priceLabel = new QLabel(QString::fromStdString(priceText));
    buttonLayout->addWidget(priceLabel);
    buttonLayout->addWidget(quantityLabel);

    QSpacerItem *vButtonSpacerBottom = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    buttonLayout->addItem(vButtonSpacerBottom);

    productLayout->addWidget(buttonPanel);

    buyableLayout->addWidget(productPanel);

    QFrame *sepLine = new QFrame();
    sepLine->setFrameShape(QFrame::HLine);
    sepLine->setFrameShadow(QFrame::Plain);
    sepLine->setLineWidth(1);
    buyableLayout->addWidget(sepLine);

    layout->addWidget(buyablePanel);

    itemWidgets->push_back(std::pair<std::shared_ptr<Buyable>, QWidget *>(item, buyablePanel));
}

ItemScrollAreaMain::ItemScrollAreaMain(QScrollArea *scrollArea)
    : ItemScrollArea(scrollArea)
{}

ItemScrollAreaMain::ItemScrollAreaMain()
    : ItemScrollArea()
{}
