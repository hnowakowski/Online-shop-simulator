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
    Listing<std::shared_ptr<Buyable>> buyables;
    if(!system.GetBuyables(buyables)){
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

        QLabel *ratingLabel = new QLabel(QString::fromStdString(buyable->GetRating() + "/10"));
        ratingLabel->setWordWrap(true);
        infoLayout->addWidget(ratingLabel);

        QLabel *descriptionLabel = new QLabel(QString::fromStdString(buyable->GetDescription()));
        descriptionLabel->setWordWrap(true);
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

        uint32_t mainunit;
        uint32_t subunit;
        buyable->GetPrice(mainunit, subunit);
        std::string priceText = std::to_string(mainunit) + "." + std::to_string(subunit)+" ZŁ";

        QLabel *priceLabel = new QLabel(QString::fromStdString(priceText));
        priceLabel->setWordWrap(true);
        buttonLayout->addWidget(priceLabel);

        QSpacerItem *vButtonSpacerBottom = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
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
    : BuyableScrollArea(scrollArea) {}
