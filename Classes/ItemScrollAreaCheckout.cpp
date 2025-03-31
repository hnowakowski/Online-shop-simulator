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
#include "ItemScrollAreaCheckout.h"
#include "StoreSystem.h"

void ItemScrollAreaCheckout::populateItems()
{
    StoreSystem &system = StoreSystem::getInstance();
    std::shared_ptr<std::vector<std::shared_ptr<CartItem>>> items = system.getCart().getItems();

    for (auto &item : *items) {
        if (!panelExists(item)) {
            generatePanel(item);
        }
    }
}

void ItemScrollAreaCheckout::displayItems()
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(scrollArea->widget()->layout());
    for (const auto &[item, widget] : *itemWidgets) {
        widget->setVisible(true);
        layout->addWidget(widget);
    }
}

bool ItemScrollAreaCheckout::panelExists(const std::shared_ptr<CartItem> &item) const
{
    for (const auto &[i, w] : *itemWidgets) {
        if (item == i) {
            return true;
        }
    }
    return false;
}

void ItemScrollAreaCheckout::generatePanel(std::shared_ptr<CartItem> &item)
{
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

    buyableLayout->addWidget(productPanel);

    QFrame *sepLine = new QFrame();
    sepLine->setFrameShape(QFrame::HLine);
    sepLine->setFrameShadow(QFrame::Plain);
    sepLine->setLineWidth(1);
    buyableLayout->addWidget(sepLine);
    itemWidgets->push_back(std::pair<std::shared_ptr<CartItem>, QWidget *>(item, buyablePanel));
}

void ItemScrollAreaCheckout::clearArea()
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

ItemScrollAreaCheckout::ItemScrollAreaCheckout(QScrollArea *scrollArea)
    : ItemScrollArea(scrollArea)
{}

ItemScrollAreaCheckout::ItemScrollAreaCheckout()
    : ItemScrollArea()
{}
