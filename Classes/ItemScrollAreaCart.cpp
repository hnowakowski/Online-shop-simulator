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
#include "Classes/Product.h"
#include "ItemScrollAreaCart.h"
#include "StoreSystem.h"

void ItemScrollAreaCart::populateItems()
{
    StoreSystem &system = StoreSystem::getInstance();
    std::shared_ptr<std::vector<std::shared_ptr<CartItem>>> items = system.getCart().getItems();

    for (auto &item : *items) {
        if (!panelExists(item)) {
            generatePanel(item);
        }
    }
}

void ItemScrollAreaCart::displayItems()
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(scrollArea->widget()->layout());
    StoreSystem &system = StoreSystem::getInstance();
    for (const auto &[item, widget] : *itemWidgets) {
        widget->setVisible(true);
        layout->addWidget(widget);
    }
}

bool ItemScrollAreaCart::panelExists(const std::shared_ptr<CartItem> &item) const
{
    for (const auto &[i, w] : *itemWidgets) {
        if (item == i) {
            return true;
        }
    }
    return false;
}

void ItemScrollAreaCart::generatePanel(std::shared_ptr<CartItem> &item)
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(scrollArea->widget()->layout());

    QWidget *buyablePanel = new QWidget();
    QVBoxLayout *buyableLayout = new QVBoxLayout(buyablePanel);

    QWidget *productPanel = new QWidget();
    QHBoxLayout *productLayout = new QHBoxLayout(productPanel);

    QLabel *imageLabel = new QLabel();
    std::string imgPath = (PATH + item->getBuyable()->getImage()).c_str();
    QPixmap pixmap(imgPath.c_str());
    imageLabel->setPixmap(pixmap.scaled(100, 100));
    productLayout->addWidget(imageLabel);

    QWidget *infoPanel = new QWidget();
    QVBoxLayout *infoLayout = new QVBoxLayout(infoPanel);

    QLabel *nameLabel = new QLabel(QString::fromStdString(item->getBuyable()->getName()));
    QFont nameFont = nameLabel->font();
    nameFont.setPointSize(14);
    nameFont.setBold(true);
    nameLabel->setFont(nameFont);
    infoLayout->addWidget(nameLabel);

    std::shared_ptr<Price> price = item->getBuyable()->getPrice();
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

    QObject::connect(removeFromCartButton, &QPushButton::clicked, [item, this]() {
        StoreSystem &system = StoreSystem::getInstance();
        //qDebug() << "Removing " << currentBuyable->getName() << " from cart.";
        std::shared_ptr<Buyable> buyable = item->getBuyable();
        if (std::shared_ptr<Product> product = std::dynamic_pointer_cast<Product>(buyable)) {
            product->setQuantity(product->getQuantity() + 1);
        }

        //qDebug() << "BEFORE REMOVE: " << buyableWidgets->at(0).first->getName();

        for (int32_t i = itemWidgets->size() - 1; i >= 0; i--) {
            //qDebug() << i;
            if (itemWidgets->at(i).first->getId() == item->getId()) {
                itemWidgets->at(i).second->deleteLater();
                itemWidgets->erase(itemWidgets->begin() + i);
                qDebug() << "REMOVED BUYABLE WIDGET AT " << i;
                break;
            }
        }

        system.getCart().removeBuyable(buyable);

        qDebug() << system.getCart().size() << itemWidgets->size();
        displayItems();
    });
    buyableLayout->addWidget(productPanel);

    QFrame *sepLine = new QFrame();
    sepLine->setFrameShape(QFrame::HLine);
    sepLine->setFrameShadow(QFrame::Plain);
    sepLine->setLineWidth(1);

    buyableLayout->addWidget(sepLine);

    layout->addWidget(buyablePanel);
    itemWidgets->push_back(std::pair<std::shared_ptr<CartItem>, QWidget *>(item, buyablePanel));
}

void ItemScrollAreaCart::clearArea()
{
    QWidget *container = scrollArea->widget();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(container->layout());
    StoreSystem &system = StoreSystem::getInstance();
    for (int32_t i = itemWidgets->size() - 1; i >= 0; i--) {
        itemWidgets->at(i).second->setVisible(false);
        layout->removeWidget(itemWidgets->at(i).second);
        if (!system.getCart().hasItemId(itemWidgets->at(i).first->getId())) {
            itemWidgets->at(i).second->deleteLater();
            itemWidgets->erase(itemWidgets->begin() + i);
            qDebug() << "ANNIHILATED BUYABLE WIDGET AT " << i;
        }
    }
}

ItemScrollAreaCart::ItemScrollAreaCart(QScrollArea *scrollArea)
    : ItemScrollArea(scrollArea)
{
    itemWidgets = std::make_shared<std::vector<std::pair<std::shared_ptr<CartItem>, QWidget *>>>();
}

ItemScrollAreaCart::ItemScrollAreaCart()
    : ItemScrollArea()
{
    itemWidgets = std::make_shared<std::vector<std::pair<std::shared_ptr<CartItem>, QWidget *>>>();
}
