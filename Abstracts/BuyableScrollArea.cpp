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
    populateBuyables(layout);
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
    buyableWidgets = std::make_shared<std::vector<std::pair<std::shared_ptr<Buyable>, QWidget *>>>();
};

BuyableScrollArea::BuyableScrollArea()
    : scrollArea(nullptr)
{
    buyableWidgets = std::make_shared<std::vector<std::pair<std::shared_ptr<Buyable>, QWidget *>>>();
};
