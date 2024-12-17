#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "mainwindow.h"
#include "Headers/System/StoreSystem.h"
#include "Headers/Core/Product.h"
#include "Headers/CustomWidgets/BuyableScrollAreaMain.h"

void BuyableScrollAreaMain::Populate() {
    QWidget *container = scrollArea->widget();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(container->layout());
    StoreSystem& system = StoreSystem::GetInstance();
    Listing<std::shared_ptr<Buyable>> buyables = system.GetBuyables();
    qDebug() << buyables.GetSize();

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
        std::string imgPath = (PATH + buyable->GetImage()).c_str();
        QPixmap pixmap(imgPath.c_str());
        imageLabel->setPixmap(pixmap.scaled(200, 200));
        productLayout->addWidget(imageLabel);

        QWidget *infoPanel = new QWidget();
        QVBoxLayout *infoLayout = new QVBoxLayout(infoPanel);

        QLabel *nameLabel = new QLabel(QString::fromStdString(buyable->GetName()));
        QFont nameFont = nameLabel->font();
        nameFont.setPointSize(12);
        nameFont.setBold(true);
        nameLabel->setFont(nameFont);
        infoLayout->addWidget(nameLabel);

        QLabel *descriptionLabel = new QLabel(QString::fromStdString(buyable->GetDescription()));
        descriptionLabel->setWordWrap(true);
        infoLayout->addWidget(descriptionLabel);

        productLayout->addWidget(infoPanel);

        QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding);
        productLayout->addItem(horizontalSpacer);

        QPushButton *addToCartButton = new QPushButton("Add to Cart");
        productLayout->addWidget(addToCartButton);
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
    : BuyableScrollArea(scrollArea) {}
