#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "mainwindow.h"
#include "Headers/Core/Product.h"
#include "Headers/CustomWidgets/BuyableScrollAreaMain.h"

void BuyableScrollAreaMain::Populate() {
    QWidget *container = scrollArea->widget();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(container->layout());

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
        QHBoxLayout *panelLayout = new QHBoxLayout(productPanel);

        QLabel *imageLabel = new QLabel();
        std::string imgPath = (PATH + buyable->GetImage()).c_str();
        qDebug()<<imgPath<<"\n";
        QPixmap pixmap(imgPath.c_str());
        imageLabel->setPixmap(pixmap.scaled(200, 200));
        panelLayout->addWidget(imageLabel);

        QLabel *nameLabel = new QLabel(QString::fromStdString(buyable->GetName()));
        QFont nameFont = nameLabel->font();
        nameFont.setPointSize(12);
        nameFont.setBold(true);
        nameLabel->setFont(nameFont);
        panelLayout->addWidget(nameLabel);

        QLabel *descriptionLabel = new QLabel(QString::fromStdString(buyable->GetDescription()));
        descriptionLabel->setWordWrap(true);
        panelLayout->addWidget(descriptionLabel);

        layout->addWidget(productPanel);

        QPushButton *addToCartButton = new QPushButton("Add to Cart");
        panelLayout->addWidget(addToCartButton);

        layout->addWidget(productPanel);
    }

    scrollArea->widget()->adjustSize();
}

BuyableScrollAreaMain::BuyableScrollAreaMain(QScrollArea *scrollArea, std::vector<std::shared_ptr<Buyable>> buyables)
    : BuyableScrollArea(scrollArea, buyables) {}
