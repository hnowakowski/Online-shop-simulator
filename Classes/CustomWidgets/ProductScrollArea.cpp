#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "Headers/Core/Product.h"
#include "Headers/CustomWidgets/ProductScrollArea.h"

void ProductScrollArea::Populate() {
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

    for (auto &product : products) {
        QWidget *productPanel = new QWidget();
        QVBoxLayout *panelLayout = new QVBoxLayout(productPanel);

        QLabel *imageLabel = new QLabel();
        QPixmap pixmap(product->GetImage().c_str());
        imageLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
        panelLayout->addWidget(imageLabel);

        QLabel *nameLabel = new QLabel(QString::fromStdString(product->GetName()));
        panelLayout->addWidget(nameLabel);

        QLabel *descriptionLabel = new QLabel(QString::fromStdString(product->GetDescription()));
        descriptionLabel->setWordWrap(true);
        panelLayout->addWidget(descriptionLabel);

        layout->addWidget(productPanel);
    }

    scrollArea->widget()->adjustSize();
}

ProductScrollArea::ProductScrollArea(QScrollArea *scrollArea, std::vector<std::shared_ptr<Product>> products) : products(products), scrollArea(scrollArea) {};

