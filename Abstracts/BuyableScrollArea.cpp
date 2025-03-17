#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "BuyableScrollArea.h"

void BuyableScrollArea::populate()
{
    QWidget *container = scrollArea->widget();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(container->layout());

    if (!layout) {
        layout = new QVBoxLayout(container);
        container->setLayout(layout);
    }

    clearArea();
    populateElements(layout);
}

void BuyableScrollArea::clearArea()
{
    QWidget *container = scrollArea->widget();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(container->layout());
    while (QLayoutItem *item = layout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
}

BuyableScrollArea::BuyableScrollArea(QScrollArea *scrollArea)
    : scrollArea(scrollArea)
{
    buyableLayout = std::make_shared<std::unordered_map<std::string, QVBoxLayout *>>();
};

BuyableScrollArea::BuyableScrollArea()
    : scrollArea(nullptr)
{
    buyableLayout = std::make_shared<std::unordered_map<std::string, QVBoxLayout *>>();
};
