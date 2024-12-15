#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include "BuyableScrollArea.h"

BuyableScrollArea::BuyableScrollArea(QScrollArea *scrollArea, std::vector<std::shared_ptr<Product>> products) : products(products), scrollArea(scrollArea) {};

